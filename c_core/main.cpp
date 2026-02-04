#include <iostream> 
using namespace std ;  
#include <fstream> 
#include "url.h"
#include <cstdlib>


int main () {
 
    url liste ; 
    string url ; //l'url que l'utilisateur va entrer 
    cerr<<"Chargement de la liste d'url répertoriée "<<endl ; 
    liste.load("../data/blacklist.txt");
   cout<<"Entrer l'url a verifier "<<endl ;
    while(cin>>url){

    bool danger = liste.check(url) ; 
    if(danger){
        cout<<"DANGER "<<endl ; 
       
    }
    else {

    cout<<"SAFE"<<endl ; 
    

    }

    }
   cerr<<"fin du programme"<<endl ; 

return 0 ; 

}