#include <iostream>
using namespace std;

int recursiveBinarySearch(int vet[], int size, int key, int left, int right)
{
    if (key < vet[left] || key > vet[right] || left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (vet[mid] < key)
        return recursiveBinarySearch(vet, size, key, mid + 1, right);
    else if (vet[mid] > key)
        return recursiveBinarySearch(vet, size, key, left, mid - 1);
    else
        return mid;
}

int main()
{
    int size = 8;
    int vet[size] = {2, 5, 8, 12, 16, 23, 38, 56};
    int key;
    cin >> key;
    cout << recursiveBinarySearch(vet, size, key, 0, size - 1) << endl;
    return 0;
}
