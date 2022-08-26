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
	// Dear ImGui Font 에 대해 아는게 없으니 건들지 말자.
	static const Font& LoadFontFromFile(const std::string& path);
	static Shader& LoadShader(const std::string& vertPexath, const std::string& fragPath);
};