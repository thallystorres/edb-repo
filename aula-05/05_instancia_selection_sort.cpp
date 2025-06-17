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

// Para o pior caso possível, é preciso que o vetor esteja totalmente fora de ordem
// Crescente (ou seja em ordem crescente), pois dessa forma seram executadas
// O(n²) comparações e O(n) trocas de valores de lugar