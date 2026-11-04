#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* O objetivo é investigar experimentalmente o comportamento dos algoritmos
BubbleSort, QuickSort, MergeSort e HeapSort; em diferentes cenários de
entrada, analisando desempenho, escalabilidade, consumo de recursos e
características dos algoritmos
*/

// Implementação vetores

void gera_aleatorio(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = i + 1; // Substituído += por = (evita lixo de memória)
    }
    // Embaralha usando Fisher-Yates
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void gera_crescente(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = i + 1; // Substituído += por =
    }
}

void gera_decrescente(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = n - i; // Lógica corrigida para não pular o índice 0 e gerar ordem reversa
    }
}

void gera_alliguais(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = 67;
    }
}

void gera_poucosiguais(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % 10;
    }
}

// Entrada

int *copiar_vetor(const int *origem, int n)
{
    int *copia = (int *)malloc(n * sizeof(int));
    if (copia != NULL)
    {
        memcpy(copia, origem, n * sizeof(int));
    }
    return copia;
}

int validar_ord(const int *vetor, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
        {
            return 0; // nao ordenado
        }
    }
    return 1;
}

int main()
{
    srand(42);

    int tamanhos[] = {100, 1000, 10000, 100000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    int n = tamanhos[0];
    int *vetor_original = (int *)malloc(n * sizeof(int));

    printf("A gerar vetor aleatorio com %d elementos...\n", n);
    gera_aleatorio(vetor_original, n);

    int *vetor_para_teste = copiar_vetor(vetor_original, n);

    // Como o vetor gerado é aleatório e ainda não passamos nenhum algoritmo
    // de ordenação, a validação abaixo deve cair no "Erro!" intencionalmente.
    if (validar_ord(vetor_para_teste, n))
    {
        printf("Validacao: O vetor foi ordenado com sucesso!\n");
    }
    else
    {
        printf("Validacao: Erro! O vetor nao esta ordenado.\n");
    }

    free(vetor_para_teste);
    free(vetor_original);

    return 0;
}