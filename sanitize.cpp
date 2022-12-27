/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/

#include "sanitize.hpp"




Sanitize::Sanitize(string message) : message(message) {

} // constructeur

string Sanitize::sanitize(){  
    string final;
    locale loc ;
    int message_size = message.length()+1;
    for (int i = 0; i < message_size; i++) // on effectue un parcours sur le message de façon à ce que 
                                            // on récupère uniquement les espaces ou les lettres
                                            // si les lettres sont en minuscules ils sont transformés en 
                                            // en majuscule
        if (isalpha(message[i],loc))
            {
        final += toupper(message[i]);
        }

        else if (message[i] == ' '){
            final += ' ';
        }
        
    return final;
};
