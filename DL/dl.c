#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
 
const double TWO_PI = 6.283153;
GLuint regHex;
GLdouble theta;
GLint x,y,k;

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    gluOrtho2D(0.0,400.0,0.0,400.0);

    regHex = glGenLists(1);
    glNewList(regHex,GL_COMPILE);
        glBegin(GL_POLYGON);
            for(k=0; k<50; k++){
                theta = TWO_PI * k / 50;
                x = 200 + 150*cos(theta);
                y = 200 + 150*sin(theta);
                glVertex2i(x,y);
            }
        glEnd();
    glEndList();
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0, 0.0, 0.5,1.0);
    glCallList(regHex);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - DLs OpenGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
