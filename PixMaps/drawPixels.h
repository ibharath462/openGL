#include <GL/freeglut.h>
#include <GL/gl.h>

int WIDTH, HEIGHT = 400;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
    glFlush(); 
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowSize(WIDTH, HEIGHT); 
    glutInitWindowPosition(100, 100); 

    int MainWindow = glutCreateWindow("Hello Graphics!!"); 
    glClearColor(0.5, 0.5, 0.5, 0);

    makePixel(200,200,0,0,0,PixelBuffer);

    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;
}
