
# Explicação do Algoritmo

## Iniciando com a declaração de bibliotecas padrão e uso do namespace `std`

```cpp
#include <iostream>
#include <chrono>
using namespace std;
```

## Algoritmo de ordenação

```cpp
// Função para particionar o vetor
int partition(int vet[], int left, int right, bool reverse)
{
    int pivot = vet[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        bool condition = reverse ? (vet[j] >= pivot) : (vet[j] <= pivot);
        if (condition)
        {
            i++;
            swap(vet[i], vet[j]);
        }
    }

    swap(vet[i + 1], vet[right]);
    return i + 1;
}

// Algoritmo de quicksort divide and conquer
void quicksort(int vet[], int left, int right, bool reverse)
{
    if (left < right)
    {
        int pi = partition(vet, left, right, reverse);
        quicksort(vet, left, pi - 1, reverse);
        quicksort(vet, pi + 1, right, reverse);
    }
}
```

Nesse algoritmo de sorting simples, eu uso QuickSort para um approach mais rápido na completude do exercício.  
Você basicamente vai remontar um subarray ordenando os elementos em maior ou menor que o pivô selecionado (função `partition`).

Após isso, aplicamos um algoritmo de divide and conquer (DC), baseado na separação de subvetores em vetores e ordená-los recursivamente.

Vale salientar que a função `quicksort` aplicada possui uma funcionalidade de `reverse`, então tu pode inverter ou não como você quer ordenar teu vetor.

## Verificador de ano bissexto

```cpp
bool isLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
```

Boe, sinceramente, isso aqui é mais saber a definição de um ano bissexto e passar pro código, você provavelmente entendeu essa parte.

## Linear Search

```cpp
int linearSearch(int years[], int yearBirth, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (years[i] > yearBirth && isLeap(years[i]))
        {
            return years[i];
        }
    }
    return -1;
}
```

Com tempo médio de execução O(n), esse algoritmo, por conseguir lidar bem com tipos de ordenação inversa (e até sem ordenação), é o mais adequado para solucionar o problema!

Aliás, para a lógica de verificação da key, eu mesclei um pouco com a verificação de ano bissexto.

## Binary Search

```cpp
int binarySearch(int years[], int yearBirth, int size)
{
    int ip = 0;
    int fp = size - 1;
    int result = -1;
    while (ip <= fp)
    {
        int mid = ip + (fp - ip) / 2;
        if (years[mid] > yearBirth)
        {
            if (isLeap(years[mid]))
            {
                result = years[mid];
                ip = mid + 1;
            }
            else
            {
                ip = mid + 1;
            }
        }
        else
        {
            fp = mid - 1;
        }
    }
    return result;
}
```

Mesmo com tempo médio de execução superior ao `Linear Search`, O(log n), não se sai muito bem quando o input é ordenado de forma não convencional.  
Mais tarde eu posso refazer o algoritmo para ele funcionar direcionadamente para vetores em ordenação inversa.

## Verificação

```cpp
void verifyLeap(int years[], int birthYear, int size)
{
    quicksort(years, 0, size - 1, true);

    auto startseq = std::chrono::high_resolution_clock::now();
    int seq = linearSearch(years, birthYear, size);
    auto endseq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedseq = endseq - startseq;

    auto startbin = std::chrono::high_resolution_clock::now();
    int bin = binarySearch(years, birthYear, size);
    auto endbin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedbin = endbin - startbin;

    cout << "Resultado do Linear Search: " << seq << endl << "Tempo do Linear Search: " << elapsedseq.count() << endl;
    cout << "Resultado do Binary Search: " << bin << endl << "Tempo do Binary Search: " << elapsedbin.count() << endl;
}
```

> **CALMA!!!**  
> Eu sei que tá feio, mas isso tudo é só pra calcular o tempo de cada algoritmo e printar seus resultados.  
> Não é tão complexo assim, só tá feio (porque eu tô com preguiça de fazer mais bonitinho :P)

Aqui ordenamos o vetor de forma inversa, depois tiramos a prova de como os algoritmos se saem.  
(**SPOILER:** binary search falhou >:( )

```cpp
int main()
{
    int size = 7;
    int years[size] = {2010, 2004, 1996, 2020, 1980, 2000, 1999};
    verifyLeap(years, 1998, size);
    return 0;
}
```

Testando aqui, vemos que as saídas vão ser semelhantes a:

```bash
Resultado do Linear Search: 2020
Tempo do Linear Search: 0.000178
Resultado do Binary Search: 2000
Tempo do Binary Search :0.000128
```

Levando em conta que a resposta certa seria **2020**, por que o BS está dando uma resolução errada?

É simples: ele não foi feito pra trabalhar com ordenações fora do seu padrão!  
Esse é o ponto de toda a tarefa: mostrar que não existe um **melhor que o outro**, existe apenas um algoritmo que é melhor **NAQUELA SITUAÇÃO ESPECÍFICA**!!

Ademais, é possível ver que a diferença no tempo de execução entre os dois é bem insignificante, né?  
Então, às vezes, nem sempre o mais performático é o melhor pra situação.

Vejamos que o mais performático aqui seria o BS, porém ele **não só deu uma resposta errada** como também **não deu um aumento de tempo significativo**.

## Próximos passos

Agora, o que podemos fazer pra melhorar isso?  
Bem, o primeiro a se fazer é procurar uma forma melhor de escrever esse código — fiz nas pressas, tá feio demais boe!

Mas fora isso, é bom melhorar o algoritmo de busca binária, algo como aceitar diferentes formas de inputs com base em suas ordenações.  
Fica de tarefa de casa pra você, leitor :P