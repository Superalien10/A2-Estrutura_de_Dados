# A2-Estrutura_de_Dados
Trabalho para avaliação durante curso de ciência de dados.

O trabalho de Estrutura de Dados teve como objetivo a construção de um *Explorador de Árvores*. Basicamente, é um programa na linguagem de programação C++ com o objetivo de construir uma árvore binária e oferecer diversas funcionalidades a partir disso, desde verficar se é uma árvore completa até ordená-la.

Integrantes: Lucas Cuan; Rodrigo Kalil; e Yonathan

ATENÇÃO !!!
Para rodar o código no VScode sem dar erro com as organizações das funções em .cpp e .hpp, abra a pasta que contém todos os arquivos e realize o seguinte procedimento: 

Terminal -> NewTerminal -> Colar no terminal: g++ main.cpp funcoes.cpp -o programa -> Colar no terminal: ./programa

##Funcionalidades
Esse programa oferece um total de diversas funcionalidades e para ter acesso a essas, é preciso rodar o código do arquivo "main.cpp", no qual terá como saída o seguinte menu:

![Imagem do WhatsApp de 2023-07-01 à(s) 01 56 06](https://github.com/Superalien10/A2-Estrutura_de_Dados/assets/103382148/e465ac21-75f7-42db-8088-8f1c6517fae7)

A partir disso, nota-se que há 2 opções para construir uma árvore binária, a partir de um arquivo .txt e inserindo os próprios dados no terminal. Ambos precisam estar no seguinte formato, como 15 10 8 12 20 18 25 7 9 11 13 17 19 23 26. 

Logo após a construção da árvore binária, aparece um menu secundário:
![Imagem do WhatsApp de 2023-07-01 à(s) 01 56 46](https://github.com/Superalien10/A2-Estrutura_de_Dados/assets/103382148/4e8465e8-4107-4fe7-aba8-6a0967c58bd6)

Como a árvore já foi construída, o menu secundário apresenta todas as diversas funcionalidades para realizar modificações dentro da árvore já estabelecida. Segue a lista e a descrição sobre o que cada funcionalidade do menu secundário se responsabiliza:

###Menu Secundário
1. IMPRIMA O TAMANHO DA ÁRVORE - tem como objetivo imprimir o número de nós que a árvore possui
2. IMPRIMA A ALTURA/PROFUNDIDADE DA ÁRVORE - imprime a altura daquela árvore, ou seja, número máximo de arestas em qualquer caminho da raiz até uma folha.
3. INSERIR ELEMENTO NA ÁRVORE - adiciona um valor na árvore
4. REMOVER ELEMENTO DA ÁRVORE - remove um valor existente da árvore
5. BUSCAR ENDERECO DE MEMÓRIA DE UM ELEMENTO - procura o endereço de memória de determinado elemento
6. VERIFICAR SE A ÁRVORE E COMPLETA - afirma se a árvore construída é completa ou não
7. VERIFICAR SE A ÁRVORE E PERFEITA - afirma se a árvore construída é perfeita ou não
8. BFS - realiza a Busca em Largura (Breadth-First Search), imprimindo os valores da árvore seguindo a ordem de cada nível, começando a partir da raiz
9. ORDENAR COM BUBBLE SORT - ordena toda a árvore a partir do algoritmo de Bubble Sort
10. ORDENAR COM SELECTION SORT - ordena toda a árvore a partir do algoritmo de Selection Sort
11. ORDENAR COM INSERTION SORT - ordena toda a árvore a partir do algoritmo de Insertion Sort
12. ORDENAR COM SHELL SORT - ordena toda a árvore a partir do algoritmo de Shell Sort
13. Sair - fecha o programa

Obs: as funções de ordenação possuem visualizações, as quais são optativas para o usuário que estiver utilizando o programa

