#include <iostream>
#include "funcoes.cpp"
#include "funcoes.hpp"

using namespace std;

int main()
{
    cout << "Teste de funcoes" << endl;
    string resultado;

    cout << "Teste de Readtxt" << endl;
    resultado=("1 5 7 18 2 3 "==Readtxt("arvore_1.txt"))? "BEM-SUCEDIDO":"FALHOU";
    cout << Readtxt("arvore_1.txt") << endl;
    cout << "Leitura arvore_1.txt: " << resultado << endl;
    
    cout << "Fim dos testes" << endl;
    return 0;
}