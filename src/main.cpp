#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	if (!glfwInit()) {
		std::cout << "Failed to init GLFW!" << std::endl;
	}

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "GLFWWindow", nullptr, nullptr);

    if (!window) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

	return 0;
}