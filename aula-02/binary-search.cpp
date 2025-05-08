#include <iostream>
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

int main()
{
    int size = 8;
    int vet[size] = {2, 5, 8, 12, 16, 23, 38, 56};
    int key;
    cin >> key;
    cout << binarySearch(vet, size, key) << endl;
    return 0;
}
