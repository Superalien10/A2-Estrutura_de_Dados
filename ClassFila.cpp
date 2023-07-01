#include "ClassFila.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;


void CFila::AddFila(Node* pNode) {

    //Criando um novo nó da fila
    sFilaNode* pTemp = new sFilaNode;

    //Definindo o novo nó como o pNode e seu próximo como ponteiro nulo
    pTemp->pTreeNode = pNode;
    pTemp->pNext = nullptr;

    //Se a fila estiver vazia, o da frente e o último são o mesmo
    if (pRear == nullptr) {
        pFront = pRear = pTemp;
        return;
    }

    pRear->pNext = pTemp;
    pRear = pTemp;
}

void CFila::RemoveFila() {
    if (pFront == nullptr) {
        cout << "A fila está vazia" << endl;
        return;
    }

    //Armazenando o ponteiro do primeiro nó e atualizando
    sFilaNode* pTemp = pFront;
    pFront = pFront->pNext;

    //Caso a fila fique vazia, colocar o último nó como nulo
    if (pFront == nullptr) {
        pRear = nullptr;
    }

    //Liberando a memória do nó
    delete pTemp;
}

void CFila::DisplayFila() {
    sFilaNode* pTemp = pFront;
    while (pTemp != nullptr) {
        cout << pTemp->pTreeNode->iPayload << " ";
        pTemp = pTemp->pNext;
    }
    cout << endl;
}