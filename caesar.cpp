/*
Nom : Secundar
Prénom : Ismael
Matricule : 504107

Projet LDP
*/

#include "caesar.hpp"

Caesar::Caesar(bool decalage, int nombre_decalage) : decalage(decalage), nombre_decalage(nombre_decalage){
}
//Classe Cesar


string Caesar::caesar(string message){
    
    
    int message_size = message.size();      // on initialise la taille du message dans une variable
    int size_alphabet = 26;  //on initialise la taille de l'alphabet dans une variable pour éviter les valeurs magiques
    int valeur_A = int('A'); //on initialise le début de l'alphabet dans une variable pour éviter les valeurs magiques
    int valeur_Z = int('Z'); 
    string message_final;    // on déclare un message final dans lequel sera mis le message final
    if(decalage){ // Si le décalage se fait vers la droite
    nombre_decalage =  nombre_decalage*(-1);    // alors on change le signe du nombre de décalage.
    }
    for(int i = 0; i < message_size; i++){
    
    if ( message[i] == ' '){    // si c'est un espace on ajoute un espace
        message_final[i] = ' ';
    }
    
    else{
            int message_temp = message[i] + nombre_decalage;   // On ajoute le décalage à la valeur du caractère.
            while(! (message_temp >= valeur_A && message_temp <= valeur_Z)){ // tant que ce n'est pas entre A ou Z
                if(message_temp < valeur_A){     // si c'est inférieur à A on va ajouter encore 26
                    message_temp += size_alphabet;
                }
                else if(message_temp > valeur_Z){   
                    message_temp -= size_alphabet;
                }
            }
            char message_temp_final = message_temp;
            message_final += message_temp_final; // on concatène
        }
    }
    
    
    return message_final;
}