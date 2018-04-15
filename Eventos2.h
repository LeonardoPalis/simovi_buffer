/* 
 * File:   Eventos.h
 * Author: Leonardo
 *
 * Created on 5 de Agosto de 2015, 18:50
 */

#ifndef EVENTOS2_H
#define	EVENTOS2_H
#define TAM_CODE 256  //tamanho do array de preferencias
#include <iostream>
#include <string>
#include <list>
#include "Node.h"
using std::endl;
using std::string;
using std::cout;

typedef bool bit; //vetor booleano

class Eventos2 {
public:
    Node *first, *last, trash;
    Eventos2 *inicio, *fim;
    Eventos2 *t;
    string ref;
    bit type[7];
    bit code[256];
  
    /*
     * Contrutor da classe
     */
    Eventos2(){
        fim = inicio = NULL;
        first = new Node(-1);
        last = first;
        
    }
    
    Eventos2(int ){ }
    
    /*
     * Metodo responsavel por inserir um novo evento no final da lista
     * @param a -> inteiro que sera inserido
     */
    void insereFim(int a){
        
        last->prox = new Node(a);
        last = last->prox;
        last->prox = &trash;
        
    }
    
    /*
     * Metodo responsavel por inserir no fim da lista um array binario
     * @param bit b -> array de 256 elementos binarios
     */
    Eventos2 *insereFimCode(bit b[], string tmp_ref){
        ref = tmp_ref;
        last->prox = new Node(&b[0]);
        last = last->prox;
        last->prox = &trash;
        
        return this;
    }
    
    /*
     * Metdo responsavel por mostrar um elemento da lista inteiro
     */
    void mostrar(){
        Node *s = first->prox;
        for( ;s != &trash ;  ){          
            cout << s->elemento << " ";
            s = s->prox;
        }
           
    }
   
    /*
     * Metodo que mostra o array binario
     */
    void mostrarCode(){
       // Node *s = first->prox;
        Node *n = new Node;
        n = first->prox;
        cout << "( ";
        
        for( ; n->prox != NULL ;  ){
            
            for(int i = 0; i < TAM_CODE; i++){
                cout << n->code[i];
            } 
            cout << " )" << endl;
            n = n->prox;
        }
        
    }
    
    /*
     * Metodo que mostra o array binario
     */
    void mostrarCodeByNode(Node *no){
       // Node *s = first->prox;
        
        for( ; no->prox != NULL ;  ){
       
            for(int i = 0; i < TAM_CODE; i++){
                cout << no->code[i];
            } 
            cout << " )" << endl;
            no = no->prox;
        }
        
    }
    
    Eventos2(const Eventos2& orig);
    virtual ~Eventos2();
private:

};

#endif	/* EVENTOS2_H */
