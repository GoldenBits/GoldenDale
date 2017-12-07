#pragma once

#include "Window.h"

class GLFWwindow;

class MainWindow : public Window {
public:
	MainWindow(GLFWwindow * glfwWindow);

	int getWidth() override;
    int getHeight() override;
    std::string getTitle() override;

    void setWidth(int w) override;
    void setHeight(int h) override;
    void setTitle(std::string name) override;

	void init() override;
	void close() override;

	void makeCurrent() override;

    GLFWwindow * getWindowDirector() override;

	void swapBuffers();
private:
	void refreshWindowSize();

	int width, height;
    std::string title;
    GLFWwindow * windowDirector;
};