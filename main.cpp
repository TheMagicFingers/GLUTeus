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

int main(int argc, char **argv){

  if(!pontos){ /*Verifica se a mem�ria foi alocada para 'pontos'.*/
          printf("Erro: Nao foi poss�vel alocar mem�ria.\n");
          exit(1);
        }

    glutInit(&argc,argv); /*Esta fun��o � utilizada para iniciar a biblioteca GLUT.*/
    /*glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);*/
    /*glutInitWindowPosition(200,200); *//*Posi��o da janela na tela*/
    glutInitWindowSize (1280, 720); /*Tamanho da Janela*/
    glutCreateWindow("Editor de Poligonos 2D"); /*Nome da Janela*/
    glutKeyboardFunc(keyboard_cb);/*Fun��o que ser� chamada quando ocorrer um evento no teclado*/
    glutMouseFunc(mouse);/*Fun��o que ser� chamada quando ocorrer um evento no mouse*/
    glutDisplayFunc(display); /*Fun��o que ser� chamada quando houver a necessidade de atualizar a janela*/
    glutMainLoop(); /*Inicia o gerenciamento de eventos, aguardando que algum evento seja acionado.*/
    return EXIT_SUCCESS ;

}

void display(){/*Fun��o respons�vel por plotar na tela*/
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  cabecalho();
  glPointSize(8.0); /*Define o tamanho do ponto*/
  glLineWidth(4); /*Define a espessura da linha*/

  glBegin(GL_LINE_STRIP); /*GL_LINE_STRIP respons�vel por liga os pontos por uma linha reta*/
    glColor3f(1.0,1.0,1.0);/*Define a cor das linhas*/
    for(int i = 0; i<cont-1; i++){
      glVertex2f(pontos[i].coordX,pontos[i].coordY); /*Respons�vel por plotar os pontos*/
    }
    if((cont>3) && (distancia_entre_pontos(pontos[0],pontos[cont-1]) < 0.05) && etapa == 1){ /*Verifica sempre se o �ltimo ponto escolhido est� pr�ximo do primeiro ponto do pol�gono*/
      glVertex2f(pontos[0].coordX,pontos[0].coordY);/*Caso esteja, conecta ao primeiro ponto do pol�gino*/
      etapa = 2; /*Ativa a etapa 2 e em seguida define o �timo ponto como sendo o primeiro*/
      pontos[cont-1].coordX = pontos[0].coordX;
      pontos[cont-1].coordY = pontos[0].coordY;
    }else if(cont > 1){
      glVertex2f(pontos[cont-1].coordX,pontos[cont-1].coordY); /*Respon�vel por plotar o �ltimo ponto*/
    }
  glEnd();
  glFlush();
  glutSwapBuffers();
}
