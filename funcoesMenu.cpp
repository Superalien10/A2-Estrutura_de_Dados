#include "funcoesMenu.hpp"
#include "funcoesLista.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>


using namespace std;
using namespace std::chrono;

// Variáveis globais que registram tempo
duration<double>timeDuration;
time_point<system_clock> timeStart, timeStop;

// Função para ler o arquivo .txt
string Readtxt(string strNomeArquivo)
{
    timeStart = high_resolution_clock::now();
    ifstream ifsArquivo(strNomeArquivo); 

    if (ifsArquivo.is_open()) {
        string strLinha;
        string strConteudoArquivo;

        while (getline(ifsArquivo, strLinha)) {
            strConteudoArquivo += strLinha + " ";
        }
        strConteudoArquivo.pop_back();
        //Se quiser ver o conteudo do arquivo, descomente a linha abaixo
        //cout << "Conteúdo do arquivo:\n" << strConteudoArquivo << endl;
        return strConteudoArquivo;
        ifsArquivo.close(); 
    } else {
        cout << "Falha ao abrir o arquivo." << endl;
        return "";
    }

}


// Função para criar o menu inicial
string CreateInicialMenu()
{
    int iOpcao;

    while (true) {
        cout << "======================" << endl;
        cout << "      MENU INICIAL     " << endl;
        cout << "======================" << endl;
        cout << "1. CONSTRUIR ARVORE BINARIA DE BUSCA POR .TXT (cada dado deve estar separado por espaco no arquivo)" << endl;
        cout << "2. CONSTRUIR ARVORE BINARIA DE BUSCA INSERINDO DADOS" << endl;
        cout << "3. Sair" << endl;
        cout << "======================" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> iOpcao;
        cout << endl;

        string strNomeArquivo;
        string strDadosIniciais;
        switch (iOpcao) {
            case 1:
                cout << "Opcao 1 selecionada." << endl;
                cout << "Digite o nome do arquivo com a extensao: ";
                cin >> strNomeArquivo;
                timeStart = high_resolution_clock::now();
                return Readtxt(strNomeArquivo);
                break;
            case 2:
                cout << "Opcao 2 selecionada." << endl;
                cout << "Insira abaixo os valores que para construir a arvore separados por espaco:" << endl;
                cin.ignore();
                getline(cin, strDadosIniciais);
                timeStart = high_resolution_clock::now();
                return strDadosIniciais;
            case 3:
                cout << "Saindo do programa..." << endl;
                timeStart = high_resolution_clock::now();
                return "";
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

        cin.ignore();
        cout << "Pressione Enter para continuar...";
        cin.get();
    }
}

// Função pra criar menu secundário
void CreateSecondaryMenu(struct Node* npRoot)
{
    int iOpcao;
    char cOpcao;

    while (true) {
        cout << "======================" << endl;
        cout << "      MENU SECUNDARIO     " << endl;
        cout << "======================" << endl;
        cout << "1. IMPRIMA O TAMANHO DA ARVORE" << endl;
        cout << "2. IMPRIMA A ALTURA/PROFUNDIDADE DA ARVORE" << endl;
        cout << "3. INSERIR ELEMENTO NA ARVORE" << endl;
        cout << "4. REMOVER ELEMENTO DA ARVORE" << endl;
        cout << "5. BUSCAR ENDERECO DE MEMORIA DE UM ELEMENTO" << endl;
        cout << "6. VERIFICAR SE A ARVORE E COMPLETA" << endl;
        cout << "7. VERIFICAR SE A ARVORE E PERFEITA" << endl;
        cout << "8. BFS" << endl;
        cout << "9. ORDENAR COM BUBBLE SORT" << endl;
        cout << "10. ORDENAR COM SELECTION SORT" << endl;
        cout << "11. ORDENAR COM INSERTION SORT" << endl;
        cout << "12. ORDENAR COM SHELL SORT" << endl;
        cout << "13. Sair" << endl;
        cout << "======================" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> iOpcao;
        cout << endl;

        struct ListNode* npListRoot = nullptr;
        struct ListNode* npHead;
        struct ListNode* npCopyRoot = nullptr;
      
        switch (iOpcao) {
            case 1:
                timeStart = high_resolution_clock::now();
                cout << "Tamanho da arvore: " << treeLength(npRoot) << endl;
                break;
            case 2:
                timeStart = high_resolution_clock::now();
                cout << "Altura/Profundidade da arvore: " << treeDepth(npRoot) << endl;
                break;
            case 3:
                timeStart = high_resolution_clock::now();
                cout << "Insira o elemento que deseja inserir na arvore: ";
                int iElemento;  
                cin >> iElemento;
                npRoot = insertElement(npRoot, iElemento);
                break;
            case 4:
                timeStart = high_resolution_clock::now();
                cout << "Digite o elemento que deseja remover da arvore: ";
                cin >> iElemento;
                npRoot = removeElement(npRoot, iElemento);
                break;
            case 5:
                timeStart = high_resolution_clock::now();
                cout << "Insira o elemento que deseja buscar na arvore: ";
                cin >> iElemento;
                searchElement(npRoot, iElemento);
                cout << endl;
                break;
            case 6:
                timeStart = high_resolution_clock::now();
                if (isComplete(npRoot, 0, treeLength(npRoot))) 
                {
                    cout << "A arvore e completa." << endl;
                } else 
                {
                    cout << "A arvore nao e completa." << endl;
                }
                break;
            case 7:
                timeStart = high_resolution_clock::now();
                if (isPerfect(npRoot)) 
                {
                    cout << "A arvore e perfeita." << endl;
                } else 
                {
                    cout << "A arvore nao e perfeita." << endl;
                }
                break;
            case 8:
                timeStart = high_resolution_clock::now();
                cout << "BFS: " << endl;
                BFS(npRoot);
                break;
            case 9:
                timeStart = high_resolution_clock::now();
                // A função treeToList cria uma lista duplamente encadeada a partir da árvore.
                npHead = treeToList(npRoot);
                // A função duplicateList cria uma cópia da lista duplamente encadeada.
                npCopyRoot = duplicateList(npHead);
                // A função bubbleSort ordena a lista duplamente encadeada.
                npListRoot = bubbleSort(npHead, false);
                timeStop=high_resolution_clock::now();
                timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                cout << "A ordenacao levou " << timeDuration.count() << " nanosegundos." << endl;
                cout << "Se quiser ver o processo de ordenacao a seguir, digite s/S. Caso contrario, digite n/N> ";
                cin >> cOpcao;
                if (cOpcao == 's' || cOpcao == 'S')
                {
                    // A função setPositions atribui a cada nó da lista um valor de posição, que é usado para representar graficamente a lista.
                    setPositions(npCopyRoot, npListRoot);
                    // A função bubbleSort ordena a lista duplamente encadeada.
                    // Desta vez, o parâmetro bVisualize é verdadeiro, o que faz com que a função visualizeList seja chamada a cada troca de nós.
                    bubbleSort(npCopyRoot, true);
                }
                break;
            case 10:timeStart = high_resolution_clock::now();
                npHead = treeToList(npRoot);
                npCopyRoot = duplicateList(npHead);
                npListRoot = selectionSort(npHead, false);
                timeStop=high_resolution_clock::now();
                timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                cout << "A ordenacao levou " << timeDuration.count() << " nanosegundos." << endl;
                cout << "Se quiser ver o processo de ordenacao a seguir, digite s/S. Caso contrario, digite n/N> ";
                cin >> cOpcao;
                if (cOpcao == 's' || cOpcao == 'S')
                {
                    setPositions(npCopyRoot, npListRoot);
                    selectionSort(npCopyRoot, true);
                }
                break;
            case 11:timeStart = high_resolution_clock::now();
                npHead = treeToList(npRoot);
                npCopyRoot = duplicateList(npHead);
                npListRoot = insertionSort(npHead, false);
                timeStop=high_resolution_clock::now();
                timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                cout << "A ordenacao levou " << timeDuration.count() << " nanosegundos." << endl;
                cout << "Se quiser ver o processo de ordenacao a seguir, digite s/S. Caso contrario, digite n/N> ";
                cin >> cOpcao;
                if (cOpcao == 's' || cOpcao == 'S')
                {
                    setPositions(npCopyRoot, npListRoot);
                    insertionSort(npCopyRoot, true);
                }
                break;
            case 12:timeStart = high_resolution_clock::now();
                npHead = treeToList(npRoot);
                npCopyRoot = duplicateList(npHead);
                npListRoot = shellSort(npHead, false);
                timeStop=high_resolution_clock::now();
                timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                cout << "A ordenacao levou " << timeDuration.count() << " nanosegundos." << endl;
                cout << "Se quiser ver o processo de ordenacao a seguir, digite s/S. Caso contrario, digite n/N> ";
                cin >> cOpcao;
                if (cOpcao == 's' || cOpcao == 'S')
                {
                    setPositions(npCopyRoot, npListRoot);
                    shellSort(npCopyRoot, true);
                }
                break;
            case 13:
                timeStart = high_resolution_clock::now();
                cout << "Saindo do programa..." << endl;
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

        if (iOpcao <= 9 || iOpcao >= 12)
        {
            timeStop=high_resolution_clock::now();
            timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        }
        cout << "Tempo de operacao: " << timeDuration.count() << endl;
        cin.ignore();
        cout << "Pressione Enter para continuar...";
        cin.get();
    }
}

// Função pra criar o menu completo
void CreateCompleteMenu()
{
    string strDadosIniciais = CreateInicialMenu();
    if (strDadosIniciais == "") return; // Se o usuario digitou 3 no menu inicial
    struct Node* npRoot = buildTree(strDadosIniciais);
    timeStop=high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo de operacao: " << timeDuration.count() << endl;
    CreateSecondaryMenu(npRoot);
    timeStop=high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo de operacao: " << timeDuration.count() << endl;

}

