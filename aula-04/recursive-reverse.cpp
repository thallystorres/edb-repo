#include <iostream>
using namespace std;

void recursiveReverse(char *str, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return;

    }
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    recursiveReverse(str, inicio + 1, fim - 1);
}

void reverse(char *str)
{
    int tamanho = 0;
    while (str[tamanho] != '\0')
    {
        tamanho++;
    }
    recursiveReverse(str, 0, tamanho - 1);
    
}
int main()
{
    char teste[] = "ABCDEFgh";
    reverse(teste);
    cout << teste << endl;
    return 0;
}
