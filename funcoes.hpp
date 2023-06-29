#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <string>
using namespace std;
string Readtxt(string strNomeArquivo);
string CreateInicialMenu();
struct Node
{
    int iPayload;
    struct Node* npLeft;
    struct Node* npRight;
};
struct Node* newNode(int iData);
struct Node* insertNode(struct Node* npNode, int iData);
struct Node* buildTree(string strDadosIniciais);
void CreateSecondaryMenu(struct Node* npRoot);
void CreateCompleteMenu();
int treeLength(struct Node* npNode);
int treeDepth(struct Node* npNode);
struct ListNode
{
    int iPayload;
    struct ListNode* npNext;
    struct ListNode* npPrev;
};
struct ListNode* newListNode(int iData);
struct ListNode* insertListNode(struct ListNode* npNode, int iData);
struct ListNode* traversePreOrder(struct ListNode* npListNode, struct Node* npNode);
struct ListNode* treeToList(struct ListNode* npNode);
struct ListNode* bubbleSort(struct Node* npNode);
void displayList(struct ListNode* npListNode);
void swapListNodes(struct ListNode**, struct ListNode**);
struct ListNode* optimizedBubbleSort(struct ListNode**);
struct ListNode* selectionSort(struct Node*);
#endif
