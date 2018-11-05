/*
Aluno 1: Lucas Martins Mendes Vieira
Aluno 2: Francisco Lucas
Aluno 3: Gustavo Soares
*/

/*Bibliotecas Utilizadas*/
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<math.h>
#include <iostream>

using namespace std;

typedef struct _ponto{ /*Estrutura que define um ponto, com as coordenadas 'x' e 'y'.*/
    float coordX;
    float coordY;
} ponto;

typedef struct _vetor{ /*Estrutura que define um vetor, com os pontos inicial e final*/
  ponto p1; /*Origem do vetor*/
  ponto p2; /*Fim do vetor*/
} vetor;

/*Prot�tipos das fun��es utilizadas*/
void display();
void mouse(int button, int state, int X, int Y);
void keyboard_cb(unsigned char key, int X, int Y);
ponto *resize(ponto *p, int Tamanho, int NovoTam);
void cabecalho();
float distancia_entre_pontos(ponto p1, ponto p2);
bool intersecao(vetor v1, vetor v2);
float produto_vetorial(ponto p1, ponto p2);

/*Vari�veis globais*/
int cont = 0; /*Cont � a quantidade de pontos existentes*/
int tam = 100; /*Tamanho do array que vai guardar os pontos, inicialmente come�a com 100 e cresce conforme a necessidade.*/
int etapa = 1; /*Para controlar a etapa 1 (Construir o p�logono) e a etapa 2 (Escolher um ponto)*/
ponto p; /*Ponto que ser� utilizado para descobrir a localiza��o*/
ponto *pontos = (ponto *) malloc (sizeof(ponto)*tam);/*Aloca��o de mem�ria para o array de pontos*/
