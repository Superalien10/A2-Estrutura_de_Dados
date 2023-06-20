#include "funcoes.hpp"
#include <iostream>
#include <fstream>
using namespace std;
string strReadtxt(string strNomeArquivo)
{
    ifstream ifsArquivo(strNomeArquivo); 

    if (ifsArquivo.is_open()) {
        string strLinha;
        string strConteudoArquivo;

        while (getline(ifsArquivo, strLinha)) {
            strConteudoArquivo += strLinha + " ";
        }

        //Se quiser ver o conteudo do arquivo, descomente a linha abaixo
        //cout << "Conteúdo do arquivo:\n" << strConteudoArquivo << endl;
        
        return strConteudoArquivo;
        ifsArquivo.close(); 
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
        return "";
    }

}
string strCreateInicialMenu()
{
    int iOpcao;

    while (true) {
        cout << "======================" << endl;
        cout << "      MENU INICIAL     " << endl;
        cout << "======================" << endl;
        cout << "1. CONSTRUÍR ÁRVORE BINÁRIA DE BUSCA POR .TXT (cada dado deve estar separado por espaço no arquivo)" << endl;
        cout << "2. CONSTRUÍR ÁRVORE BINÁRIA DE BUSCA INSERINDO DADOS" << endl;
        cout << "3. Sair" << endl;
        cout << "======================" << endl;
        cout << "Digite o número da opção: ";
        cout << endl;
        cin >> iOpcao;

        string strNomeArquivo;
        string strDadosIniciais;
        switch (iOpcao) {
            case 1:
                cout << "Opção 1 selecionada." << endl;
                cout << "Digite o nome do arquivo com a extensão: ";
                cin >> strNomeArquivo;
                break;
            case 2:
                cout << "Opção 2 selecionada." << endl;
                cout << "Insira abaixo os valores que para construír a árvore separados por espaço:" << endl;
                cin >> strDadosIniciais;
                return strDadosIniciais;
            case 3:
                cout << "Saindo do programa..." << endl;
                return "";
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

        cin.ignore();
        cout << "Pressione Enter para continuar...";
        cin.get();
    }
}