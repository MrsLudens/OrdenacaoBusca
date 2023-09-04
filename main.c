#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickS(int vet[], int esq, int dir){
	
	int pivo=esq;
	int i,ch,j;
	
	for(i=esq+1; i<=dir; i++){
		
		j=i;
		if(vet[j] < vet[pivo]){
			ch=vet[j];
			while(j>pivo){
				vet[j] = vet [j-1];
				j--;
			}
			vet[j] = ch;
			pivo++;
		}
	}
	
	if (pivo-1 > esq){
		quickS(vet, esq, pivo-1);
	}
	if(pivo+1 < dir){
		quickS(vet, pivo+1, dir);
	}
}

void insertionSort(int array[], int tamanho) {
    int i, medio, j;
    for (i = 1; i < tamanho; i++) {
        medio = array[i];
        j = i - 1;

        // Move os elementos do array que são maiores que o medio para uma posição à frente de sua posição atual
        while (j >= 0 && array[j] > medio) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = medio;
    }
}


void imprimirArray(int array[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d \n ", array[i]);
        printf("%d \n ", i);
    }
    printf("\n");
}


int buscaBinaria(int arr[], int tamanho, int elemento) {
   int esquerda = 0;
   int direita = tamanho - 1;
   int meio;

   while (esquerda <= direita) {
      meio = (esquerda + direita) / 2;

      if (arr[meio] == elemento)
         return meio;
      else if (arr[meio] < elemento)
         esquerda = meio + 1;
      else
         direita = meio - 1;
   }

   return -1; // SE O ELEMENTO NÃO EXISTE
}


int buscaLinear(int arr[], int tamanho, int elemento) {
	int i;
   for (i = 0; i < tamanho; i++) {
      if (arr[i] == elemento)
         return i;
   }

   return -1; // SE O ELEMENTO NÃO EXISTE
}

