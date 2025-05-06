#include <iostream>
using namespace std;

int sumNaturals(int k) {
    if (k == 0) return 0;
    else return k + sumNaturals(k-1);
}

int main(int argc, char const *argv[])
{
    cout << (sumNaturals(4)) << endl;
    return 0;
}
