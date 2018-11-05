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

/*Protótipos das funções utilizadas*/
void display();
void mouse(int button, int state, int X, int Y);
void keyboard_cb(unsigned char key, int X, int Y);
ponto *resize(ponto *p, int Tamanho, int NovoTam);
void cabecalho();
float distancia_entre_pontos(ponto p1, ponto p2);
bool intersecao(vetor v1, vetor v2);
float produto_vetorial(ponto p1, ponto p2);

/*Variáveis globais*/
int cont = 0; /*Cont é a quantidade de pontos existentes*/
int tam = 100; /*Tamanho do array que vai guardar os pontos, inicialmente começa com 100 e cresce conforme a necessidade.*/
int etapa = 1; /*Para controlar a etapa 1 (Construir o pílogono) e a etapa 2 (Escolher um ponto)*/
ponto p; /*Ponto que será utilizado para descobrir a localização*/
ponto *pontos = (ponto *) malloc (sizeof(ponto)*tam);/*Alocação de memória para o array de pontos*/

int main(int argc, char **argv){

  if(!pontos){ /*Verifica se a memória foi alocada para 'pontos'.*/
          printf("Erro: Nao foi possível alocar memória.\n");
          exit(1);
        }

    glutInit(&argc,argv); /*Esta função é utilizada para iniciar a biblioteca GLUT.*/
    /*glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);*/
    /*glutInitWindowPosition(200,200); *//*Posição da janela na tela*/
    glutInitWindowSize (1280, 720); /*Tamanho da Janela*/
    glutCreateWindow("Editor de Poligonos 2D"); /*Nome da Janela*/
    glutKeyboardFunc(keyboard_cb);/*Função que será chamada quando ocorrer um evento no teclado*/
    glutMouseFunc(mouse);/*Função que será chamada quando ocorrer um evento no mouse*/
    glutDisplayFunc(display); /*Função que será chamada quando houver a necessidade de atualizar a janela*/
    glutMainLoop(); /*Inicia o gerenciamento de eventos, aguardando que algum evento seja acionado.*/
    return EXIT_SUCCESS ;

}
