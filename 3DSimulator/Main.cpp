/*
기능
1. 윈도우 핸들링
2. 직사각형, 원, 큐브, 구체 -> 크기 조절, 색 조절, 텍스쳐
3. 모델링
4. 모든 것을 ImGui로 제어
*/

#include "Engine/RenderWindow.h"
#include "Engine/Graphics.h"
#include "Engine/GUI.h"
#include "Engine/ResourceManager.h"
#include <iostream>

int main()
{
	auto renderWindow = RenderWindow(1200, 900, "3DSimulator");
	if (!renderWindow.Initialize())
	{
		std::cout << "Failed to initialize a RenderWindow class." << std::endl;
		return -1;
	}

	GUI::Initialize(renderWindow);
	GUI::SetTheme(Theme::Light);

	auto& shader = ResourceManager::LoadShader("Shaders/shader.vert", "Shaders/shader.frag");

	while (renderWindow.IsOpen())
	{
		renderWindow.PollEvents();

		renderWindow.Clear(Mask::Color);
		renderWindow.ClearColor(0.45f, 0.55f, 0.60f, 1.00f);

		shader.Use();

		GUI::NewFrame();

		// RENDER

		GUI::Render();

		renderWindow.SwapBuffers();
	}

	GUI::Cleanup();
	renderWindow.Cleanup();

	return 0;
}