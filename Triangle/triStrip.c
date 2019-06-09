#include <GL/freeglut.h>
#include <GL/gl.h>
 
void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0, 0.0, 0.0,1.0);
    int p1 [] = {30,80};
    int p2 [] = {60,40};
    int p3 [] = {110,40};
    int p4 [] = {140,80};
    int p5 [] = {110,120};
    int p6 [] = {60,120};
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2iv(p1);
        glVertex2iv(p2);
        glVertex2iv(p6);
        glVertex2iv(p3);
        glVertex2iv(p5);
        glVertex2iv(p4);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - TriStrip openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
