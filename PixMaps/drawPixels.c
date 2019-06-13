#include <GL/glut.h>
#include <cstdlib>

const unsigned int W = 640;
const unsigned int H = 640  ;

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    unsigned int data[H][W][3];
    for( size_t y = 0; y < H; y++ )
    {
        //L to R  red
        data[y][y][0] = ( rand() % 256 ) * 256 * 256 * 256;
        //R to L blue
        data[639-y][y][2] = ( rand() % 256 ) * 256 * 256 * 256;
        //Horizontal blue
        data[639/2][y][1] = ( rand() % 256 ) * 256 * 256 * 256;
        //Vertical yellow
        data[y][639/2][1] = ( rand() % 256 ) * 256 * 256 * 256;
        data[y][639/2][0] = ( rand() % 256 ) * 256 * 256 * 256;
    }

    glDrawPixels( W, H, GL_RGB, GL_UNSIGNED_INT, data );

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( W, H );
    glutCreateWindow( "DB Studios - drawPixels" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}