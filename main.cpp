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

using namespace std;

void display();
void getMouseClick(int,int,int,int);

struct coordinates {
    int x;
    int y;
} ;

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

    coordinates c;

    if (botao == GLUT_LEFT_BUTTON) {
        if (status == GLUT_DOWN) {
            c.x = x;
            c.y = y;
            cout << "\n";
            cout << "X: " << c.x << "\n";
            cout << "Y: " << c.y << "\n";
        }
    }
}