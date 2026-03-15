#include <iostream>
#include <fstream>


/*
  Algorithme :

    1. ouvrir le fichier en mode lecture
    2. parcourir le fichiers et voir octets par octets s'ils sont printable
    3. si c'est le cas on ajoute le caractère dans la variable temporaire
    4. si c'est pas le cas et que temp est inférieur à 4 : on vide la variable temporaire sans l'afficher
    5. s'il y a minimum 4 caractères consécutifs stocké dans temp: on affiche et on vide la variable temporaire
    6. une fois sortie de la boucle on affiche temp si il contient au moins 4 caractères


*/ 


int main(int argc, char* argv[]) {

    std::ifstream file(argv[1], std::ios::binary); // std::ios::binary, pour ouvrir le fichier en mode binaire
    std::string temp;
    char octet;

    while (file.get(octet)){ // pour lire le fichier octet par octet
       if (std::isprint(octet)){ // check si l'octet est un caractère imprimable
        // stocké le caractère dans une variable temporaire
        temp += octet;
       }
       else if (temp.length() < 4){
        // vider temp
        temp = "";
       }

       else{
        // affche temp + vider temp
        std::cout << temp << std::endl;
        temp = "";
       }

    }

    if (temp.length() >= 4) { // une fois sortie de la boucle on affiche temp si il contient au moins 4 caractères
    std::cout << temp << std::endl;
   }


    return 0;
}

