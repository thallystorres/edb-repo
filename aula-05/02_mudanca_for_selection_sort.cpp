#include <iostream>
using namespace std;

void selectionsort(int n, int v[])
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (v[j] < v[min])
                min = j;
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

void selectionsortInicialDiferente(int n, int v[])
{
    for (int i = 1; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (v[j] < v[min])
                min = j;
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

void selectionsortFinalDiferente(int n, int v[])
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (v[j] < v[min])
                min = j;
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Quantos elementos terá em sua lista?" << endl;
    cin >> n;
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    selectionsort(n, v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    delete[] v;
    return 0;
}

// Caso o for da função de sorting iniciar com 1 em vez de 0
// O primeiro elemento será desconsiderado, então caso um input seja:
// >> 123312312
// >> 12
// >> 34
// >> -22
// >> 2
// O resultado final será: {123312312, -22, 2, 12, 34}
// E não {-22, 2, 12, 34, 123312312}

// Já caso o for da função de sorting terminar com n em vez de n - 1
// O programa irá fazer uma iteração a mais em um slot de memória que não
// Corresponde a nenhum espaço do array, levando a uma iteração inútil
// Gastando memória mas sem perigo de deflagrar erro
