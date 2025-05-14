#include <iostream>
using namespace std;

// Modifiquei minimamente a assinatura e funcionamento das funções
// para que se possa passar o a chave bad para os testes

bool isBadVersion(int version, int bad)
{
    return version >= bad;
}

int busca_binaria(int n, int bad)
{
    int left = 1;
    int right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid, bad))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
