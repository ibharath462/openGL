#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstring>

int glWidth( void* font, const char* str )
{
    int width = 0;
    for( size_t i = 0; i < strlen( str ); ++i )
    {
        width += glutStrokeWidth( font, (int)str[i] );
    }
    return width;
}

void glPrint( void* font, const char* str )
{
    for( size_t i = 0; i < strlen( str ); ++i )
    {
        glutStrokeCharacter( font, (int)str[i] );
    }
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);

    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    glOrtho( -250 * ar, 250 * ar, -250, 250, -1, 1 );

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0, 0.0, 0.0,1.0);

    void* font = GLUT_STROKE_MONO_ROMAN;
    const char* str = "D";
    glTranslatef( -glWidth( font, str ), 0, 0 );
    glPrint( font, str );

    glRasterPos2i(0,0);
    glColor4f(0.0, 0.0, 1.0,1.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'B');

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize( 640, 480 );
    //glutInitWindowPosition(100,100);
    glutCreateWindow("DB studios - Text openGL");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
