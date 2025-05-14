#include <iostream>
#include <iomanip>
#include <vector>
#include "busca_seq_ordenada.hpp"
#include "busca_binaria.hpp"
#include "recursao.hpp"
using namespace std;

#define RUN_TEST(name, expr, expected)                           \
    do                                                           \
    {                                                            \
        int result = (expr);                                     \
        cout << left << setw(25) << name                         \
             << ": " << ((result == (expected)) ? "OK" : "FAIL") \
             << endl;                                            \
    } while (0)

int main()
{
    // Vetor desordenado <POPULAR>
    vector<int> arr1 = {4, 2, 1, 4, 2, 1};
    // Vetor ordenado <POPULAR>
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8};

    // Eexemplo de chamada da macro RUN_TEST
    // RUN_TEST("Titulo do teste", nome_da_funcao(entradas das funcao), resposta_esperada);
    RUN_TEST("Busca binaria 5", busca_binaria(5, 4), 4);
    RUN_TEST("Busca binaria 100000", busca_binaria(100000, 10), 10);
    RUN_TEST("Busca desordenada", conta_especialidades_distintas(arr1), 3);
    RUN_TEST("Busca ordenada", conta_especialidades_distintas(arr2), 8);
    RUN_TEST("Recursiva a", recursao("banana", 'a'), 3);
    RUN_TEST("Recursiva b", recursao("banana", 'b'), 1);
    RUN_TEST("Recursiva n", recursao("banana", 'n'), 2);

    return 0;
}
