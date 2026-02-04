#orhestrator 
import os 
from wrap import wrapper 

def main() :
    print("on demare")
    w = wrapper()
    print("en attente de l'input")

    while(True ) : 
        try : 
            inpu = input("analyser > ")
            if inpu.lower()=="q":  
                print("l'utilisateur a mis q ainsi le prgramme se ferme ")
                break
            if not inpu.strip() :
                continue #on passe 
            resultat = w.check_url(inpu) 
            if resultat =="DANGER" : 
                print(f"cette url n'est pas sure {inpu}")
            elif resultat == "SAFE":
                print("rien a signaler ")
                #PARTIE 2  A FAIRE RANCHER A UN LLM POUR VERIFIER ET VOIR SI LE CONTENU A PLUTOT MANIPULATIF SI IL Y A DES MOTS CLE COMME VIREMENT INFO PERSONNELLES ....
                #ou definir un dictionnaire de mots clé et detecter si inpu est present dans ce dictionnaire boucle for i in dictionnaire 
            else : 
                print(f"resultat innatendu {resultat}")

        except Exception as e : 
            print(f"Erreur de type {e}")

    print("fermeture et netoyage du systeme ")
    w.close()

if __name__ == "__main__" : 
    main() 