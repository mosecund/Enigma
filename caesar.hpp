/*
Nom : Secundar
Prénom : Ismael
Matricule : 504107

Projet LDP
*/

#include <string>
#include <iostream>
using namespace std;

class Caesar{
    /*
    On défini juste la classe césar et on mets dans le private, 
    le décalage et le nombre de décalage
    */
    public:
    Caesar(bool decalage, int nombre_decalage);
    string caesar(string message);

    private:
    bool decalage;
    int nombre_decalage;
};