#include <shader/shader.h>

Shader::Shader(const char *vertextPath, const char *framentPath)
{
    std::string vertextCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vShaderFile.open(vertextPath);
        fShaderFile.open(framentPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertextCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    const char *vShaderCode = vertextCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    unsigned int vertext, fragment;
    vertext = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertext, 1, &vShaderCode, NULL);
    glCompileShader(vertext);
    checkCompileErrors(vertext, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    
   

    ID = glCreateProgram();
    glAttachShader(ID, vertext);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    

    checkCompileErrors(ID, "PROGRAM");
    glDeleteShader(vertext);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR:SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog << "\n -----------------------------" << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR:PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog << "\n -----------------------------" << std::endl;
        }
    }
}