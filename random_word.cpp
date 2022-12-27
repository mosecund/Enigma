/*
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP

*/


// code qui permettait de générer des mots aléatoire selon une taille donnée

#include <iostream>
#include <fstream>
#include <cstdlib>



using namespace std;

static const char pool[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int poolSize = sizeof(pool) - 1;

char getRandomChar(){
  return pool[rand() % poolSize];
}

string* randomword(int passLenght, int numberOfPasswords)
{
  string pass;
  string final;
    
    for (int i = 0; i < numberOfPasswords; i++)
    {
      for (int j = 0; j < passLenght; j++)
      {
        if(j==0){
          pass += '"';
        }

        
        pass += getRandomChar();
        if(j==passLenght-1){
          pass += '"';
        }
      }
      
      final += pass;
      
      pass = ",";
    
    }
  cout << final<< endl;
  
  }

int main(int args, char *argv[])
{
  randomword(100,100);
}