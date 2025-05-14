#include <string>

int recursao(const std::string &str, char alvo)
{
    if (str.empty())
    {
        return 0;
    }
    return (str[0] == alvo ? 1 : 0) + recursao(str.substr(1), alvo);
}
