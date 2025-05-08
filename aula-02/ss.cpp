#include <iostream>
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
int main()
{
    int n = 6;
    int c[n] = {13, 14, 15, 16, 17, 18};
    int key = 15;
    cout << sequencialSearch(c, n, key) << endl;
    return 0;
}
