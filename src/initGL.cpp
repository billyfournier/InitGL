// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include before GLFW
#include<glad/glad.h>

// Include GLFW for Window and I/O control
#include <GLFW/glfw3.h>

int main(){
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);                // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  // OpenGL Version 4.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);  // OpenGL Version x.5
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow( 1024, 768, "InitGL", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    int gladInitRes = gladLoadGL();
    if (!gladInitRes) {
        fprintf(stderr, "Unable to initialize glad\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    
    // Enable key press capture
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    do {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while ( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0
          );

    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
}