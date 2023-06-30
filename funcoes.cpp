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
        displayList(treeToList(npRoot));
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
            // case 8:
            //     timeStart = high_resolution_clock::now();
            //     npListRoot = bfs(npRoot);
            //     cout << "Lista: ";
            //     displayList(npListRoot);
            //     break;
            case 9:
                timeStart = high_resolution_clock::now();
                npListRoot = bubbleSort(npRoot);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                break;
            case 10:timeStart = high_resolution_clock::now();
                npListRoot = selectionSort(npRoot);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                break;
            case 11:timeStart = high_resolution_clock::now();
                npListRoot = insertionSort(npRoot);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                break;
            case 12:timeStart = high_resolution_clock::now();
                npListRoot = shellSort(npRoot);
                cout << "Lista ordenada: ";
                displayList(npListRoot);
                break;
            case 13:
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
    return npListNode;
}

// Função que cria uma lista com base na árvore
struct ListNode* treeToList(struct Node* npNode)
{
    struct ListNode* npListNode = traversePreOrder(nullptr, npNode);
    return npListNode;
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
        // cout << "Não é possível exibir: meio da Lista" << endl;
        // return;
        while (npListNode->npPrev!=nullptr)
        {
            npListNode = npListNode->npPrev;
        }
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

//Estrutura de um node de uma fila
struct FilaNode {
    Node* treeNode;
    FilaNode* next;
};

//Classe de faila
class Fila {
public:
    FilaNode *front, *rear;

    Fila() {
        front = NULL;
        rear = NULL;
    }

