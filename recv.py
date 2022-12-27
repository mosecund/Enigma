"""
Nom: Secundar
Prénom : Ismael
Matricule: 504107

Projet LDP
"""


import sys, time
from ctypes import CDLL, c_char_p

class Recv:
    """
    Classe qui gère l'affichage sur le terminal
    """
    def __init__(self,filename,decalage,nombre_de_decalage,enigma):
        """
        le fillename est directement donné par l'utilisateur,
        un booléen enigma permet de vérifier s'il sagit de césar ou enigma
        """
        self.decalage = decalage
        self.nombre_de_decalage = nombre_de_decalage
        self.enigma = enigma

        enigmalib = CDLL("./enigma.so")
        enigmalib.enigma.restype = c_char_p
        enigmalib.enigma.argstype = [c_char_p]
    
        with open(filename) as file:                                    # permet de lire ligne par ligne le fichier
            while True:
                line = file.readline()
                if not line:
                    time.sleep(1)
                else:
                    if enigma == False:

                        print(f"Nouveau message: {line} ->", self.uncaesar(line))
                        

                    elif enigma == True:
                        # s'il sagissait bien d'enigma
                        message = str.encode(line.strip())  # encode et nettoie le message
                        enigma_on_message = enigmalib.enigma(message).decode("utf-8")   # applique enigma
                        print(f"Nouveau message: {message} ->", enigma_on_message)
                        


                time.sleep(1)

    def uncaesar(self,message):
        """
        Fonction qui permet de décoder César
        """
        res = ""
        valeur_Z = ord('Z')
        valeur_A = ord('A')


        for i in message:
            if i == " ":        # s'il y a un espace, on ajoute juste l'espace
                res += i

            elif i.isalpha():
                alpha_len = 26  # s'il y a une lettre de l'alphabet
                current_letter = self.nombre_de_decalage + ord(i)
                while not (current_letter >= valeur_A and current_letter <= valeur_Z):
                    # tant que cette lettre n'est pas comprise entre A et Z
                    if current_letter < valeur_A:
                        current_letter += alpha_len
                    elif current_letter > valeur_Z:
                        current_letter -= alpha_len

                res += chr(current_letter)

        return res



def main():
    if len(sys.argv) < 3:
        print("Utilisation: python recv.py G|D decalage fichier.", file=sys.stderr)
        sys.exit(1)
    if sys.argv[1] not in ("G", "D", "enigma"):
        print(f"Le premier argument doit etre G / D ou enigma, {sys.argv[1]} est incorrect", file=sys.stderr)
        sys.exit(1)

    if len(sys.argv) == 4:

        right_shift: bool = sys.argv[1] == "D"
        shift: int = int(sys.argv[2])
        filename: str = sys.argv[3]
        Recv(filename,decalage=right_shift, nombre_de_decalage=shift,enigma=False)
        print(f"Communication chiffree avec Cesar {sys.argv[1]} {shift} via {filename}")

    elif len(sys.argv) == 3:
        filename: str = sys.argv[2]
        print(f"Communication chiffree avec Enigma {sys.argv[1]} via {filename}")
        Recv(filename,None,None,True)



if __name__ == "__main__":
    main()


