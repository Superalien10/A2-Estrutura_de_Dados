#include "funcoesLista.hpp"
#include "funcoesVisualizacao.hpp"
#include "funcoesArvore.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;




// Função pra criar um novo nó de lista
struct ListNode* newListNode(int iData)
{
    //np -> node pointer
    struct ListNode* npNewNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    npNewNode->iPayload = iData;
    npNewNode->npNext = nullptr;
    npNewNode->npPrev = nullptr;
    return npNewNode;    
}

// Função que insere um nó de lista numa lista
struct ListNode* insertListNode(struct ListNode* npNode, int iData)
{
    struct ListNode* npNewNode = newListNode(iData);
    if (npNode==nullptr) return npNewNode;
    struct ListNode* tempListNode = npNode;
    while (tempListNode->npNext!=nullptr) tempListNode=tempListNode->npNext;
    tempListNode->npNext=npNewNode;
    npNewNode->npPrev=tempListNode;
    return npNode;
}

// Função que atravessa a árvore e adiciona novos itens na lista, copiando a árvore
struct ListNode* traversePreOrder(struct ListNode* npListNode, struct Node* npNode)
{
    if (npNode!=nullptr)
    {
        npListNode = insertListNode(npListNode, npNode->iPayload);
        traversePreOrder(npListNode, npNode->npLeft);
        traversePreOrder(npListNode, npNode->npRight);
    }
    return npListNode;
}

// Função que cria uma lista com base na árvore
struct ListNode* treeToList(struct Node* npNode)
{
    struct ListNode* npListNode = traversePreOrder(nullptr, npNode);
    return npListNode;
}

// Função que exibe os elementos de uma lista
void displayList(struct ListNode* npListNode)
{
    if (npListNode == nullptr)
    {
        cout << "Não é possível exibir: lista vazia" << endl;
        return;
    }

    if (npListNode->npPrev!=nullptr)
    {
        while (npListNode->npPrev!=nullptr)
        {
            npListNode = npListNode->npPrev;
        }
    }

    cout << "Payload: ";

    while (npListNode!=nullptr)
    {
        cout << npListNode->iPayload << " ";
        npListNode = npListNode->npNext;
    }

    cout << endl;
}

// Função que troca dois nós de lista
struct ListNode* swapListNodes(struct ListNode** npFirst, struct ListNode** npSecond, bool visualize=false)
{
    struct ListNode* npRoot = *npFirst;
    while (npRoot->npPrev!=nullptr)
    {
        npRoot = npRoot->npPrev;
    }
    struct ListNode* npOne = *npFirst;
    struct ListNode* npTwo = *npSecond;
    struct ListNode* npTemp;
    // Se a variável visualize for verdadeira, a função visualizeList é chamada para mostrar o processo de troca dos nós.
    if (visualize) visualizeList(npRoot, npOne, npTwo);
    if (npOne->npNext==npTwo&&npOne->npPrev!=nullptr)
    {
        npTemp = npOne->npPrev;
        npOne->npPrev = npTwo;
        npOne->npNext = npTwo->npNext;
        npTwo->npPrev = npTemp;
        npTwo->npNext = npOne;
        npTemp->npNext = npTwo;
        if(npOne->npNext!=nullptr)
        {
            npOne->npNext->npPrev = npOne;
        }
    }
    else if (npOne->npNext==npTwo&&npTwo->npNext!=nullptr)
    {
        npTemp = npTwo->npNext;
        npTwo->npNext = npOne;
        npTwo->npPrev = npOne->npPrev;
        npOne->npNext = npTemp;
        npOne->npPrev = npTwo;
        npTemp->npPrev = npOne;
        if(npTwo->npPrev!=nullptr)
        {
            npTwo->npPrev->npNext = npTwo;
        }
        npRoot=npTwo;
    }
    else if (npOne->npNext==npTwo)//Teste 
    {
        npOne->npPrev=npTwo;
        npOne->npNext=nullptr;
        npTwo->npPrev=nullptr;
        npTwo->npNext=npOne;
        npRoot=npTwo;
    }
    else if (npOne->npPrev==nullptr&&npTwo->npNext==nullptr)
    {
        npOne->npPrev=npTwo->npPrev;
        npTwo->npNext=npOne->npNext;
        npOne->npPrev->npNext=npOne;
        npTwo->npNext->npPrev=npTwo;
        npOne->npNext=nullptr;
        npTwo->npPrev=nullptr;
        npRoot=npTwo;
    }
    else
    {
        npTemp = npOne->npPrev;
        npOne->npPrev = npTwo->npPrev;
        npTwo->npPrev = npTemp;
        npTemp = npOne->npNext;
        npOne->npNext = npTwo->npNext;
        npTwo->npNext = npTemp;
        if(npOne->npPrev!=nullptr)
        {
            npOne->npPrev->npNext = npOne;
        }
        if(npOne->npNext!=nullptr)
        {
            npOne->npNext->npPrev = npOne;
        }
        if(npTwo->npPrev!=nullptr)
        {
            npTwo->npPrev->npNext = npTwo;
        }
        if(npTwo->npNext!=nullptr)
        {
            npTwo->npNext->npPrev = npTwo;
        }
    }
    // Se a variável visualize for verdadeira, a função visualizeList é chamada para mostrar o processo de troca dos nós. Tanto o antes como o depois da troca são representados.
    if (visualize) visualizeList(npRoot, npOne, npTwo);
    return npRoot;
}


