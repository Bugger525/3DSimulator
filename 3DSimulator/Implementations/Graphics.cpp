#include "../Engine/Graphics.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader()
{
    _id = 0;
}
Shader::Shader(unsigned int id)
{
    _id = id;
}
void Shader::Use()
{
	glUseProgram(_id);
}
int Shader::GetID() const
{
	return _id;
}