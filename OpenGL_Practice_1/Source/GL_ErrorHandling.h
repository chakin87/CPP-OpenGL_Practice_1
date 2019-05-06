#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// TODO: Delete this file


#define ASSERT(X) if (!(X)) __debugbreak();

#define GLCall(X) GLClearError();\
	X;\
	ASSERT(GLLogCall(#X, __FILE__, __LINE__));


static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static void GLCheckError() {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << ")\n";
	}
}

static bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error]   |" << error << "| \n"
			      << "[Funtion]        |" << function << "|\n"
			      << "[Line]           |" << file << "|\n"
			      << "[Line]           |" << line << "|\n";
		return false;
	}
	return true;
}