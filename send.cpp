/*
Nom : Secundar
Prénom : Ismael
Matricule : 504107

Projet LDP
*/
#include "enigma.hpp"
#include "caesar.hpp"
#include "sanitize.hpp"
#include "send_auxiliary.hpp"


using namespace std;

    
int main(int argc, char *argv[]) {

    if (argc < 3) {
        std::cout << "Utilisation: ./send G|D décalage fichier ou python enigma /tmp/f105" << endl;
        return 1;
    }
    if (strcmp(argv[1], "G") != 0 && strcmp(argv[1], "D")!=0 && strcmp(argv[1], "enigma") != 0){
        std::cout << "Le premier argument doit être G ou D, " << argv[1] << " est incorrect." << endl;
        return 1;
    }
    
    bool flag = false;

    if (argc == 4){
        
        bool rightShift = strcmp(argv[1], "D") == 0;
        int shift = atoi(argv[2]);

        string message;
        string message_cesar;
        string filename = argv[3];
        std::cout << "Communication chiffrée avec César " << argv[1] <<  " " << shift <<" via " << filename << endl;

        while(!flag){
            try{
            cout << "Votre message :";
            
            getline(cin,message);
            if (message == ""){ // Si le message est vide, on souleve une erreur
                throw 20;
            }
        message_cesar = message;
        Caesar caesar_obj(rightShift,shift);
        Sanitize sanitize_obj(message_cesar);
        message_cesar = caesar_obj.caesar(sanitize_obj.sanitize());
        Send_auxiliary send_auxiliary_obj(filename,message_cesar);
        send_auxiliary_obj.send();
            }
            catch(int x){   // On catch l'erreur renvoyé pour arrêter la boucle
                flag = true;
            }
        }    
    }

    else if (argc == 3){
                
        string filename = argv[2];
        string message;
        std::cout << "Communication chiffrée avec Enigma " << argv[1] << filename << endl;
        
        while (!flag){
                try{
        
        cout << "Votre message :";
        
        getline(cin,message);
        
        if (message == ""){ // Si le message est vide, on souleve une erreur
                throw 20;
            }
        

        std::cout << message << endl;
        string message_enigma;
        string conversion_en_string;
        int index;
        int message_size = message.length();
        Sanitize sanitize_obj(message);
        message = sanitize_obj.sanitize();

        for (index = 0; index < message_size; index++)
        {   
            char* message_code;
            string conversion_en_string(1,message[index]);
            message_code = strdup(conversion_en_string.c_str());        // conversion en string
            string message_final = enigma(message_code);
            message_enigma += message_final; 
        }
        Send_auxiliary send_auxiliary_obj(filename, message_enigma);
        send_auxiliary_obj.send();
                }
            
        catch(int x){
            flag = true;
        }
        
        
        }
           
            
    }
        
    return 0; 
};