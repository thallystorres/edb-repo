#include <iostream>
using namespace std;

int recursiveMultiplication(int a, int b){
    if (a == 0 || b == 0) return 0;
    else return a + recursiveMultiplication(a, b-1);
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << recursiveMultiplication(a,b) << endl;
    return 0;
}
