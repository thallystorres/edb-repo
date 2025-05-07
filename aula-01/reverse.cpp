#include <iostream>
#include <string>
using namespace std;

string reverse(string a) {
    if (a.empty()) return "";
    else return reverse(a.substr(1)) + a[0];
}

int main(int argc, char const *argv[])
{
    string a;
    cin >> a;
    cout << reverse(a) << endl;
    return 0;
}
