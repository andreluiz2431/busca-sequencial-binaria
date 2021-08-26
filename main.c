#include <stdio.h>
#include <time.h>

void seqSearch(char *data, char *nameFile, int sort){
  char final[256];

  if(sort == 0){ // caso não for ordenado
    sprintf(final, "%s%s", nameFile, ".txt");
  } else { // caso for ordenado
    sprintf(final, "%s%s", nameFile, "-sort.txt");
  }
  //printf("\nArquivo: %s", final);
  printf("\nDADO A BUSCAR: %s", data);

  FILE *arqDados;
  char *dado = malloc(sizeof(dado));;

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
    fgets(dado, 10, arqDados);
    
    //printf("%s", dado);
    if(dado == data){
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
  
  printf("\nseqSearch: tempo=%.0fs, comp=%d\n", time_taken, count);

}

//void seqSearchSort(char data, char *nameFile){}

void binSearch(char data, char *nameFile){}

int main()
{

  seqSearch("1227630213", "1M", 0); // não ordenada

  //seqSearch("1227630213", "1M", 1); // ordenada

  return 0;
}