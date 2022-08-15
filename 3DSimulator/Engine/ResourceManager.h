#pragma once

#include <string>

class Shader;
class Texture;
class Model;

class Font
{

};
class ResourceManager
{
public:
	// Dear ImGui Font �� ���� �ƴ°� ������ �ǵ��� ����.
	static const Font& LoadFontFromFile(const std::string& path);
	static const Shader& LoadShader(const std::string& path);
};