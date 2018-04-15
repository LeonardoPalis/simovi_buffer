/* 
 * File:   Buffer.h
 * Author: Leonardo
 *
 * Created on 5 de Agosto de 2015, 18:34
 */

#ifndef BUFFER_H
#define	BUFFER_H
#define TAM_CODE 256
#define TAM_TYPES 7
#define NUM_CIDADES 6
#define HOURS 7
#include <math.h>
#include <iostream>
#include "Eventos2.h"
typedef bool bit;
using std::string;

class Buffer2 {
public:

    /*
     * struct responsavel por conter o hash de types
     * tipo Eventos2 -> Lista que contem os eventos
     */     
    struct hash{
        Eventos2 hash[TAM_CODE]; 
        
    };
    
    hash h[TAM_TYPES]; //hash dos types
    
    struct hashHour{
        Eventos2 hour[HOURS];
    };
    
    hashHour hhour[TAM_TYPES];
    
    
    Buffer2(){
        
        for(int i = 0; i < TAM_TYPES ; i++){
            //this -> new Buffer();
        }
                
    }
    
    /*
     * Metodo reponsavel por inserir em uma cidade elementos do buffer
     * @param type -> tipo de evento
     * @param vet -> vetor binario com as preferencias
     * @param ref -> string que indica o type
     */
    void putTown(int type,bit *vet,string ref){    
       this->putEventType(type,vet, ref); 
    }

    
    /*
     * Metodo responsavel por setar um TYPE com uma lista de eventos
     * @param pos_Type
     * @param p posicao 0 do array binario 
     */    
    void putEventType(int pos_Type, bit *p, string ref){
        int aux = calculator_hash(&p[0]);
        
        h[pos_Type].hash[aux].insereFimCode(&p[0],ref);
        cout << &h[pos_Type].hash[aux].first << "-> ";
        h[pos_Type].hash[aux].mostrarCodeByNode(&h[pos_Type].hash[aux].first->prox[0]);
       
        cout << endl;
    }
    
    /*
     * Metodo responsavel por calcular o hash (posicao) que sera inserido no hash
     * Funcao transforma o array binario em um numero decimal mod 256 para encaixar no hash
     * @param p -> posicao 0 do array binario
     * @return soma -> posicao do hash
     */
    int calculator_hash(bit *p){
        int soma = 0;
        int aux = 0;
        for(int i = 0; i < TAM_CODE; i++,p++){
           if(*p == 1){
               aux = pow(2,i);
               soma += aux%256;
           }  
       }
        return soma;
    }

    
    Buffer2(const Buffer2& orig);
    int types[9];
    
    virtual ~Buffer2();
private:
    
    
};

#endif	/* BUFFER_H */

