#include "StdInc.h"
#include "MainWindow.h"

int MainWindow::getWidth()
{
	return width;
}

int MainWindow::getHeight()
{
	return height;
}

std::string MainWindow::getTitle()
{
	return title;
}

void MainWindow::setHeight(int h)
{
	height = h;
	refreshWindowSize();
}

void MainWindow::setWidth(int w)
{
	width = w;
	refreshWindowSize();
}

void MainWindow::setTitle(std::string name)
{
	title = name;
	glfwSetWindowTitle(windowDirector, title.c_str());
}

MainWindow::MainWindow(GLFWwindow *glfwWindow) : windowDirector(glfwWindow)
{
	glfwGetWindowSize(getWindowDirector(), &width, &height);
	auto setFramebuffer = [](GLFWwindow *window, int width, int height) -> void
	{
		glViewport(0, 0, width, height);
	};
	glfwSetFramebufferSizeCallback(getWindowDirector(), setFramebuffer);
	init();
}

GLFWwindow *MainWindow::getWindowDirector()
{
	return windowDirector;
}

void MainWindow::refreshWindowSize()
{
	glfwSetWindowSize(getWindowDirector(), width, height);
}

void MainWindow::close()
{
	glfwSetWindowShouldClose(getWindowDirector(), GLFW_TRUE);
}

void MainWindow::swapBuffers()
{
	glfwSwapBuffers(getWindowDirector());
}

void MainWindow::init()
{
	makeCurrent();
}

void MainWindow::makeCurrent()
{
	glfwMakeContextCurrent(getWindowDirector());
}
