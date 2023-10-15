#include <iostream>

struct ElementoPilha {
	int data;
	ElementoPilha *next;
};

void push(ElementoPilha *&topo, int value){
	ElementoPilha *elemento = new ElementoPilha;
	elemento -> data = value;
	elemento -> next = topo;
		
	topo = elemento;
}

int meio(ElementoPilha *& topo){
	int tamanho = 0;
		
	ElementoPilha *aux = new ElementoPilha;
	aux = topo;
	
	while(aux != NULL){
		aux = aux -> next;
		tamanho++;
	
	}
	
	//int x = tamanho / 2;
	return 100;
	
}

/*void imprimirLista(ElementoPilha *& topo) {
    ElementoPilha *aux = new 
    while (atual != NULL) {
        cout << atual->data << " ";
        atual = atual->next;
    }
    cout << endl;

}
*/


/*
using namespace std;
void pop(ElementoPilha *&topo){
	if(topo == NULL){
		cout << "A lista esta vazia" << endl;
	}
	else{
		ElementoPilha *aux = new ElementoPilha;
		aux = topo;
		
		topo = topo -> next;
		
		delete aux;
	}
}
*/

int main(int argc, char** argv) {
	
	int posicaoMeio;
	
	ElementoPilha *topo = new ElementoPilha;
	
	
		
	push(topo,1);
	push(topo,2);
	push(topo,3);
	push(topo,4);
	push(topo,5);
				
	posicaoMeio = meio(topo);
				
	cout << posicaoMeio;
						
				
			

	
	return 0;
}
