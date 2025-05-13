#include <stdio.h>
#include "busca_seq_ordenada.h"
#include "busca_binaria.h"
#include "recursao.h"

#define RUN_TEST(name, expr, expected)                               \
    do {                                                             \
        int result = (expr);                                         \
        printf("%-25s : %s\n", name,                                  \
               (result == (expected)) ? "OK" : "FAIL");              \
    } while(0)

int main() {
    //Vetor desordenado <POPULAR>
    int arr1[] = {};
    //Tamanho do vetor <ALTERAR>
    int n1 = 0;

    //Vetor ordenado <POPULAR>
    int arr2[] = {};
    //Tamanho do vetor <ALTERAR>
    int n2 = 0;


    //Eexemplo de chamada da macro RUN_TEST
    //RUN_TEST("Titulo do teste", nome_da_funcao(entradas da funcao), resposta_esperada);
    RUN_TEST("Busca ordenada", conta_especialidades_distintas(), 0);
    RUN_TEST("Busca binaria", busca_binaria(), 0);
    RUN_TEST("Recursao", recursao(), 0);

    return 0;
}
