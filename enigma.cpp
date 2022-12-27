/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/

#include "enigma.hpp"

Enigma::Enigma(string Rotor1,string Rotor2, string Rotor3, string bytes){

    Rotor[0] = Rotor1;
    Rotor[1] = Rotor2;
    Rotor[2] = Rotor3;
    Reflector = bytes;

};
string Enigma::getRotor(int i) {
    // renvoie le Rotor demandé
    return Enigma::Rotor[i];
};

string Enigma::getReflector() {
        // renvoie le réflécteur

    return Enigma::Reflector;
};

int Enigma::getSizeRotor(){
    // renvoie le nombre de rotor

    return Enigma::Rotor->length();
};

int Enigma::getSizeReflector(){
    return Enigma::Reflector.size();
};

extern "C" char* enigma(char* message){

    string rotor1_liste = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    string rotor2_liste = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    string rotor3_liste = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    string reflecteur_liste = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string message_code;
    // on stock le message codé dans cette variable
    string message_string = message;
    // on converti en string
    int len_message = strlen(message);
    // on prend la taille de ce string pour borner notre boucle for


    Enigma enigma_obj(rotor1_liste,rotor2_liste,rotor3_liste,reflecteur_liste);
    // Enigma prend les 3 rotors en parametre et ensuite le reflecteur
    

    for ( int index = 0; index < len_message; index++)
    {
        if(isspace(message_string[index])){
            message_code += message_string[index];
        }
        // dans le cas où il y a un espace on ajoute juste l'espace dans le message codé
        else if(isalpha(message_string[index])){
        // sinon on le fait passer dans les rotors puis sur le reflecteur et ensuite de nouveau par les rotors
            int index_of_current_char = alphabet.find(message_string[index]);       // on trouve l'index du caractère courant dans l'alphabet
            char rotor_3 = enigma_obj.getRotor(2)[index_of_current_char];           // on fait le rotor aller
            index_of_current_char = alphabet.find(rotor_3);                         // on recherche dans l'alphabet 
            char rotor_2 = enigma_obj.getRotor(1)[index_of_current_char];
            index_of_current_char = alphabet.find(rotor_2);
            char rotor_1 = enigma_obj.getRotor(0)[index_of_current_char];
            index_of_current_char = alphabet.find(rotor_1);
            char bytes = enigma_obj.getReflector()[index_of_current_char]; // on projette avec le reflecteur
            
            index_of_current_char = enigma_obj.getRotor(0).find(bytes);      // on fait le rotor retour
            rotor_1 = alphabet[index_of_current_char];

            index_of_current_char = enigma_obj.getRotor(1).find(rotor_1);                 
            rotor_2 = alphabet[index_of_current_char];

            index_of_current_char = enigma_obj.getRotor(2).find(rotor_2);                 
            rotor_3 = alphabet[index_of_current_char];

            message_code += rotor_3;                // on concatene 

        }
    }
    
    return &message_code[0];
};

