#include "funcoesVisualizacao.hpp"
#include "funcoesArvore.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>


using namespace std;


// Função que exibe uma representação gráfica de3 uma lista.
void visualizeList(struct ListNode* npListNode, struct ListNode* npActive1, struct ListNode* npActive2)
{
    struct ListNode* npTemp = npListNode;
    if (npTemp == nullptr)
    {
        cout << "Não é possível exibir: lista vazia" << endl;
        return;
    }

    if (npTemp->npPrev!=nullptr)
    {
        while (npTemp->npPrev!=nullptr)
        {
            npTemp = npTemp->npPrev;
        }
    }

    cout << "Ordenação em andamento: " << endl;

    while (npTemp!=nullptr)
    {
        if (npTemp==npActive1||npTemp==npActive2)
        {
            cout << " | ";
            for (int i=0; i<npTemp->iPosition; i++)
            {
                cout << "#";
            }
        }
        else
        {
            cout << " | ";
            for (int i=0; i<npTemp->iPosition; i++)
            {
                cout << "*";
            }
        }
        cout << endl;
        npTemp = npTemp->npNext;
    }
    sleep(1);
}

// Função que atribui posições aos nós de uma lista.
void setPositions(struct ListNode* npListNode, struct ListNode* npOrdered)
{
    struct ListNode* npTemp = npListNode;
    struct ListNode* npTemp2 = npOrdered;
    // displayList(npListNode);
    // displayList(npOrdered);
    int iPosition = 1;
    int iLast;
    while (npTemp2!=nullptr)
    {
        while (npTemp!=nullptr)
        {
            if (npTemp->iPayload==npTemp2->iPayload)
            {
                npTemp->iPosition = iPosition;
                // cout << "Check 1: " << iPosition << endl;
                // cout << "Check 2: " << npTemp->iPosition << endl;
                // cout << "Check 3: " << npTemp2->iPayload << endl;
                // cout << "Check 4: " << npTemp->iPayload << endl;
                npTemp = npTemp->npNext;
            }
            else
            {
                npTemp = npTemp->npNext;
            }
        }
        npTemp = npListNode;
        iLast=npTemp2->iPayload;
        bool bCondition = true;
        while (bCondition)
        {
            // cout<<"Check 5: "<<npTemp2->iPayload<<endl;
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
        iPosition++;
    }
    displayList(npListNode);
}

