#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int valor(char c)
{
	if(c == '.')
		return 1;
	if(c == 'M')
		return 100;
	if(c == 'R')
		return 5;
	if(c == 'F')
		return 0;
	if(c == 'I')
		return 0;
}

typedef struct lista
{
    int listai;
    int listaj;
}LISTA;

typedef struct anterior
{
    int i;
    int j;
}ANTERIOR;



void dist_filho(char mapa[40][82], int fim[2], int pUso1, int pUso2, int val_mapa[40][82], int dist_perc[40][82], unsigned int *teste2, LISTA *listanum, int visitado_mapa[40][82], ANTERIOR ant[40][82])
{
	int pAtual[2], comp[3], teste[2], calculo1, calculo2, dist, temp, passo;
	pAtual[0] = pUso1;
	pAtual[1] = pUso2;
	int o = 0, i, j=0;
	unsigned int contador = *teste2;
	
	if(visitado_mapa[pAtual[0]][pAtual[1]] == 0)
	{
		while(o <= 0)
		{
			o = 0;
			j=0;
			if(pAtual[0] - 1 > -1)
			{
				calculo1 = abs(fim[0] - pAtual[0]-1);
				calculo2 = abs(fim[1] - pAtual[1]);
				temp = valor(mapa[pAtual[0] - 1][pAtual[1]]);
				passo = dist_perc[pAtual[0]][pAtual[1]] + temp;
				dist = calculo1 + calculo2 + passo;
				if(dist < val_mapa[pAtual[0]-1][pAtual[1]])
				{
					val_mapa[pAtual[0]-1][pAtual[1]] = dist;
					dist_perc[pAtual[0]-1][pAtual[1]] = passo;
					visitado_mapa[pAtual[0]-1][pAtual[1]] = 0;
					for(i=0;i<contador;i++)
					{
						if((listanum[i].listai == pAtual[0] - 1) && (listanum[i].listaj == pAtual[1]))
						{
							j=1;
							
						}
						
					}
					if(j==0)
					{
						
						
						contador++;
						listanum = (LISTA*) realloc(listanum, contador * sizeof(LISTA));
						if (listanum == NULL)
						{
				  			printf("N?o foi poss?vel alocar mem?ria!\n");
				 			exit(1);
						}
						listanum[contador-1].listai = pAtual[0] - 1;
						listanum[contador-1].listaj = pAtual[1];
						
					}
					ant[pAtual[0]-1][pAtual[1]].i = pAtual[0];
					ant[pAtual[0]-1][pAtual[1]].j = pAtual[1];
				}
				if(val_mapa[pAtual[0]][pAtual[1]] > abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]-1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]))
				{
					val_mapa[pAtual[0]][pAtual[1]] = abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]-1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]);
					dist_perc[pAtual[0]][pAtual[1]] = dist_perc[pAtual[0]-1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]);
					ant[pAtual[0]][pAtual[1]].i = pAtual[0]-1;
					ant[pAtual[0]][pAtual[1]].j = pAtual[1];
					o = -6;
				}
				o++;
			}
			if(pAtual[0] + 1 < 40)
			{
				j=0;
				calculo1 = abs(fim[0] - pAtual[0]+1);
				calculo2 = abs(fim[1] - pAtual[1]);
				temp = valor(mapa[pAtual[0] + 1][pAtual[1]]);
				passo = dist_perc[pAtual[0]][pAtual[1]] + temp;
				dist = calculo1 + calculo2 + passo;
				if(dist < val_mapa[pAtual[0]+1][pAtual[1]])
				{
					val_mapa[pAtual[0]+1][pAtual[1]] = dist;
					dist_perc[pAtual[0]+1][pAtual[1]] = passo;
					visitado_mapa[pAtual[0]+1][pAtual[1]] = 0;
					for(i=0;i<contador;i++)
					{
						if((listanum[i].listai == pAtual[0] + 1) && (listanum[i].listaj == pAtual[1]))
						{
							j=1;
							
						}
					}
					if(j==0)
					{
						
						
						contador++;
						listanum = (LISTA*) realloc(listanum, contador * sizeof(LISTA));
						if (listanum == NULL)
						{
				  			printf("N?o foi poss?vel alocar mem?ria!\n");
				 			exit(1);
						}
						listanum[contador-1].listai = pAtual[0] + 1;
						listanum[contador-1].listaj = pAtual[1];
						
					}
					ant[pAtual[0]+1][pAtual[1]].i = pAtual[0];
					ant[pAtual[0]+1][pAtual[1]].j = pAtual[1];
				}
				if(val_mapa[pAtual[0]][pAtual[1]] > abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]+1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]))
				{
					val_mapa[pAtual[0]][pAtual[1]] = abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]+1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]);
					dist_perc[pAtual[0]][pAtual[1]] = dist_perc[pAtual[0]+1][pAtual[1]] + valor(mapa[pAtual[0]][pAtual[1]]);
					ant[pAtual[0]][pAtual[1]].i = pAtual[0]+1;
					ant[pAtual[0]][pAtual[1]].j = pAtual[1];
					o = -6;
				}
				o++;
			}
			if(pAtual[1] - 1 > -1)
			{
				j=0;
				calculo1 = abs(fim[0] - pAtual[0]);
				calculo2 = abs(fim[1] - pAtual[1] - 1);
				temp = valor(mapa[pAtual[0]][pAtual[1] - 1]);
				passo = dist_perc[pAtual[0]][pAtual[1]] + temp;
				dist = calculo1 + calculo2 + passo;
				if(dist < val_mapa[pAtual[0]][pAtual[1]-1])
				{
					val_mapa[pAtual[0]][pAtual[1]-1] = dist;
					dist_perc[pAtual[0]][pAtual[1]-1] = passo;
					visitado_mapa[pAtual[0]][pAtual[1]-1] = 0;
					for(i=0;i<contador;i++)
					{
						if((listanum[i].listai == pAtual[0]) && (listanum[i].listaj == pAtual[1]-1))
						{
							j=1;
							
						}
					}
					if(j==0)
					{
						
						contador++;
						listanum = (LISTA*) realloc(listanum, contador * sizeof(LISTA));
						if (listanum == NULL)
						{
				  			printf("N?o foi poss?vel alocar mem?ria!\n");
				 			exit(1);
						}
						listanum[contador-1].listai = pAtual[0];
						listanum[contador-1].listaj = pAtual[1] - 1;
						
					}
					ant[pAtual[0]][pAtual[1]-1].i = pAtual[0];
					ant[pAtual[0]][pAtual[1]-1].j = pAtual[1];
				}
				if(val_mapa[pAtual[0]][pAtual[1]] > abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]][pAtual[1]-1] + valor(mapa[pAtual[0]][pAtual[1]]))
				{
					val_mapa[pAtual[0]][pAtual[1]] = abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]][pAtual[1]-1] + valor(mapa[pAtual[0]][pAtual[1]]);
					dist_perc[pAtual[0]][pAtual[1]] = dist_perc[pAtual[0]][pAtual[1]-1] + valor(mapa[pAtual[0]][pAtual[1]]);
					ant[pAtual[0]][pAtual[1]].i = pAtual[0];
					ant[pAtual[0]][pAtual[1]].j = pAtual[1]-1;
					o=-6;
				}
				o++;
			}
			if(pAtual[1] + 1 < 82)
			{
				j=0;
				calculo1 = abs(fim[0] - pAtual[0]);
				calculo2 = abs(fim[1] - pAtual[1] + 1);
				temp = valor(mapa[pAtual[0]][pAtual[1] + 1]);
				passo = dist_perc[pAtual[0]][pAtual[1]] + temp;
				dist = calculo1 + calculo2 + passo;
				if(dist < val_mapa[pAtual[0]][pAtual[1]+1])
				{
					val_mapa[pAtual[0]][pAtual[1]+1] = dist;
					dist_perc[pAtual[0]][pAtual[1]+1] = passo;
					visitado_mapa[pAtual[0]][pAtual[1]+1] = 0;
					for(i=0;i<contador;i++)
					{
						if((listanum[i].listai == pAtual[0]) && (listanum[i].listaj == pAtual[1]+1))
						{
							j=1;
						}
					}
					if(j==0)
					{
						
						
						contador++;
						listanum = (LISTA*) realloc(listanum, contador * sizeof(LISTA));
						if (listanum == NULL)
						{
				  			printf("N?o foi poss?vel alocar mem?ria!\n");
				 			exit(1);
						}
						listanum[contador-1].listai = pAtual[0];
						listanum[contador-1].listaj = pAtual[1] + 1;
					}
					ant[pAtual[0]][pAtual[1]+1].i = pAtual[0];
					ant[pAtual[0]][pAtual[1]+1].j = pAtual[1];
				}
				if(val_mapa[pAtual[0]][pAtual[1]] > abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]][pAtual[1]+1] + valor(mapa[pAtual[0]][pAtual[1]]))
				{
					val_mapa[pAtual[0]][pAtual[1]] = abs(fim[0] - pAtual[0]) + abs(fim[1] - pAtual[1]) + dist_perc[pAtual[0]][pAtual[1]+1] + valor(mapa[pAtual[0]][pAtual[1]]);
					dist_perc[pAtual[0]][pAtual[1]] = dist_perc[pAtual[0]][pAtual[1]+1] + valor(mapa[pAtual[0]][pAtual[1]]);
					ant[pAtual[0]][pAtual[1]].i = pAtual[0];
					ant[pAtual[0]][pAtual[1]].j = pAtual[1]+1;
					o=-6;
				}
				o++;
			}
		}
		
	}
	
	
	*teste2 = contador;
	
	return;
}


