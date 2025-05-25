#include <iostream>
#include <vector>
using namespace std;

int findPeak(const vector<int> &arr)
{
    int ip = 0;
    int fp = arr.size() - 1;
    while (ip < fp)
    {
        int mid = ip + (fp - ip) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            ip = mid + 1;
        }
        else
        {
            fp = mid;
        }
    }
    return ip;
}

int binarySearch(const vector<int> &arr, int X, int ip, int fp)
{
    while (ip <= fp)
    {
        int mid = ip + (fp - ip) / 2;
        if(arr[mid] < X)
        {
            ip = mid + 1;
        }
        else if(arr[mid] > X)
        {
            fp = mid - 1;
        }
        else if(arr[mid] == X)
        {
            return mid;
        }
    }
    return -1;
}

int reverseBinarySearch(const vector<int> &arr, int X, int ip, int fp)
{
    while (ip <= fp)
    {
        int mid = ip + (fp - ip) / 2;
        if(arr[mid] > X)
        {
            ip = mid + 1;
        }
        else if(arr[mid] < X)
        {
            fp = mid - 1;
        }
        else if(arr[mid] == X)
        {
            return mid;
        }
    }
    return -1;
}

int bitonicSearch(const vector<int> &arr, int X)
{
    int peak = findPeak(arr);
    int resultado = binarySearch(arr, X, 0, peak);
    if (resultado != -1)
    {
        return resultado;
    }
    resultado = reverseBinarySearch(arr, X, peak, arr.size() - 1);
    return resultado;
}

int main()
{
    vector<int> arr = {10, 11, 12, 90, 80, 70, 60, 50, 4, 3, 2};
    cout << bitonicSearch(arr, 50) << endl;
    return 0;
}
