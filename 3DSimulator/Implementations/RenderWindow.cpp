#include "../Engine/RenderWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using std::tuple;
using std::string;

static void GLFWErrorCallback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

RenderWindow::RenderWindow(int width, int height, const string& title)
{
	size_ = std::make_tuple(width, height);
	title_ = title;

	glVersion_ = std::make_tuple(3, 3);

	endOfInit_ = false;

	data_ = NULL;
}
bool RenderWindow::Initialize()
{
	glfwSetErrorCallback(GLFWErrorCallback);

	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, std::get<0>(glVersion_));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, std::get<1>(glVersion_));
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	data_ = glfwCreateWindow(std::get<0>(size_), std::get<1>(size_), title_.c_str(), NULL, NULL);
	if (data_ == NULL)
	{
		std::cout << "Failed to create a GLFW window." << std::endl;
		return false;
	}
	glfwMakeContextCurrent(data_);
	gladLoadGL();
	glfwSwapInterval(1); // Enable VSYNC

	glfwSetWindowSizeCallback(data_, [](GLFWwindow* window, int width, int height)
		{
			auto renderWindow = static_cast<RenderWindow*>(glfwGetWindowUserPointer(window));
			renderWindow->SetSize(width, height);
			glViewport(0, 0, width, height);
		});
	endOfInit_ = true;
	return true;
}
const tuple<int, int>& RenderWindow::GetSize() const
{
	return size_;
}
const tuple<int, int>& RenderWindow::GetFrameSize() const
{
	int left = 0, top = 0, right = 0, bottom = 0;
	glfwGetWindowFrameSize(data_, &left, &top, &right, &bottom);

	return std::make_tuple(right - left, top - bottom);
}
void RenderWindow::SetSize(int width, int height)
{
	std::get<0>(size_) = width;
	std::get<1>(size_) = height;

	if (!endOfInit_)
		return;

	glfwSetWindowSize(data_, width, height);
}
const string& RenderWindow::GetTitle() const
{
	return title_;
}
void RenderWindow::SetTitle(const string& title)
{
	title_ = title;

	if (!endOfInit_)
		return;

	glfwSetWindowTitle(data_, title.c_str());
}
const tuple<int, int>& RenderWindow::GetGLVersion() const
{
	return glVersion_;
}
const string& RenderWindow::GetGLSLVersion() const
{
	auto major = std::to_string(std::get<0>(glVersion_));
	auto minor = std::to_string(std::get<1>(glVersion_));

	return "#version " + major + minor + "0";
}
void RenderWindow::SetGLVersion(int major, int minor)
{
	if (endOfInit_)
		return;

	std::get<0>(glVersion_) = major;
	std::get<1>(glVersion_) = minor;
}
bool RenderWindow::IsOpen() const
{
	return !glfwWindowShouldClose(data_);
}
void RenderWindow::PollEvents() const
{
	glfwPollEvents();
}
void RenderWindow::SwapBuffers() const
{
	glfwSwapBuffers(data_);
}
void RenderWindow::Clear(const Mask& mask) const
{
	glClear(static_cast<GLbitfield>(mask));
}
void RenderWindow::ClearColor(float red, float green, float blue, float alpha) const
{
	glClearColor(red, green, blue, alpha);
}
void RenderWindow::Close() const
{
	glfwSetWindowShouldClose(data_, true);
}
void RenderWindow::Terminate() const
{
	glfwDestroyWindow(data_);
	glfwTerminate();
}