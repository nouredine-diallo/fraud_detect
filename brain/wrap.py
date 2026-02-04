#va permettre l'interpretation de la partie precedente( c_core) pour le reste 
#on va utiliser subprocess pour gerer les process pere et fils et les communication 
#on a 2 tuyeaux ( entree et sortant ) stdout action read  et sdtin action write
import os #pour naviguer vers l'excutable sentinel 
import subprocess 
#permet de gerer les process 
class wrapper : 

    def __init__(self ) : 
        try :
            self.process = subprocess.Popen(
                ["../c_core/sentinel"],
                stdin = subprocess.PIPE , 
                stdout = subprocess.PIPE , 
                text = True ,
                bufsize = 1 #ligne par ligne 
            )
        except FileNotFoundError as e : 
            print(f"Erreur , l'executable n'est pas trouver {e}")
        

    def check_url(self , url) :
        try :
            self.process.stdin.write(url + "\n")
            self.process.stdin.flush()  #envoyer les donnees directement 

            #maintenat on it la reponse 

            response = self.process.stdout.readline().strip()

            return response #on a la reponse sans le n de fin de phrase 
        except Exception as e : 
            print(f"Erreur de type {e}")
            return None 
        
        def close(self) :
            self.process.terminate() #tue directement tous les process 

