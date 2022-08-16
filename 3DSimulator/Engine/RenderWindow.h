#pragma once

#include <tuple>
#include <string>
#include "Graphics.h"

struct GLFWwindow;

class RenderWindow
{
public:
	RenderWindow(int width, int height, const std::string& title);

	bool Initialize();

	const std::tuple<int, int>& GetSize() const;
	const std::tuple<int, int>& GetFrameSize() const;
	void SetSize(int width, int height);

	const std::string& GetTitle() const;
	void SetTitle(const std::string& title);

	const std::tuple<int, int>& GetGLVersion() const;
	const std::string& GetGLSLVersion() const;
	void SetGLVersion(int major, int minor);

	GLFWwindow* GetData() const;

	bool IsOpen() const;

	void PollEvents() const;
	void SwapBuffers() const;

	void Clear(const Mask& mask) const;
	void ClearColor(float red, float green, float blue, float alpha) const;

	void Close() const;
	void Cleanup() const;
private:
	std::tuple<int, int> size_;
	std::string title_;

	std::tuple<int, int> glVersion_;

	bool endOfInit_;

	GLFWwindow* data_;
};