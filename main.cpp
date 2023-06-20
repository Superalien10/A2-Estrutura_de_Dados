#include <iostream>
#include "funcoes.hpp"
using namespace std;
int main()
{
    string strDadosIniciais =  CreateInicialMenu();
    struct Node* npRoot = buildTree(strDadosIniciais);
    return 0;
}
