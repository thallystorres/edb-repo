#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    auto length = arr.size();
    for (size_t i = 0; i < length; i++)
    {
        int min_idx = i;
        for (size_t j = i + 1; j < length; j++)
        {
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
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
    selectionSort(arr);
    for(int num : arr){
        cout << num << endl;
    }
    return 0;
}
