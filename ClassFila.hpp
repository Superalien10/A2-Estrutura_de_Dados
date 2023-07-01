#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;


//Estrutura de um node de uma fila
struct sFilaNode {
    Node* pTreeNode;
    sFilaNode* pNext;
};

//Classe da fila
class CFila {
public:
    sFilaNode* pFront, * pRear;

    CFila() {
        pFront = nullptr;
        pRear = nullptr;
    }

    //Função para adicionar o elemento na fila
    void AddFila(Node* pNode) {

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

    //Função para remover o último elemento da fila
    void RemoveFila() {
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

    //Função para exibir a fila
    void DisplayFila() {
        sFilaNode* pTemp = pFront;
        while (pTemp != nullptr) {
            cout << pTemp->pTreeNode->iPayload << " ";
            pTemp = pTemp->pNext;
        }
        cout << endl;
    }
};

