
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>


#include "Renderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"



#include "tools/cpp/runfiles/runfiles.h"


using bazel::tools::cpp::runfiles::Runfiles;

int main(int argc, char** argv)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
    };

    std::cout << glGetString(GL_VERSION) << std::endl;


    /////______________________________________________________________________////

    //define buffer and indicies
    {
        float positions[] = {
             -0.5f, -0.5f,  // 0
              0.5f, -0.5f,  // 1
              0.5f,  0.5f,  // 2
             -0.5f,  0.5f,  // 3
        };

        unsigned int indicies[] = {
           0, 1, 2,
           2, 3, 0
        };

        


        
        VertexArray va;                                          // Vertex array object
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));       // Vertex buffer creation
        VertexBufferLayout layout;                               // Vertex buffer layout creation
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indicies, 6);                             // Index buffer creation




        std::string error;
        std::string argv0 = argv[0];
        std::unique_ptr<Runfiles> runfiles(Runfiles::Create(argv0, &error));

        if (!runfiles)
        {
            std::cout << "[FATAL] Runfiles failed: " << error << std::endl;
            return -1;
        }

        std::string path = runfiles->Rlocation(
            "opengl_app/application.shader"
        );
        
        std::cout << "Shader path: " << path << std::endl;

        Shader shader(path);                     // Define shaders
        shader.Bind();                                           //glUseProgram(shader);
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);  // Uniform logic



        float r = 0.0f;
        float increment = 0.05f;




        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);


            shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

            va.Bind();
            GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

            if (r > 1.0f)
                increment = -0.05f;
            if (r < 0.0f)
                increment = 0.05f;


            r += increment;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}

