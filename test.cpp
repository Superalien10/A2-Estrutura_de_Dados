#include <iostream>
#include "funcoes.hpp"
using namespace std;
int main()
{
    cout << "Teste de funcoes" << endl;
    string resultado;

    cout << "Teste de Readtxt" << endl;
    resultado=("1 5 7 18 2 3"==Readtxt("arvore_1.txt"))? "BEM-SUCEDIDO":"FALHOU";
    cout << Readtxt("arvore_1.txt") << endl;
    cout << "Leitura arvore_1.txt: " << resultado << endl;

    // Testes da função swapListNodes
    cout << "Teste de swapListNodes" << endl;
    // Setup
    struct ListNode* npNode1 = nullptr;
    npNode1=insertListNode(npNode1, 1);
    npNode1=insertListNode(npNode1, 2);
    npNode1=insertListNode(npNode1, 3);
    npNode1=insertListNode(npNode1, 4);
    npNode1=insertListNode(npNode1, 5);
    // Teste 1
    npNode1=swapListNodes(&(npNode1), &(npNode1->npNext));
    struct ListNode* npTest = npNode1;
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
    // Teste 2
    npNode1=swapListNodes(&(npNode1), &(npNode1->npNext->npNext->npNext->npNext));
    npTest = npNode1;
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
    // Teste 3
    npNode1=swapListNodes(&(npNode1->npNext->npNext->npNext), &(npNode1->npNext->npNext->npNext->npNext));
    npTest = npNode1;
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
    // Teste 4
    npNode1=swapListNodes(&(npNode1->npNext->npNext), &(npNode1->npNext->npNext->npNext));
    npTest = npNode1;
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
    // Teste 5
    npNode1=swapListNodes(&(npNode1->npNext), &(npNode1->npNext->npNext->npNext));
    npTest = npNode1;
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
    // Teste 6
    npNode1=swapListNodes(&(npNode1->npNext->npNext), &(npNode1->npNext->npNext->npNext->npNext));
    npTest = npNode1;
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
    // Teste 7
    npNode1=swapListNodes(&(npNode1), &(npNode1->npNext->npNext->npNext));
    npTest = npNode1;
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
