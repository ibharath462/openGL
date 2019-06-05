#include <GL/freeglut.h>
#include <GL/gl.h>
 
void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.4, 0.2);
    int p1 [] = {150,50};
    int p2 [] = {50,120};
    glRectiv(p1,p2);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Rectangle openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
