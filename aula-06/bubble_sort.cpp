#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        bool is_sorted = true;
        for (size_t j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                is_sorted = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (is_sorted)
            return;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    while (true)
    {
        int input = 0;
        cin >> input;
        if(input == -666) break;
        arr.push_back(input);
    }
    
    bubbleSort(arr);
    for(int num : arr){
        cout << num << endl;
    }
    return 0;
}
