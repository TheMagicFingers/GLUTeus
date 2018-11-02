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

const GLfloat tam_x = 50.0f;
const GLfloat tam_y = 50.0f;

GLint largura_vp, altura_vp;
GLfloat xm, ym;
GLfloat angulo = 0.0f;

GLfloat posx[100], posy[100];
void savePolygon(V vertice, A aresta);
void display(void);
void getMouseClick(int,int,int,int);
void desenha(void);
void redimensiona(GLsizei largura, GLsizei altura);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Editor de Poligonos 2D");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(display);
    glutDisplayFunc(desenha);
    glutReshapeFunc(redimensiona);
    glutMouseFunc(getMouseClick);
    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void desenha(){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2i(posx[0], posy[0]);
  glVertex2i(posx[1], posy[1]);
  glEnd();
  glFlush();

}

void getMouseClick(int botao, int status, int x, int y) {

    int i = 0;
    if (botao == GLUT_LEFT_BUTTON)
		if (status == GLUT_DOWN) {
			xm = ( (2 * tam_x * x) / largura_vp) - tam_x;
			ym = ( ( (2 * tam_y) * (y - altura_vp) ) / - altura_vp) - tam_y;
			angulo = 0;
		}

     glutPostRedisplay();
}

void savePolygon(V vertice, A aresta) {
    // TODO: save polygon to file
    cout << "\n";
    cout << "X: " << vertice.x << "\n";
    cout << "Y: " << vertice.y << "\n";
}
void redimensiona(GLsizei largura, GLsizei altura) {
     // Redimensiona a viewport para ficar com o mesmo tamanho da janela
     glViewport(0, 0, largura, altura);

     largura_vp = largura;
     altura_vp = altura;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Faz o mapeamento entre a viewport e o sistema de coordenadas 2D
    // levando em consideracao a relacao entre a largura e a altura da viewport
    // Nesse caso, o objeto renderizado vai mudar de tamanho conforme a janela
    // aumentar ou diminuir
    if (largura <= altura)
       gluOrtho2D(-tam_x, tam_x, -tam_y * altura / largura, tam_y * altura / largura);
    else
       gluOrtho2D(-tam_x * largura / altura, tam_x * largura / altura, -tam_y, tam_y);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
