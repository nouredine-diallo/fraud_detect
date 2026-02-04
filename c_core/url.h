// fichier classe url.h
#ifndef __url_H__
#define __url_H__
 
//cette classe charge la liste d'url interdite et l'associe a un string et le compare a l'url iniilae ( de la classe ) 

#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std ; 

class url 
{
 private : 
    string* block ;//la liste d'url interdite 
    int size ;
    int capacite; // ainsi on pourra ajuster 


public : 
    url(); //constructeur initialisé a null
    ~url();//destructeur 

    void load(string fichier) ; // transforme le contenu du fichier en string block

    bool check(string url) ;//fonction clé compare l'url en parametre a la liste block 


};

































#endif 