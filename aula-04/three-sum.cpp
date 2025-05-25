#include <iostream>
#include <vector>
using namespace std;

bool worstWay(vector<int>& arr, int key)
{
    for(int i : arr)
    {
        for(int j : arr)
        {
            for(int k : arr)
            {
                if(i + j + k == key)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool binarySearch(vector<int>& arr, int key)
{
    int ip = 0;
    int fp = arr.size() - 1;
    while (ip <= fp)
    {
        int mid = ip + (fp - ip) / 2;
        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] < key)
        {
            ip = mid + 1;
        } else
        {
            fp = mid - 1;
        }
    }
    return false;
}

bool betterWay(vector<int>& arr, int key)
{
    for(int i: arr)
    {
        for(int j: arr)
        {
            if (binarySearch(arr, key - i - j))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> teste = {0, 4, 7, 9, 10, 13, 20, 27};
    cout << betterWay(teste, 14) << endl;
    return 0;
}
