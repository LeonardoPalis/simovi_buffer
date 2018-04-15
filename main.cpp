/* 
 * File:   main.cpp
 * Author: Leonardo
 *
 * Created on 5 de Agosto de 2015, 18:34
 */

#include <cstdlib>
#include <iostream>
#include "Eventos2.h"
#include "Buffer2.h"
#define TAM_PREF 256
typedef bool bit;
using namespace std;

/* MAIN */
int main(int argc, char** argv) {
   
       Buffer2 *towns[4];    
       Buffer2 b;
       
       bit vet1[TAM_CODE], vet2[TAM_CODE],vet3[TAM_CODE];
    
       for(int i = 0; i < TAM_CODE; i++){
            if(i == 2){
                vet1[i] = 0;
            }    
            else vet1[i] = 1;  
        
       }
       for(int i = 0; i < TAM_CODE; i++){
             vet2[i] = 1;        
       }
       
       for(int i = 0; i < TAM_CODE; i++){
             vet3[i] = 0;        
       }
       for(int i = 0; i < 4; i++){
             towns[i] = new Buffer2;        
       }
   
        towns[0]->putTown(0,vet1, "ROCK");
        towns[0]->putTown(0,vet2, "ROCK");        
        //b.putEventType(1,vet2, "RESTAURANTE");
        //b.putEventType(2,vet2, "BALADA");        
        //b.putEventType(0,vet2, "METAL");
    
    return 0;
}