int main()
{
	clock_t t;
    t = clock();
	FILE *arq;
	arq = fopen("maze_lab_grafos_T03.txt", "rt");
	char mapa[40][82];
	char caracter;
	int i, j;
	int ini[2], fim[2];
	if (arq == NULL)
	{
	    printf("Problemas na abertura do arquivo\n");
	    fclose(arq);
	    return 0;
	}
	for(i=0;i<40;i++)
	{
		for(j=0;j<82;j++)
		{
			caracter = getc(arq);
			if(caracter == '\n')
				caracter = getc(arq);
			mapa[i][j] = caracter;
			if(mapa[i][j] == 'I')
			{
				ini[0] = i;  
				ini[1] = j;
			}
			if(mapa[i][j] == 'F')
			{
				fim[0] = i;  
				fim[1] = j;
			}
		}
		caracter = getc(arq);
	}
	for(i=0;i<40;i++)
	{
		for(j=0;j<82;j++)
		{
			printf("%c", mapa[i][j]);
		}
		printf("\n");
	}
	
	fclose(arq);
	int pAtual[2], comp[3], teste[2], z=1, calculo1, calculo2, dist, temp, passo, soma = 0, anterior[2], teste4;
	unsigned int contador=1;
	int val_mapa[40][82], visitado_mapa[40][82], dist_perc[40][82];
	for(i=0;i<40;i++)
	{
		for(j=0;j<82;j++)
		{
			val_mapa[i][j] = 999999;
			visitado_mapa[i][j] = 0;
			dist_perc[i][j] = 0;
		}
	}
	pAtual[0] = ini[0];
	pAtual[1] = ini[1];
	val_mapa[ini[0]][ini[1]] = 0;
	visitado_mapa[ini[0]][ini[1]] = 0;
	printf("\n\nINICIO %d %d \n", ini[0], ini[1]);
	printf("FIM %d %d \n\n", fim[0], fim[1]);
	LISTA *listanum = NULL;
	listanum = (LISTA*) malloc(50000*sizeof(LISTA));
	if (listanum== NULL)
	{
  		printf("N?o foi poss?vel alocar mem?ria!\n");
 		exit(1);
	}
	listanum[0].listai = ini[0];
	listanum[0].listaj = ini[1];
	ANTERIOR ant[40][82];
	while(z==1)
	{
		soma++;
		pAtual[0] = listanum[0].listai;
		pAtual[1] = listanum[0].listaj;
		listanum = (LISTA*) realloc( listanum, contador * sizeof(LISTA));
		dist_filho(mapa, fim, pAtual[0], pAtual[1], val_mapa, dist_perc, &contador, listanum, visitado_mapa, ant);
		visitado_mapa[pAtual[0]][pAtual[1]]=1;
		contador = contador - 1;
		if(contador == 0)
		{
			z=0;
		}
		else
		{
			memmove(&listanum[0], &listanum[1], contador * sizeof(LISTA));
	    	listanum = (LISTA*) realloc( listanum, contador * sizeof(LISTA));
	    	if (listanum == NULL)
			{
		  		printf("N?o foi poss?vel alocar mem?ria!\n");
		 		exit(1);
		
		    }	
	    }
	}
	free(listanum);
	printf("%d %d \n", pAtual[0], pAtual[1]);
	/*mapa[pAtual[0]][pAtual[1]]*/
	printf("Fim: %d %d com custo total %d\n", fim[0], fim[1], dist_perc[fim[0]][fim[1]]);
	printf(" Quantidade visitado %d \n", soma);
	t = clock() - t;
    printf("Tempo em %f segundos\n", ((double)t)/CLOCKS_PER_SEC);
	return 0;
}


