#pragma once
#include <string>

class GLFWwindow;

class Window
{
public:
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual std::string getTitle() = 0;

    virtual void setWidth(int w) = 0;
    virtual void setHeight(int h) = 0;
    virtual void setTitle(std::string name) = 0;

	virtual void init() = 0;
	virtual void close() = 0;

	virtual void makeCurrent() = 0;

    virtual GLFWwindow * getWindowDirector() = 0;
};