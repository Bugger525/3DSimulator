/*
���
1. ������ �ڵ鸵
2. ���簢��, ��, ť��, ��ü -> ũ�� ����, �� ����, �ؽ���
3. �𵨸�
4. ��� ���� ImGui�� ����
*/

#include "Engine/RenderWindow.h"
#include <iostream>

int main()
{
	auto renderWindow = RenderWindow(1200, 900, "3DSimulator");
	if (!renderWindow.Initialize())
	{
		std::cout << "Failed to initialize a RenderWindow class." << std::endl;
		return -1;
	}

	while (renderWindow.IsOpen())
	{
		renderWindow.Clear();

		// RENDER

		renderWindow.SwapBuffers();
		renderWindow.PollEvents();
	}

	renderWindow.Terminate();

	return 0;
}