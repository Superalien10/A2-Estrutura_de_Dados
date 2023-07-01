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
    void AddFila(Node* pNode);

    //Função para remover o último elemento da fila
    void RemoveFila();

    //Função para exibir a fila
    void DisplayFila();
};

