#ifndef FUNCOES_ARVORE_HPP
#define FUNCOES_ARVORE_HPP

#include <string>
#include "ClassFila.hpp"
using namespace std;


struct Node* newNode(int iData);
struct Node* insertNode(struct Node* npNode, int iData);
struct Node* buildTree(string strDadosIniciais);
int treeLength(struct Node* npNode);
int treeDepth(struct Node* npNode);
struct Node* removeElement(struct Node* npNode, int iData);
void searchElement(struct Node* npNode, int iData);
struct Node* insertElement(struct Node* npNode, int iData);
struct Node* minValueNode(struct Node* npNode);
bool isComplete(struct Node* npNode, int iIndex, int iNumberNodes);
bool isPerfect(struct Node* npNode);
void BFS(Node* pNode);
#endif
