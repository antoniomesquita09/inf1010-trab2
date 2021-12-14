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
	printf("teste de contador que chega na funcao dist_filho %d\n", contador);
	/*printf("\n \n teste endereco de listai e listaj que chega em dist_filho %d %d com valores no endereco 0 de %d  %d \n\n", listanum.listai, listanum.listaj, listanum[0].listai, listanum[0].listaj);*/
	printf("\nP ATUAL dentro da funcao %d %d\n", pAtual[0], pAtual[1]);
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
		printf("\nteste termo 0 %d %d com endereco %d %d com distancia %d\n", listanum[0].listai, listanum[0].listaj, &listanum[0].listai, &listanum[0].listaj, val_mapa[listanum[0].listai][listanum[0].listaj]);
		printf("teste termo 1 %d %d com endereco %d %d com distancia %d\n", listanum[1].listai, listanum[1].listaj, &listanum[1].listai, &listanum[1].listaj, val_mapa[listanum[1].listai][listanum[1].listaj]);
		printf("teste termo 2 %d %d com endereco %d %d com distancia %d\n", listanum[2].listai, listanum[2].listaj, &listanum[2].listai, &listanum[2].listaj, val_mapa[listanum[2].listai][listanum[2].listaj]);
		
	}
	printf("teste de contador %d\n", contador);
	
	
	*teste2 = contador;
	
	return;
}


int main()
{
	clock_t t;
    t = clock();
	FILE *arq;
	arq = fopen("mapa.txt", "rt");
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
	printf("\n teste inicial de endereco de lista i e lista j %d %d\n\n", listanum[0].listai, listanum[0].listaj);
	ANTERIOR ant[40][82];
	while(z==1)
	{
		soma++;
		pAtual[0] = listanum[0].listai;
		pAtual[1] = listanum[0].listaj;
		printf("\nP ATUALLLL %d %d \n\n", pAtual[0], pAtual[1]);
		printf("\n teste endereco de listai e listaj ANTES de enviar para dist_filho %d %d\n", listanum[0].listai, listanum[0].listaj);
		listanum = (LISTA*) realloc( listanum, contador * sizeof(LISTA));
		dist_filho(mapa, fim, pAtual[0], pAtual[1], val_mapa, dist_perc, &contador, listanum, visitado_mapa, ant);
		
		printf("\n teste endereco de listai e listaj DEPOIS de enviar para dist_filho %d com [0] %d %d\n\n", &listanum[0], &listanum, listanum);
		printf("teste termo 0 dps que retorna da funcao dist_filho %d %d\n", listanum[0].listai, listanum[0].listaj);
		printf("teste termo 1 dps que retorna da funcao dist_filho %d %d\n", listanum[1].listai, listanum[1].listaj);
		printf("teste termo 2 dps que retorna da funcao dist_filho %d %d\n", listanum[2].listai, listanum[2].listaj);
		printf("teste termo 3 dps que retorna da funcao dist_filho %d %d\n", listanum[3].listai, listanum[3].listaj);
		printf("teste termo 4 dps que retorna da funcao dist_filho %d %d\n", listanum[4].listai, listanum[4].listaj);
	
		printf("\n teste de contador apos retornar funcao %d \n\n", contador);
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
	    	
			printf("\nEstou aqui\n");
	    	if (listanum == NULL)
			{
		  		printf("N?o foi poss?vel alocar mem?ria!\n");
		 		exit(1);
		
			printf("\nteste 0 %d %d com endereco %d %d\n", listanum[0].listai, listanum[0].listaj, &listanum[0].listai, &listanum[0].listaj);
			printf("teste 1 %d %d com endereco %d %d\n", listanum[1].listai, listanum[1].listaj, &listanum[1].listai, &listanum[1].listaj);
			printf("teste 2 %d %d com endereco %d %d\n", listanum[2].listai, listanum[2].listaj, &listanum[2].listai, &listanum[2].listaj);
			printf("teste 3 %d %d com endereco %d %d\n", listanum[3].listai, listanum[3].listaj, &listanum[3].listai, &listanum[3].listaj);
			printf("teste 4 %d %d com endereco %d %d\n", listanum[4].listai, listanum[4].listaj, &listanum[4].listai, &listanum[4].listaj);
	    	/*printf("\n \n teste de lista %d %d\n\n", listai[0], listaj[0]);*/
		    }	
	    }
	}
	free(listanum);
	printf("%d %d \n", pAtual[0], pAtual[1]);
	/*mapa[pAtual[0]][pAtual[1]]*/
	printf("Fim: %d %d com Valor Total %d e distancia percorrida %d\n", fim[0], fim[1], val_mapa[fim[0]][fim[1]], dist_perc[fim[0]][fim[1]]);
	printf(" Quantidade visitado %d \n", soma);
	int h=0, ant1 = fim[0], ant2 = fim[1], tempo1 = fim[0], tempo2 = fim[1];
	printf("Coordenada inicio %d %d\n", ini[0], ini[1]);
	int m = 97;
	while(m > 0)
	{
		tempo1 = ant1;
		tempo2 = ant2;
		printf("Coordenada anterior %d %d e coordenada atual %d %d\n", ant[ant1][ant2].i, ant[ant1][ant2].j, tempo1, tempo2);
		ant1 = ant[tempo1][tempo2].i;
		ant2 = ant[tempo1][tempo2].j;
		m--;
	}
	printf("Dist perc 10 3 e 9 3 e 8 3 e 7 3 e 6 3 e 5 3 e 5 4 %d    %d     %d    %d    %d    %d    %d\n", dist_perc[10][3], dist_perc[9][3], dist_perc[8][3], dist_perc[7][3], dist_perc[6][3], dist_perc[5][3], dist_perc[5][4]);
	printf("Dist perc 5 6 e 5 7 e 4 7 e 3 7 e 3 8 e 3 9 e 4 9 %d    %d     %d    %d    %d    %d    %d\n", dist_perc[5][6], dist_perc[5][7], dist_perc[4][7], dist_perc[3][7], dist_perc[3][8], dist_perc[3][9], dist_perc[4][9]);
	t = clock() - t;
    printf("Tempo em %f segundos\n", ((double)t)/CLOCKS_PER_SEC);
	return 0;
}


