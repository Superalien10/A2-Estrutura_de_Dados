#include "funcoes.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

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

    while (true) {
        cout << "======================" << endl;
        cout << "      MENU SECUNDARIO     " << endl;
        cout << "======================" << endl;
        cout << "1. IMPRIMA O TAMANHO DA ARVORE" << endl;
        cout << "2. IMPRIMA A ALTURA/PROFUNDIDADE DA ARVORE" << endl;
        cout << "3. Sair" << endl;
        cout << "======================" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> iOpcao;
        cout << endl;

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
                cout << "Saindo do programa..." << endl;
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

        timeStop=high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
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
    struct Node* npRoot = buildTree(strDadosIniciais);
    timeStop=high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo de operacao: " << timeDuration.count() << endl;
    CreateSecondaryMenu(npRoot);
    timeStop=high_resolution_clock::now();
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo de operacao: " << timeDuration.count() << endl;

}

//Função pra criar um novo nó
struct Node* newNode(int iData)
{
    //np -> node pointer
    struct Node* npNewNode = (struct Node*) malloc(sizeof(struct Node));
    npNewNode->iPayload = iData;
    npNewNode->npLeft = nullptr;
    npNewNode->npRight = nullptr;
    return npNewNode;    
}

// Função pra inserir um nó na árvore
struct Node* insertNode(struct Node* npNode, int iData)
{
    if(npNode == nullptr)
    {
        return newNode(iData);
    }
    if(iData < npNode->iPayload)
    {
        npNode->npLeft = insertNode(npNode->npLeft, iData);
    }
    else
    {
        npNode->npRight = insertNode(npNode->npRight, iData);
    }
    return npNode;   
}

// Função pra construir a árvore
struct Node* buildTree(string strDadosIniciais)
{
    struct Node* npRoot = nullptr;
    int iData = 0;
    int i = 0;
    while (strDadosIniciais[i] != '\0')
    {
        if(strDadosIniciais[i] != ' ')
        {
            iData = iData * 10 + (strDadosIniciais[i] - '0');
        }
        else
        {
            npRoot = insertNode(npRoot, iData);
            iData = 0;
        }
        i++;
    }
    npRoot = insertNode(npRoot, iData);
    return npRoot;
}

// Função pra imprimir o tamanho da árvore
int treeLength(struct Node* npNode)
{
    if (npNode == nullptr)
        return 0;
    else
        return treeLength(npNode->npLeft) + 1 + treeLength(npNode->npRight);
}

//Funcão pra imprimir a profundidade da árvore
int treeDepth(struct Node* npNode)
{
    if (npNode == nullptr)
        return 0;
    else
    {
        int iLeftDepth = treeDepth(npNode->npLeft);
        int iRightDepth = treeDepth(npNode->npRight);
        if (iLeftDepth > iRightDepth)
            return (iLeftDepth + 1);
        else
            return (iRightDepth + 1);
    }
}

//Função para criar um node de uma fila
class Fila {
    public:
        Node *front;
        Node *rear;
        Fila() 
        {
            front = NULL;
            rear = NULL;
        }

        //Função para adicionar árvores na fila
        void AddFila(Node* node) 
        {
            if(front == NULL) 
            {
                front = node;
                rear = node;
            } else 
            {
                rear->npRight = node;
                rear = node;
            }
        }

        //Função para remover o primeiro elemento da fila (First In First Out)
        void RemoveFila() 
        {
            if(front == NULL) 
            {
                cout << "A fila está vazia" << endl;
            } 
            else 
            {
                Node* temp = front;
                front = front->npRight;
                delete temp;
            }
        }

        void inorderTraversal(Node* node) 
        {
            if(node != NULL) 
            {
            inorderTraversal(node->npLeft);
            cout << node->iPayload << " ";   
            inorderTraversal(node->npRight); 
            }
        }


        //Função para exibir a fila
        void displayFila() {
            if(front == NULL) 
            {
            cout << "Fila vazia" << endl;
            } 
            else 
            {
                Node* temp = front;
                while(temp != NULL) 
                {
                    inorderTraversal(temp); 
                    cout << endl;
                    temp = temp->npRight;
                }
            }
        
        }
};

bool isComplete(struct Node* npNode, int iIndex, int iNumberNodes)
{
    if (npNode == nullptr)
        return (true);

    if (iIndex >= iNumberNodes)
        return (false);

    return (isComplete(npNode->npLeft, 2 * iIndex + 1, iNumberNodes) && 
    isComplete(npNode->npRight, 2 * iIndex + 2, iNumberNodes));
}

//Criando uma função para avaliar se a árvore é perfeita
bool isPerfect(struct Node* npNode)
{
    int iD = treeDepth(npNode);
    if (npNode == NULL)
        return true;

    int iNivel = 0;

    if (npNode->npLeft == NULL && npNode->npRight == NULL)
        return (iD == iNivel + 1);

    if (npNode->npLeft == NULL || npNode->npRight == NULL)
        return false;

    return isPerfect(npNode->npLeft) && isPerfect(npNode->npRight);
}

//Criando a função para garantir que 
void BFS(struct Node* npNode) {
    Fila f;
    f.AddFila(npNode);

    while(f.front!=NULL)
    {
        Node* temp = f.front;
        f.RemoveFila();

        cout << temp->iPayload << endl;

        if(temp->npLeft != NULL)
        {
            f.AddFila(temp->npLeft);
        }

        if(temp->npRight != NULL)
        {
            f.AddFila(temp->npRight);
        }
    }
    f.displayFila();
};
