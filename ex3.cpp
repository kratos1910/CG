#include<windows.h>
#include <GL/glut.h>

GLfloat angleX = 0.0f; // Angle for rotation around x-axis
GLfloat angleY = 0.0f; // Angle for rotation around y-axis
GLfloat scale = 1.0f;   // Scale factor

void init()
{
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Load the identity matrix

    glTranslatef(0.0f, 0.0f, -5.0f); // Translate the cube to a distance of -5 units along z-axis
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotate the cube around x-axis
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotate the cube around y-axis
    glScalef(scale, scale, scale); // Scale the cube

    // Draw Cube
    glBegin(GL_QUADS); // Begin drawing the cube using quads
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Top face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // Right face
    glColor3f(1.0f, 0.0f, 1.0f); // Purple color
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd(); // End of drawing cube

    glFlush(); // Flush OpenGL buffer
    glutSwapBuffers(); // Swap front and back buffers
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1; // To prevent divide by 0 error when height is 0
    glViewport(0, 0, width, height); // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION); // Switch to projection matrix
    glLoadIdentity(); // Load the identity matrix
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f); // Set perspective
    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix
    glLoadIdentity(); // Load the identity matrix
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
    case 27: // 'q' key or ESC key
        exit(0); // Exit program
        break;
    case '+':
        scale += 0.1f; // Scale up
        break;
    case '-':
        scale -= 0.1f; // Scale down
        if (scale < 0.1f)
            scale = 0.1f; // Prevent scaling down too small
        break;
    }
    glutPostRedisplay(); // Mark the current window for redisplay
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        angleX += 5.0f; // Rotate cube upward
        break;
    case GLUT_KEY_DOWN:
        angleX -= 5.0f; // Rotate cube downward
        break;
    case GLUT_KEY_LEFT:
        angleY -= 5.0f; // Rotate cube to the left
        break;
    case GLUT_KEY_RIGHT:
        angleY += 5.0f; // Rotate cube to the right
        break;
    }
    glutPostRedisplay(); // Mark the current window for redisplay
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("vtucode | Basic 3D Geometric Operations"); // Create the window with the given title
    init(); // Initialize drawing
    glutDisplayFunc(display); // Register display callback function
    glutReshapeFunc(reshape); // Register reshape callback function
    glutKeyboardFunc(keyboard); // Register keyboard callback function
    glutSpecialFunc(specialKeys); // Register special keys callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
