/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Partie 2 projet LDP

*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>

using namespace std;

#ifndef ENIGMA_HPP
#define ENIGMA_HPP

extern "C" char* enigma(char* message);

class Enigma{
    public:

    Enigma(string Rotor1,string Rotor2,string Rotor3,string Reflector);
    string getRotor(int i) ;
    string getReflector() ;
    int getSizeRotor() ;
    int getSizeReflector() ;

    private:

    string Rotor[3];
    string Reflector;
};


#endif