int main(int argc, char *argv[]) {
	
	//ARRAYS
   
	int seqDe50Mil[50000];
	int seqDe60Mil[60000];
	int seqDe70Mil[70000];
	int seqDe80Mil[80000];
	int seqDe90Mil[90000];
	int seqDe100Mil[100000];
	
	//TAMANHO DOS ARRAYS;
	int tamanho50Mil = sizeof(seqDe50Mil) / sizeof(seqDe50Mil[0]);
	int tamanho60Mil = sizeof(seqDe60Mil) / sizeof(seqDe60Mil[0]);
	int tamanho70Mil = sizeof(seqDe70Mil) / sizeof(seqDe70Mil[0]);
	int tamanho80Mil = sizeof(seqDe80Mil) / sizeof(seqDe80Mil[0]);
	int tamanho90Mil = sizeof(seqDe90Mil) / sizeof(seqDe90Mil[0]);
	int tamanho100Mil = sizeof(seqDe100Mil) / sizeof(seqDe100Mil[0]);
	
	//ALGORITMOS PARA O QUICK
	int i, numero1, numero2;
	
	
	//ALGORITMO PRA CALCULAR TEMPO DE EXECUÇÃO
	clock_t inicio,fim;
	double tempo_execucao;
	
	
	
	//ABRINDO ARQUIVO
	FILE *arquivo = fopen("numeros.txt", "r"); // Abrir arquivo com numeros no modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    
    //RETORNANDO AO INICIO DO ARQUIVO
    rewind(arquivo);
    
    
       //	 COLETAR NUMEROS NOS ARRAY //
       
        //COLETAR 50000 NUMEROS
	rewind(arquivo);
	for(i=0; i<50000; i++){
    	
    	fscanf(arquivo, "%d", &numero1);
    	seqDe50Mil[i] = numero1;
	}

	//RESETAR O ARQUIVO
		rewind(arquivo);
       
       
       
     //COLETAR 60000 NUMEROS
    for(i=0; i<60000; i++){
    	
    	fscanf(arquivo, "%d", &numero1);
    	seqDe60Mil[i] = numero1;
	}
	
	//RESETAR O ARQUIVO
	rewind(arquivo);
	
	
	 //COLETAR 70000 NUMEROS
    for(i=0; i<70000; i++){
    	
    	fscanf(arquivo, "%d", &numero1);
    	seqDe70Mil[i] = numero1;
	}
	
	//RESETAR O ARQUIVO
	rewind(arquivo);

 //COLETAR 80000 NUMEROS
    for(i=0; i<80000; i++){
    	
    	fscanf(arquivo, "%d", &numero1);
    	seqDe80Mil[i] = numero1;
	}
	
	//RESETAR O ARQUIVO
	rewind(arquivo);

// COLETAR 90000 NUMEROS
    for(i=0; i<90000; i++){
    	
    	fscanf(arquivo, "%d", &numero1);
    	seqDe90Mil[i] = numero1;
	}
	
	//RESETAR O ARQUIVO
	rewind(arquivo);
	
	
	 //COLETAR 100000 NUMEROS
	for(i=0; i<100000; i++){
    	
    	fscanf(arquivo, "%d", &numero2);
    	seqDe100Mil[i] = numero2;
	}
	
	


    // Fecha o arquivo
    fclose(arquivo);
	
	
//	//-----------IMPRIMIR NUMEROS DESORDENADOS --------------//
//	
//	for(i=0; i<1000; i++){
//		printf("%d\n",seqDeMil[i]);
//	}

//	for(i=0; i<100000; i++){
//		int contagem=1;
//		printf("%d\n",seqDe100Mil[i]);
//		
//		//DEBUG
//		printf(" contagem: %d\n",contagem);
//		contagem++;
//		
//	}

//	for(i=0; i<50000; i++){
//		printf("%d\n",seqDe50Mil[i]);
//	
//	//-----------IMPRIMIR NUMEROS DESORDENADOS --------------//
	
	
	
	//--------------------FAZENDO QUICKSORT---------------------//
	
//	
//	inicio = clock();
//	quickS(seqDe50Mil,0,50000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 50000: %.6f segundos quick \n", tempo_execucao);
//	
//	inicio = clock();
//	quickS(seqDe60Mil,0,60000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 60000: %.6f segundos quick \n", tempo_execucao);
//	
//	inicio = clock();
//	quickS(seqDe70Mil,0,70000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 70000: %.6f segundos quick \n", tempo_execucao);
//	
//	inicio = clock();
//	quickS(seqDe80Mil,0,80000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 80000: %.6f segundos quick \n", tempo_execucao);
//	
//	inicio = clock();
//	quickS(seqDe90Mil,0,90000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 90000: %.6f segundos quick \n", tempo_execucao);
//
//	inicio = clock();
//	quickS(seqDe100Mil,0,100000);
//	fim = clock();
//	
//	tempo_execucao = (double)(fim-inicio) / CLOCKS_PER_SEC;
//	printf("Tempo de execucao 10000: %.6f segundos quick \n", tempo_execucao);

	
	//--------------------FAZENDO QUICKSORT---------------------//
	
	
	
	// ---------- FAZENDO O InsertionSort ----------//
	
	inicio = clock();
    insertionSort(seqDe50Mil, tamanho50Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 50000: %.6f segundos Insertion\n", tempo_execucao);
	 
	 
	inicio = clock();
    insertionSort(seqDe60Mil, tamanho60Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 60000: %.6f segundos Insertion\n", tempo_execucao);
	 
	 
	 inicio = clock();
    insertionSort(seqDe70Mil, tamanho70Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 70000: %.6f segundos Insertion\n", tempo_execucao);
	 
	 
	 inicio = clock();
    insertionSort(seqDe80Mil, tamanho80Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 80000: %.6f segundos Insertion\n", tempo_execucao);
	 
	 
	 inicio = clock();
    insertionSort(seqDe90Mil, tamanho90Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 90000: %.6f segundos Insertion\n", tempo_execucao);
	 
	 
	 
	inicio = clock();
    insertionSort(seqDe100Mil, tamanho100Mil);
    fim = clock();
	
	 tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
	 
	 printf("Tempo de execucao 100000: %.6f segundos Insertion\n", tempo_execucao);
	
	
// --------------------- PRINT DO ARRAY  ORDENADO INSERTION ------------//
//    imprimirArray(array50Mil, tamanho);
	
//-------------IMPRIMIR NUMEROS ORDENADOS------------------//
	
//	printf("NUMERO DESEMBARALHADOS:");
	
//	for(i=0; i<1000; i++){
//		printf("%d\n",seqDeMil[i]);
//	}
//	
//	
//	int contagem=1;
//	for(i=0; i<10000; i++){
//		printf("%d\n",seqDeDezMil[i]);
//		
//		//DEBUG
//		printf(" contagem: %d\n",contagem);
//		contagem++;
//		
//	}
	
		//-------------IMPRIMIR NUMEROS ORDENADOS------------------//
		
		
		//---------------BUSCA BINÁRIA ---------------//
//		int elemento = 76996; // elemento buscado
//		
//		inicio = clock();
//		int indice1 = buscaBinaria(seqDe50Mil, tamanho50Mil, elemento); // elemento que retorna
//		fim = clock();
//		
//		tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
//		printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);
//		
//		if (indice1 != -1){
//			printf("Elemento encontrado no índice %d.\n", indice1);
//		}
//  		 else{
//  		 	printf("Elemento não encontrado.\n");
//		   }
      	//---------------BUSCA BINÁRIA ---------------//
      	
//      	int indice2 = buscaLinear(seqDe50Mil, tamanho50Mil, elemento);
//		
//		if (indice2 != -1)
//      printf("Elemento encontrado no índice %d.\n", indice2);
//   else
//      printf("Elemento não encontrado.\n");

		
		
	return 0;
}
