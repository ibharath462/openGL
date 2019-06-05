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
    glColor3f(0.0, 0.4, 0.2);
    int p1 [] = {10,20};
    int p2 [] = {85,130};
    int p3 [] = {160,20};
    int p4 [] = {10,80};
    int p5 [] = {160,80};
    glBegin(GL_LINE_STRIP);
        glVertex2iv(p1);
        glVertex2iv(p2);
        glVertex2iv(p3);
        glVertex2iv(p4);
        glVertex2iv(p5);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Lines openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
