#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100000

int binSearch(unsigned long long arr[TAM], int l, int r, int x, int *counter)
{
  while (l < r)
  {
    (*counter)++;

    int m = l + (r - l) / 2;

    if (arr[m] == x)
      return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }

  int m = l + (r - l) / 2;

  if (arr[m] == x)
    return m;

  return -1;
}

void seqSearch(int data, char *nameFile, int sort){
  char final[256];

  if(sort == 0){ // caso não for ordenado
    sprintf(final, "%s%s", nameFile, ".txt");
  } else { // caso for ordenado
    sprintf(final, "%s%s", nameFile, "-sort.txt");
  }
  //printf("\nArquivo: %s", final);
  //printf("\nDADO A BUSCAR: %d", data);

  FILE *arqDados;
  char *dado = malloc(sizeof(dado));

  clock_t t;
  t = clock(); // Contagem do tempo começa
  //Código de vocês

  if ((arqDados = fopen(final, "r")) == NULL)
  {
    printf("\nErro na abertura do arquivo");
    return;
  }

  int count = 0;

  while (!feof(arqDados))
  {
    fgets(dado, 11, arqDados);

    int valDado = atoi(dado);
    
    //printf("%s", dado);
    if(valDado == data){
      break;
    }
    count++;
  }
  //printf("\nResultados: %d", count);

  fclose(arqDados);
  free(dado);

  t = clock() - t; // Contagem do tempo termina.
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  // calcula o tempo
  

  if(sort == 0){ // caso não for ordenado
    printf("seqSearch: tempo=%.0fs, comp=%d\n", time_taken, count/2);
  } else { // caso for ordenado
    printf("seqSearchSort: tempo=%.0fs, comp=%d\n", time_taken, count/2);
  }

}

void binSearchMain(int data, char *nameFile){
  char input[20];
  unsigned long long arr[TAM];

  int pos = 0;

  char final[256];
  sprintf(final, "%s%s", nameFile, "-sort.txt");
  FILE *arquivo = fopen(final, "r");

  while (pos < TAM)
  {
    char *line = fgets(input, sizeof(input), arquivo);

    arr[pos] = atoi(line);

    pos++;
  }

  clock_t t;
  t = clock(); // Contagem do tempo começa

  int var = 0;
  int *counter = &var;

  int x = 72080; // valor a buscar
  int result = binSearch(arr, 0, TAM - 1, x, counter);

  t = clock() - t; // Contagem do tempo termina.  
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  if(result == -1) printf("\nValor nao encontrado");

  printf("binSearch: tempo=%.0fs, comp=%d\n", time_taken, *counter);
  //printf("binSearch: tempo=%.0fs, comp=\n", time_taken);
}

int main()
{

  char arquivo[256] = "1M";

  seqSearch(1227630213, arquivo, 0); // não ordenada

  seqSearch(1227630213, arquivo, 1); // ordenada

  binSearchMain(1227630213, arquivo);

  return 0;
}

