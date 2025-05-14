#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubblesort(vector<int> &arr, bool reverse = false)
{
    size_t size = arr.size();
    bool swapped;
    for (size_t i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if ((reverse && arr[j] < arr[j + 1]) || (!reverse && arr[j] > arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int partition(vector<int> &arr, int left, int right, bool reverse = false)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        bool condition = reverse ? (arr[j] >= pivot) : (arr[j] <= pivot);
        if (condition)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(vector<int> &arr, int left, int right, bool reverse = false)
{
    if (left < right)
    {
        int pi = partition(arr, left, right, reverse);
        quicksort(arr, left, pi - 1, reverse);
        quicksort(arr, pi + 1, right, reverse);
    }
}

int busca_seq_ordenada(const vector<int> &arr, int key)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        else if (arr[i] > key)
        {
            return -1;
        }
    }
    return -1;
}

int conta_especialidades_distintas(vector<int> &arr)
{
    quicksort(arr, 0, arr.size() - 1, false);
    vector<int> distintos;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (busca_seq_ordenada(distintos, arr[i]) == -1)
        {
            distintos.push_back(arr[i]);
        }
    }

    return distintos.size();
}
