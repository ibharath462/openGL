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
    glColor4f(1.0, 0.0, 0.5,1.0);
    GLubyte bitShpae [20] = {0x00,0x00,0x63,0xF0,0x71,0x98,0x79,0x98,0x79,0xF0,0x79,0xF0,0x79,0x98,0x71,0xF0,0x63,0xF0,0x00,0x00};
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glRasterPos2i(30,85);
    glBitmap(16,10,0.0,0.0,20.0,15.0,bitShpae);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Bitmap openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
