#include <windows.h>
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include "structs.h"

using namespace std;

void desenha(void);
void savePolygon(V vertice, A aresta);
void display(void);
void getMouseClick(int,int,int,int);

//Flags
bool fill = false, posfound = false, theend = false, delpos = false;

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Editor de Poligonos 2D");
    glutDisplayFunc(desenha);
    glutMouseFunc(getMouseClick);

    glutMainLoop();

    return 0;
}

void desenha(void) {
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

    //Só pode adicionar ou deletar uma posição, se não tiver chegado ao fim ainda.
    if(theend == false) {
		posfound = false;
		if(delpos == true) {
			for(int i=0;i<=100 && posfound == false;i++) {
				if(posx[i] == 0 && posy[i] == 0) {
					//Se o i atual é vazio, o anterior não era. Vamos zerá-lo então:
					posx[i-1] = 0;
					posy[i-1] = 0;
					//Zerando também o penúltimo vértice, pra deletar o segmento que vai de um vértice a outro
					posx[i-2] = 0;
					posy[i-2] = 0;
					posfound = true;
				}
			}
			delpos = false;
		}
		//Percorre os arrays para adicionar próximo vértice
		for(int i=0;i<=100 && posfound == false;i++) {
			if(posx[i] == 0 && posy[i] == 0) {
				posx[i] = xm;
				posy[i] = ym;
				posfound = true; //Posição vazia encontrada e valores adicionados. Sai do For.
			}
		}
	}

	if(theend == false) {
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_STRIP);
	} else {
		glLoadIdentity();
		glTranslatef(dx, dy, 0.0f);
		glScalef(escala, escala, 0.0f);
		glTranslatef(0.0f, -20.0f, 0.0f);
		glRotatef(angulo, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, 20.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(fill ? GL_POLYGON : GL_LINE_LOOP);
	}

	//Desenhando...
    for(int i=0;i<=100 && posx[i] != 0 && posy[i] != 0;i++) {
		glVertex2i(posx[i], posy[i]);
	}
	glEnd();
	glLoadIdentity();

	//Executa os comandos OpenGL
	glFlush();

    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void getMouseClick(int botao, int status, int x, int y) {

    V vertice;
    A aresta;

    if (botao == GLUT_LEFT_BUTTON) {
        if (status == GLUT_DOWN) {
            vertice.x = x;
            vertice.y = y;
            cout << "\n";
            aresta.p1 = vertice;
            savePolygon(vertice, aresta);
            //cout << "X: " << c.x << "\n";
            //cout << "Y: " << c.y << "\n";
        }
    }
}

void savePolygon(V vertice, A aresta) {
    // TODO: save polygon to file
    cout << "X: " << vertice.x << "\n";
    cout << "Y: " << vertice.y << "\n";
}
