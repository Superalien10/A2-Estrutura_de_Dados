#ifndef FUNCOES_LISTA_HPP
#define FUNCOES_LISTA_HPP

#include <string>
using namespace std;

struct ListNode
{
    int iPayload;
    int iPosition;
    struct ListNode* npNext;
    struct ListNode* npPrev;
};

struct ListNode* newListNode(int iData);
struct ListNode* insertListNode(struct ListNode* npNode, int iData);
struct ListNode* traversePreOrder(struct ListNode* npListNode, struct Node* npNode);
struct ListNode* treeToList(struct Node* npNode);
void displayList(struct ListNode* npListNode);
struct ListNode* swapListNodes(struct ListNode**, struct ListNode**, bool);
struct ListNode* bubbleSort(struct ListNode*, bool);
struct ListNode* selectionSort(struct ListNode*,bool);
struct ListNode* insertionSort(struct ListNode*, bool);
struct ListNode* shellSort(struct ListNode*, bool);
struct ListNode* duplicateList(struct ListNode*);
#endif
