// Supporte les flags : -t (tcp), -u (udp), -x (unix), -l (listen only)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string hexToAddr(const string& hex)
{
    string ipHex   = hex.substr(0, 8);
    string portHex = hex.substr(9, 4);

    unsigned long ipInt;
    istringstream(ipHex) >> std::hex >> ipInt;

    unsigned char a = (ipInt)       & 0xFF;
    unsigned char b = (ipInt >> 8)  & 0xFF;
    unsigned char c = (ipInt >> 16) & 0xFF;
    unsigned char d = (ipInt >> 24) & 0xFF;

    unsigned int port;
    istringstream(portHex) >> std::hex >> port;

    string ip = to_string(a) + "." + to_string(b) + "." +
                to_string(c) + "." + to_string(d);

    if (ip == "0.0.0.0")
        return "0.0.0.0:" + (port == 0 ? string("*") : to_string(port));

    return ip + ":" + to_string(port);
}

string stateToStr(const string& stateHex)
{
    int state;
    istringstream(stateHex) >> std::hex >> state;

    switch (state) {
        case 1:  return "ESTABLISHED";
        case 2:  return "SYN_SENT";
        case 3:  return "SYN_RECV";
        case 4:  return "FIN_WAIT1";
        case 5:  return "FIN_WAIT2";
        case 6:  return "TIME_WAIT";
        case 7:  return "CLOSE";
        case 8:  return "CLOSE_WAIT";
        case 9:  return "LAST_ACK";
        case 10: return "LISTEN";
        case 11: return "CLOSING";
        default: return "UNKNOWN";
    }
}

// listenOnly = true => affiche seulement les lignes en état LISTEN
void parseAndPrint(const string& filename, const string& proto, bool listenOnly)
{
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Impossible d'ouvrir " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);

        string slot, localAddr, remoteAddr, state;
        iss >> slot >> localAddr >> remoteAddr >> state;

        string stateStr = stateToStr(state);

        // Si -l est actif, on n'affiche que les LISTEN
        if (listenOnly && stateStr != "LISTEN")
            continue;

        cout << left
             << setw(6)  << proto
             << setw(26) << hexToAddr(localAddr)
             << setw(26) << hexToAddr(remoteAddr)
             << stateStr << "\n";
    }
}

// Lit et affiche les sockets Unix depuis /proc/net/unix
void parseUnix(bool listenOnly)
{
    ifstream file("/proc/net/unix");

    if (!file.is_open()) {
        cerr << "Impossible d'ouvrir /proc/net/unix" << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);

        string addr, refs, localNum, proto, flags, type, state, inode, path;
        iss >> addr >> refs >> localNum >> proto >> flags >> type >> state >> inode;
        getline(iss, path); // Le chemin peut contenir des espaces

        // Supprime l'espace de début du path
        if (!path.empty() && path[0] == ' ')
            path = path.substr(1);
        if (path.empty())
            path = "*";

        // state "01" = LISTEN, "03" = CONNECTED
        int stateInt;
        istringstream(state) >> std::hex >> stateInt;
        string stateStr;
        switch (stateInt) {
            case 1:  stateStr = "LISTEN";      break;
            case 2:  stateStr = "UNCONNECTED"; break;
            case 3:  stateStr = "CONNECTED";   break;
            default: stateStr = "UNKNOWN";     break;
        }   

        if (listenOnly && stateStr != "LISTEN")
            continue;

        cout << left
             << setw(6)  << "unix"
             << setw(26) << path
             << setw(26) << "*"
             << stateStr << "\n";
    }
}

// Affiche l'aide
void printUsage(const string& progName)
{
    cerr << "Usage: " << progName << " [-t] [-u] [-x] [-l]\n"
         << "  -t  affiche les sockets TCP\n"
         << "  -u  affiche les sockets UDP\n"
         << "  -x  affiche les sockets Unix\n"
         << "  -l  affiche uniquement les sockets en écoute (LISTEN)\n";
}

int main(int argc, char* argv[])
{
    bool showTcp    = false;
    bool showUdp    = false;
    bool showUnix   = false;
    bool listenOnly = false;

    // Parse des arguments
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        for (char c : arg) {
            if      (c == 't') showTcp    = true;
            else if (c == 'u') showUdp    = true;
            else if (c == 'x') showUnix   = true;
            else if (c == 'l') listenOnly = true;
            else if (c == '-') continue; // ignore le tiret
            else {
                cerr << "Flag inconnu : " << c << "\n";
                printUsage(argv[0]);
                return 1;
            }
        }
    }

    // Si aucun flag de proto n'est donné, on affiche tout
    if (!showTcp && !showUdp && !showUnix)
        showTcp = showUdp = showUnix = true;

    // En-tête
    cout << left
         << setw(6)  << "Proto"
         << setw(26) << "Local Address:Port"
         << setw(26) << "Peer Address:Port"
         << "State" << "\n";
    cout << string(70, '-') << "\n";

    if (showTcp)  parseAndPrint("/proc/net/tcp",  "tcp",  listenOnly);
    if (showUdp)  parseAndPrint("/proc/net/udp",  "udp",  listenOnly);
    if (showUnix) parseUnix(listenOnly);

    return 0;
}