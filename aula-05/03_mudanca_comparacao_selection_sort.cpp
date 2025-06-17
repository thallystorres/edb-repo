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

void mudandoComparacaoSelectionsort(int n, int v[])
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (v[j] <= v[min])
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
    mudandoComparacaoSelectionsort(n, v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    delete[] v;
    return 0;
}

// Analisando ações teóricas e empíricas é possível chegar na conclusão
// Que, para ordenamento de valores numéricos, pouco importa a mudança
// De < para <=, visto que os valores ordenados que são semelhantes
// Não precisam ser trocados de lugar, porém quando há uma certa
// Complexidade nos dados do algoritmo a ser analisado, é possível que
// A comparação com <= não seja a mais vantajosa, visto que pode afetar
// Outras métricas que não podem ser levadas em conta apenas com a ordenação
// Numérica