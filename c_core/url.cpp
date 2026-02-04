// fichier classe url.h
#include "url.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream> 
using namespace std ;

url::url(){
 block= nullptr ;
 size = 0 ;
 capacite = 1 ;

} 

url::~url() { 
    if (block != nullptr) {
        delete[] block; 
    }
}

void url::load(string fichier){
    ifstream file(fichier) ;
  
    if (!file.is_open()) {
        cerr << "Impossible d'ouvrir en lecture le fichier : " << fichier << endl   ;
        exit(EXIT_FAILURE);
        }
    string line ; 
    int total = 0 ; // compte le nombre de ligne du fichier 
    while(getline(file , line) ){ // tant qu'on atteint pas la fin de ligne 
        if(!line.empty()){
            total ++ ; 
        }
    }

    size = total ; 
   block = new string[size] ; 
   file.clear();             // pour que la lecture du fichier recommence au debut 
file.seekg(0, ios::beg);
   
   int i = 0 ; 
   while(getline(file , line)){ // on rempli le tableau de string ligne par ligne 
    if(!line.empty()){
        block[i] = line ; 
        i++;
    }

   }
   
file.close();
}


bool url::check(string url){
    for(unsigned int i = 0 ; i < size ; i++){
        if(url==block[i]){
            return true ;
        }
    }
        return false ; 

    }



































