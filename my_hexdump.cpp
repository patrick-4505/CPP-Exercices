#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

/*
   Algorithme :
    1. ouvrir le fichier en mode binaire.
    2. lire le fichier par blocs de 16 octets.
    3. pour chaque bloc lu :
        a. afficher l'adresse de départ du bloc (en hexadécimal).
        b. afficher les octets du bloc en hexadécimal, séparés par des espaces.
        c. afficher les caractères correspondants aux octets, en remplaçant les caractères non imprimables par un point ('.').
    4. répéter les étapes 2 et 3 jusqu'à la fin du fichier. 
*/


int main(int argc, char* argv[]) {

    std::ifstream file(argv[1], std::ios::binary);

    unsigned char buffer[16];   // buffer de 16 octets, unsigned pour éviter les valeurs négatives

    int address = 0; // c'est le compteur qui sert d'offeset

    while (true) {
        file.read((char*)buffer, 16);
        int n = file.gcount();
        if (n == 0) break;

        std::cout << std::hex << std::setw(8) << std::setfill('0') << address << "  "; // ligne qui affiche l'offeset en hexadécimal, sur 8 chiffres, avec des zéros devant

        for (int i = 0; i < 16; i++) {  // affiche chaque octet en hex sur 2 chiffres (ex: 4f 2a ...)
            if (i < n)
                std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)buffer[i] << " ";
            else
                std::cout << "   ";   // padding si le dernier bloc fait moins de 16 octets

        }

        std::cout << " |";

        for (int i = 0; i < n; i++) {  // pour la partie ascii, on affiche le caractère si imprimable, sinon un point
            if (std::isprint(buffer[i]))
                std::cout << buffer[i];
            else
                std::cout << '.';
        }

        std::cout << "|\n";
        address += n;   // avance l'adresse du nombre d'octets lu

    }
    std::cout << std::hex << std::setw(8) << std::setfill('0') << address << "\n";  // affiche l'adressse finale = taille totale du fichier

    return 0;
}