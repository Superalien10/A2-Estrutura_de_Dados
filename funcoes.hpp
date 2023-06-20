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

#endif
