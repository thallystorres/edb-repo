#include <iostream>
#include <chrono>
using namespace std;

// É o seguinte se você tá vindo aqui pra dar uma checada de como resolver essa questão, não se desespera, esse é um algoritmo meio chatinho mesmo de se fazer, mas você não precisa saber fazer ele agora, só entenda que o parâmetro reverse serve como uma flag pra tu dizer se vai ou não ser um sorting reverso

int partition(int vet[], int left, int right, bool reverse)
{
    int pivot = vet[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        bool condition = reverse ? (vet[j] >= pivot) : (vet[j] <= pivot);
        if (condition)
        {
            i++;
            swap(vet[i], vet[j]);
        }
    }

    swap(vet[i + 1], vet[right]);
    return i + 1;
}

void quicksort(int vet[], int left, int right, bool reverse)
{
    if (left < right)
    {
        int pi = partition(vet, left, right, reverse);
        quicksort(vet, left, pi - 1, reverse);
        quicksort(vet, pi + 1, right, reverse);
    }
}

bool isLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int linearSearch(int years[], int yearBirth, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (years[i] > yearBirth && isLeap(years[i]))
        {
            return years[i];
        }
    }
    return -1;
}

int binarySearch(int years[], int yearBirth, int size)
{
    int ip = 0;
    int fp = size - 1;
    int result = -1;
    while (ip <= fp)
    {
        int mid = ip + (fp - ip) / 2;
        if (years[mid] > yearBirth)
        {
            if (isLeap(years[mid]))
            {
                result = years[mid];
                ip = mid + 1;
            }
            else
            {
                ip = mid + 1;
            }
        }
        else
        {
            fp = mid - 1;
        }
    }
    return result;
}

void verifyLeap(int years[], int birthYear, int size)
{
    quicksort(years, 0, size - 1, true);

    auto startseq = std::chrono::high_resolution_clock::now();
    int seq = linearSearch(years, birthYear, size);
    auto endseq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedseq = endseq - startseq;

    auto startbin = std::chrono::high_resolution_clock::now();
    int bin = binarySearch(years, birthYear, size);
    auto endbin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedbin = endbin - startbin;

    cout << "Resultado do Linear Search: " << seq << endl << "Tempo do Linear Search: " << elapsedseq.count() << endl;
    cout << "Resultado do Binary Search: " << bin << endl << "Tempo do Binary Search :" << elapsedbin.count() << endl;
}

int main()
{
    int size = 7;
    int years[size] = {2010, 2004, 1996, 2020, 1980, 2000, 1999};
    verifyLeap(years, 1998, size);
    return 0;
}
