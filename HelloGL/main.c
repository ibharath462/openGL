#include <GL/freeglut.h>
#include <GL/gl.h>
 
void renderFunction()
{
    glClearColor(1.0, 0.0, 0.0, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.3);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    // glBegin(GL_POLYGON);
    //     glVertex2f(-0.5, -0.5);
    //     glVertex2f(-0.5, 0.5);
    //     glVertex2f(0.5, 0.5);
    //     glVertex2f(0.5, -0.5);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
    glBegin(GL_LINES);
        glVertex2i(50,60);
        glVertex2i(100,80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(100,80);
        glVertex2i(150,60);
    glEnd();

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Hello openGL");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
