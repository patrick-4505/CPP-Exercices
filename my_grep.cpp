#include <iostream>
#include <fstream>
#include <regex>
#include <string>
/*
   Algorithme :
    1. ouvrir le fichier.
    2. lire le fichier ligne par ligne.
    3. pour chaque ligne :
        a. vérifier si la ligne contient le pattern.
        b. si oui, afficher la ligne.
    4. répéter les étapes 2 et 3 jusqu'à la fin du fichier.
*/

int main(int argc, char* argv[]) {

    std::string pattern_str = argv[1];
    std::string filename = argv[2];

    std::ifstream file(filename);
    std::regex pattern(pattern_str);

    std::string line;
    bool match = false;

    while (std::getline(file, line)) {
        match = std::regex_search(line, pattern);  // vérifie si la ligne contient le pattern

        if (match)
            std::cout << line << "\n"; //affiche la ligne si elle correspond au pattern
    }

    return 0;
}