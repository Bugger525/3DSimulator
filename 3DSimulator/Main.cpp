/*
���
1. ������ �ڵ鸵
2. ���簢��, ��, ť��, ��ü -> ũ�� ����, �� ����, �ؽ���
3. �𵨸�
4. ��� ���� ImGui�� ����
*/

#include "Engine/RenderWindow.h"
#include "Engine/Graphics.h"
#include "Engine/GUI.h"
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

	while (renderWindow.IsOpen())
	{
		renderWindow.PollEvents();

		renderWindow.Clear(Mask::Color);
		renderWindow.ClearColor(0.45f, 0.55f, 0.60f, 1.00f);

		GUI::NewFrame();

		// RENDER

		GUI::Render();

		renderWindow.SwapBuffers();
	}

	GUI::Cleanup();
	renderWindow.Cleanup();

	return 0;
}