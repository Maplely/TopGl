#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include "shader/stb_image.h"
class Shader
{
public:
    unsigned int texture1;
    unsigned int texture2;
    unsigned int ID;
    Shader(const char *vertextPath, const char *framentPath);
    void use();
    void start();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif