#ifndef FUNCOES_MENU_HPP
#define FUNCOES_MENU_HPP

#include <string>
#include "funcoesArvore.hpp"
#include "funcoesVisualizacao.hpp"
using namespace std;
string Readtxt(string strNomeArquivo);
string CreateInicialMenu();
void CreateSecondaryMenu(struct Node* npRoot);
void CreateCompleteMenu();
#endif
