#include "../Engine/GUI.h"
#include "../Engine/RenderWindow.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

bool GUI::Initialize(const RenderWindow& renderWindow)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui_ImplGlfw_InitForOpenGL(renderWindow.GetData(), true);
	ImGui_ImplOpenGL3_Init(renderWindow.GetGLSLVersion().c_str());

	return true;
}
void GUI::SetTheme(const Theme& theme)
{
	switch (theme)
	{
	case Theme::Dark:
		ImGui::StyleColorsDark();
		break;
	case Theme::Light:
		ImGui::StyleColorsLight();
		break;
	case Theme::Classic:
		ImGui::StyleColorsClassic();
		break;
	}
}
void GUI::Render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void GUI::NewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}
void GUI::Cleanup()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}