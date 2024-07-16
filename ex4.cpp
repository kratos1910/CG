#include<windows.h>
#include <GL/glut.h>

float angle = 0.0f;
float scaleX = 1.0f;
float scaleY = 1.0f;
float translateX = 0.0f;
float translateY = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    
    glTranslatef(translateX, translateY, 0.0f); 
    glRotatef(angle, 0.0f, 0.0f, 1.0f);         
    glScalef(scaleX, scaleY, 1.0f);             

    
    glColor3f(0.0f, 1.0f, 0.0f); 

    
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r':
        angle += 5.0f;  
        break;
    case 's':
        scaleX += 0.1f; 
        scaleY += 0.1f;
        break;
    case 't':
        translateX += 0.1f; 
        break;
    case 'd':
        translateX -= 0.1f; 
        break;
    case 'u':
        translateY += 0.1f; 
        break;
    case 'n':
        translateY -= 0.1f;
        break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("vtucode | 2D Transformation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
