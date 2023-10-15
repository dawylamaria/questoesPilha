#include <iostream>
#include <string>
struct ElementoPilha {
    int data;
    ElementoPilha *next;
};

using namespace std;
void push(ElementoPilha *&topo, int value) {
    ElementoPilha* elemento = new ElementoPilha;
    elemento -> data = value;
    elemento -> next = topo;
    topo = elemento;
}

int pop(ElementoPilha *&topo) {
    if (topo == NULL) {
        cout << "A pilha esta vazia" << endl;
        return -1; 
    }

    ElementoPilha *elemento = topo;
    int valor = topo -> data;
    topo = topo -> next;
    delete elemento;
    return valor;
}

int tamanhoPilha(ElementoPilha* topo) {
    int tamanho = 0;
    ElementoPilha* atual = topo;

    while (atual != NULL) {
        atual = atual -> next;
        tamanho++;
    }

    return tamanho;
}

void deletarElementoMeio(ElementoPilha *&topo) {
    int tamanho = tamanhoPilha(topo);

    if (tamanho == 0) {
        cout << "A pilha esta vazia." << endl;
        return;
    }

    int meioPosicao = tamanho / 2;
    ElementoPilha* atual = topo;
    ElementoPilha* anterior = NULL;

    for (int i = 0; i < meioPosicao; i++) {
        anterior = atual;
        atual = atual -> next;
    }

    if (anterior != NULL) {
        anterior -> next = atual -> next;
    } else {
        topo = atual -> next;
    }

    delete atual;
}

void reverterPilha(ElementoPilha *&topo) {
    ElementoPilha *pilha = NULL;

    while (topo != NULL) {
        int valor = pop(topo);
        push(pilha, valor);
    }

    topo = pilha;
}

using namespace std;
void imprimirPilha(ElementoPilha *&topo) {
    ElementoPilha *atual = topo;
    
    while (atual != NULL) {
        cout << atual->data << " ";
        atual = atual->next;
    }
    cout << endl;
}

using namespace std;
int main() {
    ElementoPilha *topo = NULL;

    int escolha;
    
    push(topo, 1);
	push(topo, 2);
    push(topo, 3);
    push(topo, 4);
    push(topo, 5);

    cout << "Digite a questão que deseja compilar (1 a 4):" << endl;
    cin >> escolha;

    switch (escolha) {
        case 1: {

            cout << "Pilha original: ";
            imprimirPilha(topo);

            deletarElementoMeio(topo);

            cout << "Pilha apos a remocao do elemento do meio: ";
            imprimirPilha(topo);
            break;
        }

        case 2: {

            cout << "Pilha original: ";
            imprimirPilha(topo);

            reverterPilha(topo);

            cout << "Pilha revertida: ";
            imprimirPilha(topo);
            break;
        }

        case 3: {
        	cout << "Pilha original: ";
            imprimirPilha(topo);

            reverterString(topo);

            cout << "Pilha revertida: ";
            imprimirPilha(topo);
            break;
        }

        case 4: {
            std::cout << "Implemente a lógica para a questão 4 aqui." << std::endl;
            break;
        }

        default: {
            cout << "Escolha invalida." << endl;
            break;
        }
    }

    while (topo != NULL) {
        pop(topo);
    }

    return 0;
}

