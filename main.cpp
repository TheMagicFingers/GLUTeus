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

void savePolygon(V vertice);
void display();
void getMouseClick(int,int,int,int);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Editor de Poligonos 2D");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(display);
    glutMouseFunc(getMouseClick);

    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void getMouseClick(int botao, int status, int x, int y) {

    V v;

    if (botao == GLUT_LEFT_BUTTON) {
        if (status == GLUT_DOWN) {
            v.x = x;
            v.y = y;
            cout << "\n";
            savePolygon(v);
            //cout << "X: " << c.x << "\n";
            //cout << "Y: " << c.y << "\n";
        }
    }
}

void savePolygon(V vertice) {
    cout << "X: " << vertice.x << "\n";
    cout << "Y: " << vertice.y << "\n";
}
