/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/


#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Send_auxiliary
{
public:
    Send_auxiliary(string filename, string message);
    ~Send_auxiliary() = default;
    void send();
private:
    string filename;
    string message;
};

