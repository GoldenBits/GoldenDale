#include "StdInc.h"

#include <render/Texture.h>
#include <iostream>
#include <fstream>
#include "ConstLoader.h"

#include "RectangleItem.h"
#include "window/MainWindow.h"

void initGlfwInfo(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int main(int argc,char **argv)
{
	gen::ConstLoader::load();

	initGlfwInfo();

	auto mainWindow = new MainWindow(glfwCreateWindow(800, 600, gen::Strings::Title.c_str(), nullptr, nullptr));
	glewInit();

	Shader vertexShader(gen::RenderConst::ShaderPaths::VERTEX_SHADER.c_str(), ShaderType::VERTEX_SHADER);
	Shader fragmentShader(gen::RenderConst::ShaderPaths::FRAGMENT_SHADER.c_str(), ShaderType::FRAGMENT_SHADER);
	ShaderProgram shaderProgram;
	shaderProgram.attachShader(&vertexShader);
	shaderProgram.attachShader(&fragmentShader);
	shaderProgram.linkProgram();
	auto * item = new RectangleItem(800,600);
	item->setShaderProgram(&shaderProgram);
	item->texture->setImage(gen::RenderConst::ImagesPaths::MAIN_MENU_BACKGROUND);

	while (!glfwWindowShouldClose(mainWindow->getWindowDirector()))
	{
		item->getShaderProgram()->use();
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(item->getPosition().getX(), item->getPosition().getY(), 1.0f));
		model = glm::scale(model, glm::vec3(item->getWidth(), item->getHeight(), 1.0f));

		item->getShaderProgram()->SetMatrix4("model", model);
		item->getShaderProgram()->SetMatrix4("projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));

		glUniform1i(glGetUniformLocation(item->getShaderProgram()->getID(), "tex"), 0);
		glBindTexture(GL_TEXTURE_2D, item->texture->getID());

		item->getData().getVAO().bindVertexArray();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		item->getData().getVAO().unbind();
		mainWindow->swapBuffers();

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}