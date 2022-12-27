/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/


// Classe qui permet d'alleger le fichier send.cpp
#include "send_auxiliary.hpp"

Send_auxiliary::Send_auxiliary(string filename,string message) : filename(filename),message(message){};

void Send_auxiliary::send()  // permet d'afficher le message à envoyer en chiffré
{                                                               // mais aussi en déchiffré 
    
    ofstream file(filename, ios_base::app);
    if(file.is_open()) {
    file << message << endl;
    file.close();
    cout << "Envoie du message :" << message << endl;


}
else cerr << "Impossible d’ouvrir le fichier " << filename << endl;

};