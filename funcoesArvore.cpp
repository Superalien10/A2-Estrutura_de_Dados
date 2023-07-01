#include "funcoesArvore.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;


//Função pra criar um novo nó
struct Node* newNode(int iData)
{
    //np -> node pointer
    struct Node* npNewNode = (struct Node*) malloc(sizeof(struct Node));
    npNewNode->iPayload = iData;
    npNewNode->npLeft = nullptr;
    npNewNode->npRight = nullptr;
    return npNewNode;    
}

// Função pra inserir um nó na árvore
struct Node* insertNode(struct Node* npNode, int iData)
{
    if(npNode == nullptr)
    {
        return newNode(iData);
    }
    if(iData < npNode->iPayload)
    {
        npNode->npLeft = insertNode(npNode->npLeft, iData);
    }
    else
    {
        npNode->npRight = insertNode(npNode->npRight, iData);
    }
    return npNode;   
}

// Função pra construir a árvore
struct Node* buildTree(string strDadosIniciais)
{
    struct Node* npRoot = nullptr;
    int iData = 0;
    int i = 0;
    while (strDadosIniciais[i] != '\0')
    {
        if(strDadosIniciais[i] != ' ')
        {
            iData = iData * 10 + (strDadosIniciais[i] - '0');
        }
        else
        {
            npRoot = insertNode(npRoot, iData);
            iData = 0;
        }
        i++;
    }
    npRoot = insertNode(npRoot, iData); 
    return npRoot;
}

// Função pra imprimir o tamanho da árvore
int treeLength(struct Node* npNode)
{
    if (npNode == nullptr)
        return 0;
    else
        return treeLength(npNode->npLeft) + 1 + treeLength(npNode->npRight);
}

//Funcão pra imprimir a profundidade da árvore
int treeDepth(struct Node* npNode)
{
    if (npNode == nullptr)
        return 0;
    else
    {
        int iLeftDepth = treeDepth(npNode->npLeft);
        int iRightDepth = treeDepth(npNode->npRight);
        if (iLeftDepth > iRightDepth)
            return (iLeftDepth + 1);
        else
            return (iRightDepth + 1);
    }
}

// Função que remove elemento da árvore
struct Node* removeElement(struct Node* npNode, int iData)
{
    if (npNode == nullptr)
    {
        return npNode;
    }
    if (iData < npNode->iPayload)
    {
        npNode->npLeft = removeElement(npNode->npLeft, iData);
    }
    else if (iData > npNode->iPayload)
    {
        npNode->npRight = removeElement(npNode->npRight, iData);
    }
    else
    {
        if (npNode->npLeft == nullptr)
        {
            struct Node* temp = npNode->npRight;
            free(npNode);
            return temp;
        }
        else if (npNode->npRight == nullptr)
        {
            struct Node* temp = npNode->npLeft;
            free(npNode);
            return temp;
        }
        struct Node* temp = minValueNode(npNode->npRight);
        npNode->iPayload = temp->iPayload;
        npNode->npRight = removeElement(npNode->npRight, temp->iPayload);
    }
    return npNode;
}

// Função que imprime o endereço de memória de um nó com elemento pedido pelo usuário da árvore
void searchElement(struct Node* npNode, int iData)
{
    if (npNode == nullptr)
    {
        cout << "Elemento nao encontrado" << endl;
        return;
    }
    if (iData < npNode->iPayload)
    {
        searchElement(npNode->npLeft, iData);
    }
    else if (iData > npNode->iPayload)
    {
        searchElement(npNode->npRight, iData);
    }
    else
    {
        cout << "Endereco de memoria do elemento: " << npNode << endl;
    }
}

// Função que insere elemento na árvore
struct Node* insertElement(struct Node* npNode, int iData)
{
    if(npNode == nullptr)
    {
        return newNode(iData);
    }
    if(iData < npNode->iPayload)
    {
        npNode->npLeft = insertNode(npNode->npLeft, iData);
    }
    else
    {
        npNode->npRight = insertNode(npNode->npRight, iData);
    }
    return npNode;   
}

// Função que procura o menor valor da árvore
struct Node* minValueNode(struct Node* npNode)
{
    struct Node* current = npNode;
    while (current && current->npLeft != nullptr)
        current = current->npLeft;
    return current;
}

//Função para verificar se a árvore é completa
bool isComplete(Node* pNpNode, int iIndex, int iNumberNodes) {
    if (pNpNode == nullptr)
        return true;

    //Se o índice atual for maior ou 
    if (iIndex >= iNumberNodes)
        return false;

    //Verificando recursivamente
    return (isComplete(pNpNode->npLeft, 2 * iIndex + 1, iNumberNodes) &&
            isComplete(pNpNode->npRight, 2 * iIndex + 2, iNumberNodes));
}


//Função para verificar se a árvore é perfeita
bool isPerfect(Node* pNpNode) {
    int iD = treeDepth(pNpNode);

    //uma árvore vazia é considerada completa
    if (pNpNode == nullptr)
        return true;

    int iNivel = 0;

    //Verificando a profundidade e se o nó tem 2 filhos
    if (pNpNode->npLeft == nullptr && pNpNode->npRight == nullptr)
        return (iD == iNivel + 1);

    //Verificando se o nó atual tem um filho ou nenhum
    if (pNpNode->npLeft == nullptr || pNpNode->npRight == nullptr)

        //caso a condição prevaleça, a árvore não é perfeita
        return false;
    
    return isPerfect(pNpNode->npLeft) && isPerfect(pNpNode->npRight);
}

//Função para realizar a travessia (Breadth-First Search)
void BFS(Node* pNode) {
    if (pNode == nullptr) return;

    //Criando uma fila
    CFila oFila;
    oFila.AddFila(pNode);

    //Loop para armazenar o nó na fila e printar
    while (oFila.pFront != nullptr) {
        Node* pTemp = oFila.pFront->pTreeNode;
        cout << pTemp->iPayload << endl;

        //Verificando se os nos existem e adicionando na fila
        if (pTemp->npLeft != nullptr) oFila.AddFila(pTemp->npLeft);
        if (pTemp->npRight != nullptr) oFila.AddFila(pTemp->npRight);

        oFila.RemoveFila();
    }
}