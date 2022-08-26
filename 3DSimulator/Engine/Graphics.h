#pragma once

#include <string>

enum class Mask : unsigned int
{
	Color = 0x00004000,
	Depth = 0x00000100,
	Accum = 0x00000200,
	Stencil = 0x00000400
};
struct VertexArrayObject
{
};
class Shader
{
public:
	Shader();
	Shader(unsigned int id);

	void Use();

	int GetID() const;
private:
	unsigned int _id;
};
class Texture
{

};
class Model
{

};