// Função que ordena uma lista pelo método de BubbleSort.
struct ListNode* bubbleSort(struct ListNode* npHead, bool visualize=false)
{
    struct ListNode* npCurrent = npHead;
    bool bUnordered = true;
    while(bUnordered)
    {
        bUnordered=false;
        while(npCurrent->npNext!=nullptr)
        {
            if(npCurrent->iPayload > npCurrent->npNext->iPayload)
            {
                swapListNodes(&npCurrent, &npCurrent->npNext, visualize);
                bUnordered=true;
            }
            else
            {
                npCurrent = npCurrent->npNext;
            }
        }
        while(npCurrent->npPrev!=nullptr)
        {
            npCurrent = npCurrent->npPrev;
        }
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead = npCurrent;
    return npHead;
}

// Função que ordena uma lista pelo método de SelectionSort.
struct ListNode* selectionSort(struct ListNode* npHead, bool visualize=false)
{
    struct ListNode* npCurrent = npHead;
    while(npCurrent->npNext!=nullptr)
    {
        struct ListNode* npMin = npCurrent;
        struct ListNode* npTemp = npCurrent->npNext;
        while(npTemp!=nullptr)
        {
            if(npTemp->iPayload < npMin->iPayload)
            {
                npMin = npTemp;
            }
            npTemp = npTemp->npNext;
        }
        if(npMin!=npCurrent)
        {
            swapListNodes(&npCurrent, &npMin, visualize);
            npCurrent = npMin->npNext;
        }
        else
        {
            npCurrent = npCurrent->npNext;
        }
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead=npCurrent;
    return npHead;
}

// Função que ordena uma lista pelo método de InsertionSort.
struct ListNode* insertionSort(struct ListNode* npHead, bool visualize=false)
{
    struct ListNode* npCurrent = npHead;
    while(npCurrent->npNext!=nullptr)
    {
        struct ListNode* npTemp = npCurrent->npNext;
        if (npCurrent->iPayload>npTemp->iPayload)
        {
            swapListNodes(&npCurrent, &npTemp, visualize);
            if (npTemp->npPrev!=nullptr)
            {
                bool bUnordered = true;
                while (npTemp->npPrev!=nullptr && bUnordered)
                {
                    if (npTemp->iPayload<npTemp->npPrev->iPayload)
                    {
                        swapListNodes(&npTemp->npPrev, &npTemp, visualize);
                    }
                    else
                    {
                        bUnordered = false;
                    }
                }
            }
        }
        else
        {
            npCurrent = npCurrent->npNext;
        }
        
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead=npCurrent;
    return npHead;
}

// Função que ordena uma lista pelo método de ShellSort.
struct ListNode* shellSort(struct ListNode* npHead, bool visualize=false)
{
    int n=0;
    int h;
    struct ListNode* npTemp = npHead;
    while (npTemp!=nullptr)
    {
        n++;
        npTemp = npTemp->npNext;
    }
    // A distância a ser usada na comparação entre elementos é calculada com base no tamanho da lista.
    for (h = 1; h <= n; h = 3*h+1);
    h = (h-1)/3;
    npTemp = npHead;
    struct ListNode* npTemp2 = npHead;
    struct ListNode* npTemp3 = npHead;
    while (h > 0)
    {
        while (npTemp2!=nullptr)
        {
            npTemp2=npTemp;
            for (int i=0; i<h; i++)
            {
                npTemp2=npTemp2->npNext;
                if (npTemp2==nullptr) i=h;
            }
            if (npTemp2!=nullptr)
            {
                if (npTemp->iPayload>npTemp2->iPayload)
                {
                    swapListNodes(&npTemp, &npTemp2, visualize);
                    npTemp = npTemp2->npNext;
                    while (npTemp3!=nullptr)
                    {
                        npTemp3=npTemp2;
                        for (int j=0; j<h; j++)
                        {
                            npTemp3=npTemp3->npPrev;
                            if (npTemp3==nullptr) j=h;
                        }
                        if (npTemp3!=nullptr)
                        {
                            if (npTemp3!=nullptr&&npTemp2->iPayload<npTemp3->iPayload)
                            {
                                swapListNodes(&npTemp3, &npTemp2, visualize);
                            }
                            else
                            {
                                npTemp3=nullptr;
                            }
                        }
                    }
                    npTemp3=npHead;
                }
                else
                {
                    npTemp=npTemp->npNext;
                }
            }
        }
        while (npTemp->npPrev!=nullptr)
        {
            npTemp = npTemp->npPrev;
        }
        npTemp2=npHead;
        h = (h-1)/3;
    }
    while (npTemp->npPrev!=nullptr)
    {
        npTemp = npTemp->npPrev;
    }
    npHead=npTemp;
    return npHead;
}

// Função que duplica uma lista. Ela é usada para que possamos comparar a lista original com a lista ordenada.
struct ListNode* duplicateList(struct ListNode* npListNode)
{
    struct ListNode* npHead = nullptr;
    struct ListNode* npTemp = npListNode;
    while (npTemp!=nullptr)
    {
        npHead = insertListNode(npHead, npTemp->iPayload);
        npTemp = npTemp->npNext;
    }
    return npHead;
}
