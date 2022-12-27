/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <locale> 
#include <string>

using namespace std;

class Sanitize{
    private:
        string message;
    public:
        Sanitize(string message);
        string sanitize();

};