    void AddFila(Node* node) {
        FilaNode* temp = new FilaNode;
        temp->treeNode = node;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void RemoveFila() {
        if (front == NULL) {
            cout << "A fila está vazia" << endl;
            return;
        }

        FilaNode* temp = front;
        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
    }

    void displayFila() {
        FilaNode* temp = front;
        while (temp != NULL) {
            cout << temp->treeNode->iPayload << " ";
            temp = temp->next;
        }
        cout << endl;
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

//Criando a função para que seja realizada a travessia BFS
void BFS(Node* node) {
    if (node == NULL) return;

    Fila f;
    f.AddFila(node);

    while (f.front != NULL) {
        Node* temp = f.front->treeNode;
        cout << temp->iPayload << endl;

        if (temp->npLeft != NULL) f.AddFila(temp->npLeft);
        if (temp->npRight != NULL) f.AddFila(temp->npRight);

        f.RemoveFila();
    }
    f.displayFila();
}

// Função que troca dois nós de lista
struct ListNode* swapListNodes(struct ListNode** npFirst, struct ListNode** npSecond)
{
    struct ListNode* npRoot = *npFirst;
    while (npRoot->npPrev!=nullptr)
    {
        npRoot = npRoot->npPrev;
    }
    struct ListNode* npOne = *npFirst;
    struct ListNode* npTwo = *npSecond;
    struct ListNode* npTemp;
    if (npOne->npNext==npTwo&&npOne->npPrev!=nullptr)// Teste 3 e 4
    {
        npTemp = npOne->npPrev;
        npOne->npPrev = npTwo;
        npOne->npNext = npTwo->npNext;
        npTwo->npPrev = npTemp;
        npTwo->npNext = npOne;
        npTemp->npNext = npTwo;
        if(npOne->npNext!=nullptr)
        {
            npOne->npNext->npPrev = npOne;
        }
    }
    else if (npOne->npNext==npTwo&&npTwo->npNext!=nullptr)//Teste 1
    {
        npTemp = npTwo->npNext;
        npTwo->npNext = npOne;
        npTwo->npPrev = npOne->npPrev;
        npOne->npNext = npTemp;
        npOne->npPrev = npTwo;
        npTemp->npPrev = npOne;
        if(npTwo->npPrev!=nullptr)
        {
            npTwo->npPrev->npNext = npTwo;
        }
        npRoot=npTwo;
    }
    else if (npOne->npNext==npTwo)//Teste 
    {
        npOne->npPrev=npTwo;
        npOne->npNext=nullptr;
        npTwo->npPrev=nullptr;
        npTwo->npNext=npOne;
        npRoot=npTwo;
    }
    else if (npOne->npPrev==nullptr&&npTwo->npNext==nullptr)// Teste 2
    {
        npOne->npPrev=npTwo->npPrev;
        npTwo->npNext=npOne->npNext;
        npOne->npPrev->npNext=npOne;
        npTwo->npNext->npPrev=npTwo;
        npOne->npNext=nullptr;
        npTwo->npPrev=nullptr;
        npRoot=npTwo;
    }
    else
    {
        npTemp = npOne->npPrev;
        npOne->npPrev = npTwo->npPrev;
        npTwo->npPrev = npTemp;
        npTemp = npOne->npNext;
        npOne->npNext = npTwo->npNext;
        npTwo->npNext = npTemp;
        if(npOne->npPrev!=nullptr)
        {
            npOne->npPrev->npNext = npOne;
        }
        if(npOne->npNext!=nullptr)
        {
            npOne->npNext->npPrev = npOne;
        }
        if(npTwo->npPrev!=nullptr)
        {
            npTwo->npPrev->npNext = npTwo;
        }
        if(npTwo->npNext!=nullptr)
        {
            npTwo->npNext->npPrev = npTwo;
        }
    }
    return npRoot;
}

// Função que pede uma lista pra treeToList e a ordena pelo método de BubbleSort.
struct ListNode* bubbleSort(struct Node* npNode)
{
    struct ListNode* npHead = treeToList(npNode);
    struct ListNode* npCurrent = npHead;
    bool bUnordered = true;
    while(bUnordered)
    {
        bUnordered=false;
        while(npCurrent->npNext!=nullptr)
        {
            if(npCurrent->iPayload > npCurrent->npNext->iPayload)
            {
                swapListNodes(&npCurrent, &npCurrent->npNext);
                bUnordered=true;
            }
            else
            {
                npCurrent = npCurrent->npNext;
            }
        }
        while(npCurrent->npPrev!=nullptr)
        {
            npCurrent = npCurrent->npPrev;
        }
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead = npCurrent;
    return npHead;
}

// Função que pede uma lista pra treeToList e a ordena pelo método de SelectionSort.
struct ListNode* selectionSort(struct Node* npNode)
{
    struct ListNode* npHead = treeToList(npNode);
    struct ListNode* npCurrent = npHead;
    while(npCurrent->npNext!=nullptr)
    {
        struct ListNode* npMin = npCurrent;
        struct ListNode* npTemp = npCurrent->npNext;
        while(npTemp!=nullptr)
        {
            if(npTemp->iPayload < npMin->iPayload)
            {
                npMin = npTemp;
            }
            npTemp = npTemp->npNext;
        }
        if(npMin!=npCurrent)
        {
            swapListNodes(&npCurrent, &npMin);
            npCurrent = npMin->npNext;
        }
        else
        {
            npCurrent = npCurrent->npNext;
        }
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead=npCurrent;
    return npHead;
}

// Função que pede uma lista pra treeToList e a ordena pelo método de InsertionSort.
struct ListNode* insertionSort(struct Node* npNode)
{
    struct ListNode* npHead = treeToList(npNode);
    struct ListNode* npCurrent = npHead;
    while(npCurrent->npNext!=nullptr)
    {
        struct ListNode* npTemp = npCurrent->npNext;
        if (npCurrent->iPayload>npTemp->iPayload)
        {
            swapListNodes(&npCurrent, &npTemp);
            if (npTemp->npPrev!=nullptr)
            {
                while (npTemp->iPayload<npTemp->npPrev->iPayload && npTemp->npPrev!=nullptr)
                {
                    swapListNodes(&npTemp->npPrev, &npTemp);
                }
            }
        }
        else
        {
            npCurrent = npCurrent->npNext;
        }
        
    }
    while(npCurrent->npPrev!=nullptr)
    {
        npCurrent = npCurrent->npPrev;
    }
    npHead=npCurrent;
    return npHead;
}

// Função que pede uma lista pra treeToList e a ordena pelo método de ShellSort.(Por enquanto, ela não faz a ordenação)
struct ListNode* shellSort(struct Node* npNode)
{
    struct ListNode* npHead = treeToList(npNode);
    int n=0;
    int h;
    struct ListNode* npTemp = npHead;
    while (npTemp!=nullptr)
    {
        n++;
        npTemp = npTemp->npNext;
    }
    for (h = 1; h <= n; h = 3*h+1);
    h = (h-1)/3;
    npTemp = npHead;
    struct ListNode* npTemp2 = npHead;
    struct ListNode* npTemp3 = npHead;
    while (h > 0)
    {
        while (npTemp2!=nullptr)
        {
            npTemp2=npTemp;
            for (int i=0; i<h; i++)
            {
                npTemp2=npTemp2->npNext;
                if (npTemp2==nullptr) i=h;
            }
            if (npTemp2!=nullptr)
            {
                if (npTemp->iPayload>npTemp2->iPayload)
                {
                    cout<<"swap"<<npTemp->iPayload<<"e"<<npTemp2->iPayload<<endl;
                    swapListNodes(&npTemp, &npTemp2);
                    displayList(npHead);
                    npTemp = npTemp2->npNext;
                    while (npTemp3!=nullptr)
                    {
                        npTemp3=npTemp2;
                        for (int j=0; j<h; j++)
                        {
                            npTemp3=npTemp3->npPrev;
                            if (npTemp3==nullptr) j=h;
                        }
                        if (npTemp3!=nullptr)
                        {
                            if (npTemp3!=nullptr&&npTemp2->iPayload<npTemp3->iPayload)
                            {
                                cout<<"swap"<<npTemp2->iPayload<<"e"<<npTemp3->iPayload<<endl;
                                swapListNodes(&npTemp3, &npTemp2);
                                displayList(npHead);
                            }
                            else
                            {
                                npTemp3=nullptr;
                            }
                        }
                    }
                    npTemp3=npHead;
                }
                else
                {
                    npTemp=npTemp->npNext;
                }
            }
        }
        while (npTemp->npPrev!=nullptr)
        {
            npTemp = npTemp->npPrev;
        }
        npTemp2=npHead;
        h = (h-1)/3;
    }
    while (npTemp->npPrev!=nullptr)
    {
        npTemp = npTemp->npPrev;
    }
    npHead=npTemp;
    return npHead;
}
