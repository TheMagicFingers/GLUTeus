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

void display(){/*Função responsável por plotar na tela*/
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  cabecalho();
  glPointSize(8.0); /*Define o tamanho do ponto*/
  glLineWidth(4); /*Define a espessura da linha*/

  glBegin(GL_LINE_STRIP); /*GL_LINE_STRIP responsável por liga os pontos por uma linha reta*/
    glColor3f(1.0,1.0,1.0);/*Define a cor das linhas*/
    for(int i = 0; i<cont-1; i++){
      glVertex2f(pontos[i].coordX,pontos[i].coordY); /*Responsável por plotar os pontos*/
    }
    if((cont>3) && (distancia_entre_pontos(pontos[0],pontos[cont-1]) < 0.05) && etapa == 1){ /*Verifica sempre se o último ponto escolhido está próximo do primeiro ponto do polígono*/
      glVertex2f(pontos[0].coordX,pontos[0].coordY);/*Caso esteja, conecta ao primeiro ponto do polígino*/
      etapa = 2; /*Ativa a etapa 2 e em seguida define o útimo ponto como sendo o primeiro*/
      pontos[cont-1].coordX = pontos[0].coordX;
      pontos[cont-1].coordY = pontos[0].coordY;
    }else if(cont > 1){
      glVertex2f(pontos[cont-1].coordX,pontos[cont-1].coordY); /*Responável por plotar o último ponto*/
    }
  glEnd();
  glFlush();
  glutSwapBuffers();
}
