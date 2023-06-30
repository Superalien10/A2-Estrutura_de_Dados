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
        cout << "3. ORDENAR COM BUBBLE SORT" << endl;
        cout << "4. INSERIR ELEMENTO NA ARVORE" << endl;
        cout << "5. REMOVER ELEMENTO DA ARVORE" << endl;
        cout << "6. BUSCAR ENDERECO DE MEMORIA DE UM ELEMENTO" << endl;
        cout << "7. VERIFICAR SE A ARVORE E COMPLETA" << endl;
        cout << "8. VERIFICAR SE A ARVORE E PERFEITA" << endl;
        cout << "14. Sair" << endl;
        cout << "======================" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> iOpcao;
        cout << endl;

        struct ListNode* npListRoot = nullptr;
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
                npListRoot = bubbleSort(npRoot);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                break;
            case 4:
                timeStart = high_resolution_clock::now();
                cout << "Insira o elemento que deseja inserir na arvore: ";
                int iElemento;  
                cin >> iElemento;
                npRoot = insertElement(npRoot, iElemento);
                break;
            case 5:
                timeStart = high_resolution_clock::now();
                cout << "Insira o elemento que deseja remover da arvore: ";
                cin >> iElemento;
                npRoot = removeElement(npRoot, iElemento);
                break;
            case 6:
                timeStart = high_resolution_clock::now();
                cout << "Insira o elemento que deseja buscar na arvore: ";
                cin >> iElemento;
                searchElement(npRoot, iElemento);
                cout << endl;
                break;
            case 7:
                timeStart = high_resolution_clock::now();
                if (isComplete(npRoot, 0, treeLength(npRoot))) 
                {
                    cout << "A arvore e completa." << endl;
                } else 
                {
                    cout << "A arvore nao e completa." << endl;
                }
                break;
            case 8:
                timeStart = high_resolution_clock::now();
                if (isPerfect(npRoot)) 
                {
                    cout << "A arvore e perfeita." << endl;
                } else 
                {
                    cout << "A arvore nao e perfeita." << endl;
                }
                break;
            case 14:
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

// Função pra criar um novo nó de lista
struct ListNode* newListNode(int iData)
{
    //np -> node pointer
    struct ListNode* npNewNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    npNewNode->iPayload = iData;
    npNewNode->npNext = nullptr;
    npNewNode->npPrev = nullptr;
    return npNewNode;    
}

// Função que insere um nó de lista numa lista
struct ListNode* insertListNode(struct ListNode* npNode, int iData)
{
    struct ListNode* npNewNode = newListNode(iData);
    if (npNode==nullptr) return npNewNode;
    struct ListNode* tempListNode = npNode;
    while (tempListNode->npNext!=nullptr) tempListNode=tempListNode->npNext;
    tempListNode->npNext=npNewNode;
    npNewNode->npPrev=tempListNode;
    return npNode;
}

// Função que atravessa a árvore e adiciona novos itens na lista, copiando a árvore
struct ListNode* traversePreOrder(struct ListNode* npListNode, struct Node* npNode)
{
    if (npNode!=nullptr)
    {
        npListNode = insertListNode(npListNode, npNode->iPayload);
        traversePreOrder(npListNode, npNode->npLeft);
        traversePreOrder(npListNode, npNode->npRight);
    }
}

// Função que cria uma lista com base na árvore
struct ListNode* treeToList(struct Node* npNode)
{
    struct ListNode* npListNode = traversePreOrder(nullptr, npNode);
    return npListNode;
}

// Função que pede uma lista pra treeToList e a ordena pelo método de BubbleSort (Por enquanto, ela não faz a ordenação)
struct ListNode* bubbleSort(struct Node* npNode)
{
    return treeToList(npNode);
}

// Função que exibe os elementos de uma lista
void displayList(struct ListNode* npListNode)
{
    if (npListNode == nullptr)
    {
        cout << "Não é possível exibir: lista vazia" << endl;
        return;
    }

    if (npListNode->npPrev!=nullptr)
    {
        cout << "Não é possível exibir: meio da Lista" << endl;
        return;
    }

    cout << "Payload: ";

    while (npListNode!=nullptr)
    {
        cout << npListNode->iPayload << " ";
        npListNode = npListNode->npNext;
    }

    cout << endl;
}

// Função que insere elemento na árvore
struct Node* insertElement(struct Node* npNode, int iData)
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

// Função que procura o menor valor da árvore
struct Node* minValueNode(struct Node* npNode)
{
    struct Node* current = npNode;
    while (current && current->npLeft != nullptr)
        current = current->npLeft;
    return current;
}

// Função que remove elemento da árvore
struct Node* removeElement(struct Node* npNode, int iData)
{
    if (npNode == nullptr)
    {
        return npNode;
    }
    if (iData < npNode->iPayload)
    {
        npNode->npLeft = removeElement(npNode->npLeft, iData);
    }
    else if (iData > npNode->iPayload)
    {
        npNode->npRight = removeElement(npNode->npRight, iData);
    }
    else
    {
        if (npNode->npLeft == nullptr)
        {
            struct Node* temp = npNode->npRight;
            free(npNode);
            return temp;
        }
        else if (npNode->npRight == nullptr)
        {
            struct Node* temp = npNode->npLeft;
            free(npNode);
            return temp;
        }
        struct Node* temp = minValueNode(npNode->npRight);
        npNode->iPayload = temp->iPayload;
        npNode->npRight = removeElement(npNode->npRight, temp->iPayload);
    }
    return npNode;
}

// Função que imprime o endereço de memória de um nó com elemento pedido pelo usuário da árvore
void searchElement(struct Node* npNode, int iData)
{
    if (npNode == nullptr)
    {
        cout << "Elemento nao encontrado" << endl;
        return;
    }
    if (iData < npNode->iPayload)
    {
        searchElement(npNode->npLeft, iData);
    }
    else if (iData > npNode->iPayload)
    {
        searchElement(npNode->npRight, iData);
    }
    else
    {
        cout << "Endereco de memoria do elemento: " << npNode << endl;
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
