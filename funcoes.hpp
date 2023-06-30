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
struct Node* insertElement(struct Node* npNode, int iData);
struct Node* minValueNode(struct Node* npNode);
struct Node* removeElement(struct Node* npNode, int iData);
void searchElement(struct Node* npNode, int iData);
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
bool isPerfect(struct Node* npNode);
bool isComplete(struct Node* npNode, int iIndex, int iCount);
void BFS(struct Node* npNode);
#endif
