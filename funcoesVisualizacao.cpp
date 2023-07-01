#include "funcoesVisualizacao.hpp"
#include "funcoesArvore.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;

// Essas funções permitem a visualização do processo de ordenação dos elementos de uma árvore binária.
// Com elas nós etiquetamos os nós para podermos representá-los graficamente, com base em sua posição.

void visualizeList(struct ListNode* npListNode, struct ListNode* npActive1, struct ListNode* npActive2)
{
    /* A função exibe uma representação gráfica de uma lista duplamente encadeada. Ela destaca os nós assinalados como ativos.

    argumentos:
        npListNode: ponteiro para o primeiro nó da lista
        npActive1: ponteiro para o primeiro nó ativo (nó que está sendo trocado)
        npActive2: ponteiro para o segundo nó ativo
    */
    struct ListNode* npTemp = npListNode;
    if (npTemp == nullptr)
    {
        // Caso o ponteiro para o primeiro nó seja nulo, a lista está vazia. Um aviso é dado ao usuário.
        cout << "Nao e possivel exibir: lista vazia" << endl;
        return;
    }

    if (npTemp->npPrev!=nullptr)
    {
        while (npTemp->npPrev!=nullptr)
        {
            // O ponteiro é movido para o primeiro nó da lista.
            npTemp = npTemp->npPrev;
        }
    }

    cout << "Ordenacao em andamento: " << endl;

    while (npTemp!=nullptr)
    {
        if (npTemp==npActive1||npTemp==npActive2)
        {
            // Caso o nó seja ativo, ele é representado por um asterisco.
            cout << " | ";
            for (int i=0; i<npTemp->iPosition; i++)
            {
                cout << "#";
            }
        }
        else
        {
            // Caso contrário, ele é representado por um traço.
            cout << " | ";
            for (int i=0; i<npTemp->iPosition; i++)
            {
                cout << "*";
            }
        }
        cout << endl;
        // O ponteiro é movido para o próximo nó.
        npTemp = npTemp->npNext;
    }
    // A função sleep() é usada para dar um intervalo de tempo entre a exibição de cada etapa.
    sleep(1);
}

void setPositions(struct ListNode* npListNode, struct ListNode* npOrdered)
{
    /* Essa função atribui posições aos nós de uma lista duplamente encadeada, com base na versão ordenada da mesma. Ela é usada para a visualização do processo de ordenação.
    
    argumentos:
        npListNode: ponteiro para o primeiro nó da lista
        npOrdered: ponteiro para o primeiro nó da lista ordenada
    */
    struct ListNode* npTemp = npListNode;
    struct ListNode* npTemp2 = npOrdered;
    int iPosition = 1;
    int iLast;
    while (npTemp2!=nullptr)
    {
        while (npTemp!=nullptr)
        {
            // A função percorre a lista original e atribui posições aos nós que possuem o mesmo valor que o nó da lista ordenada que está sendo analisado.
            if (npTemp->iPayload==npTemp2->iPayload)
            {
                npTemp->iPosition = iPosition;
                npTemp = npTemp->npNext;
            }
            else
            {
                npTemp = npTemp->npNext;
            }
            // O ponteiro é movido para o próximo nó.
        }
        // O ponteiro é movido para o primeiro nó da lista original.
        npTemp = npListNode;
        iLast=npTemp2->iPayload;
        bool bCondition = true;
        while (bCondition)
        {
            // A função percorre a lista ordenada até encontrar um nó com valor diferente do nó que já foi analisado.
            if (npTemp2->npNext!=nullptr)
            {
                npTemp2 = npTemp2->npNext;
                if (npTemp2->iPayload!=iLast)
                {
                    bCondition = false;
                }
            }
            else
            {
                bCondition=false;
                npTemp2=nullptr;
            }
        }
        // A posição é incrementada. De posse do próximo nó da lista ordenada, o processo é repetido.
        iPosition++;
    }
}

