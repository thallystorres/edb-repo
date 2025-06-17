#include <iostream>
#include <vector>
using namespace std;

int minIndex(vector<int> &arr, int i, int j)
{
    if (i == j)
        return i;
    int k = minIndex(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

void recursiveSelectionSort(vector<int> &arr, int index = 0)
{
    if (index == arr.size())
        return;
    int k = minIndex(arr, index, arr.size() - 1);
    if (k != index)
        swap(arr[k], arr[index]);

    recursiveSelectionSort(arr, index + 1);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {};
    while (true)
    {
        int input;
        cin >> input;
        if(input == -1) break;
        arr.push_back(input);
    }
    recursiveSelectionSort(arr);
    for(int num : arr){
        cout << num << endl;
    }
    return 0;
}
