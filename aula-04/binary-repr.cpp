#include <iostream>
#include <string>
using namespace std;

string binaryRepr(int number)
{
    if (number == 0)
    {
        return "0";
    }
    string binary = "";
    while (number > 0)
    {
        int bit = number % 2;

        binary = (bit == 0 ? "0" : "1") + binary;
        number /= 2;
    }
    return binary;
}

string recursiveBinaryRepr(int number)
{
    if (number == 0) return "0";
    if (number == 1) return "1";

    return recursiveBinaryRepr(number / 2) + to_string(number % 2);
}

int main()
{
    cout << recursiveBinaryRepr(25) << endl;
    return 0;
}
