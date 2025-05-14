#include <iostream>
#include <chrono>
using namespace std;

int sequencialSearch(int vet[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (vet[i] == key)
            return i;
        else if (vet[i] > key)
            return -i;
    }
    return -1;
}

int tempoSs(int size)
{
    int vet[size];
    for (int i = 0; i < size; i++)
    {
        vet[i] = i;
    }
    int key = size - 1;
    auto start = std::chrono::high_resolution_clock::now();
    sequencialSearch(vet, size, key);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    cout << elapsed.count() << endl;
    return 0;
}
