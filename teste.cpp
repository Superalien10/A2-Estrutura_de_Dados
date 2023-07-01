#include <iostream>
#include "funcoesMenu.hpp"
#include "funcoesArvore.hpp"
#include "funcoesVisualizacao.hpp"
#include "funcoesLista.hpp"
using namespace std;
int main()
{
    cout << "Teste de funcoes" << endl;
    string resultado;

    cout << "Teste de Readtxt" << endl;
    resultado=("1 5 7 18 2 3"==Readtxt("arvore_1.txt"))? "BEM-SUCEDIDO":"FALHOU";
    cout << Readtxt("arvore_1.txt") << endl;
    cout << "Leitura arvore_1.txt: " << resultado << endl;

    // Setup
    struct Node* npNode1 = nullptr;
    npNode1=insertNode(npNode1, 4);
    npNode1=insertNode(npNode1, 2);
    npNode1=insertNode(npNode1, 3);
    npNode1=insertNode(npNode1, 1);
    npNode1=insertNode(npNode1, 5);

    cout << "Teste de treeLength" << endl;
    resultado=(5==treeLength(npNode1))? "BEM-SUCEDIDO":"FALHOU";
    cout << "treeLength: " << resultado << endl;

    cout << "Teste de treeDepth" << endl;
    resultado=(3==treeDepth(npNode1))? "BEM-SUCEDIDO":"FALHOU";
    cout << "treeDepth: " << resultado << endl;

    cout << "Teste de isComplete" << endl;
    resultado=(true==isComplete(npNode1, 0, treeLength(npNode1)))? "BEM-SUCEDIDO":"FALHOU";
    cout << "isComplete: " << resultado << endl;

    cout << "Teste de isPerfect" << endl;
    resultado=(true==isPerfect(npNode1))? "BEM-SUCEDIDO":"FALHOU";
    cout << "isPerfect: " << resultado << endl;

    // Testes da função swapListNodes
    cout << "Teste de swapListNodes" << endl;
    // Setup
    struct ListNode* npListNode1 = nullptr;
    npListNode1=insertListNode(npListNode1, 1);
    npListNode1=insertListNode(npListNode1, 2);
    npListNode1=insertListNode(npListNode1, 3);
    npListNode1=insertListNode(npListNode1, 4);
    npListNode1=insertListNode(npListNode1, 5);
    // Teste 1 - Troca de 1 e 2
    npListNode1=swapListNodes(&(npListNode1), &(npListNode1->npNext), false);
    struct ListNode* npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==2)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 1 e 2: " << resultado << endl;
    // Teste 2 - Troca de 1 e ultimo
    npListNode1=swapListNodes(&(npListNode1), &(npListNode1->npNext->npNext->npNext->npNext), false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==5)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 1 e ultimo: " << resultado << endl;
    // Teste 3 - Troca de penultimo e ultimo
    npListNode1=swapListNodes(&(npListNode1->npNext->npNext->npNext), &(npListNode1->npNext->npNext->npNext->npNext), false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==5)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de penultimo e ultimo: " << resultado << endl;
    // Teste 4 - Troca de 3 e 4
    npListNode1=swapListNodes(&(npListNode1->npNext->npNext), &(npListNode1->npNext->npNext->npNext),false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==5)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 3 e 4: " << resultado << endl;
    // Teste 5 - Troca de 2 e 4
    npListNode1=swapListNodes(&(npListNode1->npNext), &(npListNode1->npNext->npNext->npNext), false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==5)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 2 e 4: " << resultado << endl;
    // Teste 6 - Troca de 3 e ultimo
    npListNode1=swapListNodes(&(npListNode1->npNext->npNext), &(npListNode1->npNext->npNext->npNext->npNext), false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==5)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 3 e ultimo: " << resultado << endl;
    // Teste 7 - Troca de 1 e 4
    npListNode1=swapListNodes(&(npListNode1), &(npListNode1->npNext->npNext->npNext), false);
    npTest = npListNode1;
    while (npTest->npNext!=nullptr)
    {
        npTest=npTest->npNext;
    }
    while (npTest->npPrev!=nullptr)
    {
        npTest=npTest->npPrev;
    }
    resultado=(npTest->iPayload==1)? "BEM-SUCEDIDO":"FALHOU";
    cout << "Troca de 1 e 4: " << resultado << endl;


    cout << "Fim dos testes" << endl;
    return 0;
}
