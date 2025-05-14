#include <iostream>
#include <chrono>
using namespace std;

int binarySearch(int vet[], int size, int key)
{
    int ip = 0;
    int fp = size - 1;
    int mid;
    while (ip <= fp)
    {
        mid = int((fp + ip) / 2);
        if (vet[mid] > key)
        {
            fp = mid - 1;
        }
        else if (vet[mid] < key)
        {
            ip = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int tempoBs(int size)
{
    int vet[size];
    for (int i = 0; i < size; i++)
    {
        vet[i] = i;
    }
    int key = size - 1;
    auto start = std::chrono::high_resolution_clock::now();
    binarySearch(vet, size, key);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    cout << elapsed.count() << endl;
    return 0;
}
