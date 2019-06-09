#include <GL/freeglut.h>
#include <GL/gl.h>
 
void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0, 0.0, 0.5,1.0);
    int p1 [] = {30,120};
    int p2 [] = {60,30};
    int p3 [] = {100,40};
    int p4 [] = {100,90};
    int p5 [] = {150,90};
    int p6 [] = {150,60};
    int p7 [] = {190,10};
    int p8 [] = {190,120};
    glBegin(GL_QUADS);
        glVertex2iv(p1);
        glVertex2iv(p2);
        glVertex2iv(p3);
        glVertex2iv(p4);
        glVertex2iv(p5);
        glVertex2iv(p6);
        glVertex2iv(p7);
        glVertex2iv(p8);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Quad openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
