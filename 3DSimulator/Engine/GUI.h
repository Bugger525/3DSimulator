#pragma once

class RenderWindow;

enum class Theme
{
	Dark,
	Light,
	Classic
};

class GUI
{
public:
	static bool Initialize(const RenderWindow& renderWindow);

	static void SetTheme(const Theme& theme);

	static void Render();

	static void NewFrame();

	static void Cleanup();
};