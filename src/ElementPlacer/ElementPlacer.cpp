/************************************************************************/
/* This program contains the minimal set of instructions to create      */
/* anything meaningful with OpenGL. In this case, a white rectangle is  */
/* is drawn using single buffering.                                     */
/************************************************************************/


//Include the input and output streams of the Standard template library
//Every function and variable of that library is inside the namespace std
#include <iostream>
#include <vector>
#include <stdlib.h>

// This inclusion makes the necessary external functions defined in the GLUT framework
// visible to our program. After that, we can use OpenGL and GLUT functions in code.
#include <GL/glut.h>                           

//Global variables
int windowSize = 500;
float triangleSize = 0.03;


// This function is called by GLUT within the main loop every time the window is redrawn
void display()
{
    // Clear the currently visible frame and reset the color of all pixels to black
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the active color to white
    glColor3f(1.f, 1.f, 1.f);

    //Draw all instances inside the element array


    // Finish drawing
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    switch(state)
    {
        //mouse button is released
    case 1:
        break;
        //mouse button is pressed
    case 0:

        //left mouse button is released, create a white point


        //right mouse button is released, create a randomly colored triangle


        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void init( void ) 
{
    //Set a simple orthogonal projection 
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glPointSize(3.0f);
}

//Free the memory for all elements and empty the vector holding the pointers
void cleanup()
{

}

//The entry point for this executable
int main (int argc, char** argv)
{
    srand(0);

    //Initialize GLUT 
    glutInit(&argc, argv);

    //Set single-buffer rendering with RGB color mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Setup a window of 500x500 pixels that is 100x100 pixels away from the upper-left corner of the screen
    glutInitWindowSize(windowSize,windowSize);
    glutInitWindowPosition(100,100);

    //Create the window and give it a title
    glutCreateWindow("Element Placer");

    //Set a callback function for the redraw event inside the GLUT main loop
    glutDisplayFunc(display);

    //Set a callback function for mouse clicks
    glutMouseFunc(mouse);

    //initialize the projection
    init();

    //Enter the GLUT main loop. The program iterates over this loop until closed.
    glutMainLoop();
    
    cleanup();

    //By convention, your program should return 0 when everything worked smoothly and no problems occurred
    //Otherwise you might want to return -1 or any other non-zero value and deliver an error description.
    return 0;
}
