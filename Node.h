/* 
 * File:   Node.h
 * Author: Leonardo
 *
 * Created on 6 de Agosto de 2015, 00:01
 */

#ifndef NODE_H
#define	NODE_H
#include <cstdlib>
#include <iostream>
#define TAM_CODE 256

typedef bool bit;
class Node {
public:
    int elemento;
    Node *prox;
    bit code[TAM_CODE];
    
    /*
     * Construtor vazio da classe
     */
    Node(){
        elemento = 0;
        prox = NULL;
    }
    
    /*
     * COnstrutor da classe
     * @param *vet -> ponteiro direcionado para a primeira posicao do array binario
     */
    Node(bit *vet){ 
       
        for(int i = 0; i < TAM_CODE; i++,vet++ ){
            this->code[i] = *vet;
            
        }
    }
    
    /*
     * Construtor da classe
     * @param a -> inteiro que sera inserido no node da lista
     */
    Node(int a){
        elemento = a;
        prox = NULL;
        
    }
    
    Node(const Node& orig);
    virtual ~Node();
private:

};

#endif	/* NODE_H */

