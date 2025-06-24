#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    for (int i = 1; i < arr.size(); i++)
    {
        int item = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > item){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = item;
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
    
    insertionSort(arr);
    for(int num : arr){
        cout << num << endl;
    }
    return 0;
}
