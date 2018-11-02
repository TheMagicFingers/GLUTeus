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

A aresta;
void savePolygon(V vertice, A aresta);
void display(void);
void getMouseClick(int,int,int,int);
void desenha(void);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Editor de Poligonos 2D");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(display);
    glutMouseFunc(getMouseClick);
    glutMouseFunc(desenha);
    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void desenha(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2i(40,200);  glVertex2i(200,10);
  glEnd();
  glFlush();
}

void getMouseClick(int botao, int status, int x, int y) {

    int i = 0;
    if (botao == GLUT_LEFT_BUTTON) {
        if (status == GLUT_DOWN) {
            V vertice;
            vertice.x = x;
            vertice.y = y;
            i++
            if (i == 1)
                aresta.p1 = V;
            if (i == 2)
                aresta.p2 = V

            //savePolygon(vertice, aresta);
            //cout << "X: " << c.x << "\n";
            //cout << "Y: " << c.y << "\n";
        }
    }
}

void savePolygon(V vertice, A aresta) {
    // TODO: save polygon to file
    cout << "\n";
    cout << "X: " << vertice.x << "\n";
    cout << "Y: " << vertice.y << "\n";
}
