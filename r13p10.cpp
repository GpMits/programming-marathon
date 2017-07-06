#include <stdio.h>
#include <string.h>
#include<limits.h>
#include <iostream>
#include<vector>
using namespace std;
#define MAX 1000

bool listaVazia(int lista[], int N){
	bool vazio = true;
	int i;
	for(i=0; i<N; i++){
		if(lista[i] != -1){
			vazio = false;
		}
	}
	return vazio;
}
int proximoVerticeLista(int lista[], int N){
	int i=0;
	while(lista[i] != -1 && i < N){
		i++;
	}
	if(lista[i] == -1){
		return i;
	}
	else return N;
}

bool BreadthFirstSearch (long grafo_residual[][MAX], int caminho[], int S, int T, int N ){
	int v1,v2, i, j;
	int visitado[N], lista[N];

	for(i=0; i<N; i++){
		visitado[i] = 0;
		lista[i] = -1;
	}
	
	lista[0] = S;
	visitado[S] = 1;
	caminho[S] = -1;

	while(!listaVazia(lista, N)){
		v1 = lista[0];
		for (i=1; i<N; i++){
			lista[i-1] = lista[i];
		}
		
		for (v2=0; v2<N; v2++){
			if(visitado[v2] == 0 && grafo_residual[v1][v2] > 0){
				lista[proximoVerticeLista(lista, N)] = v2;
				caminho[v2] = v1;
				visitado[v2] = 1;
			}
        }
	}
	if (visitado[T] == 1){
		return true;
	}
	else{
		return false;
	}
}

long FordFulkerson(long grafo[][MAX], int S, int T, int N, long grafo_residual[][MAX]){
    int v1, v2;
	long fluxo=0, fluxo_aresta=0;
    int caminho[N];

    for (v1=0; v1<N; v1++){
        for (v2=0; v2<N; v2++){
             grafo_residual[v1][v2] = grafo[v1][v2];
         }
    }
 
    while (BreadthFirstSearch(grafo_residual, caminho, S, T, N)){
        fluxo_aresta = LONG_MAX;
        v2 = T;
        while (v2 != S){
            v1 = caminho[v2];
            if(grafo_residual[v1][v2] < fluxo_aresta){
            	fluxo_aresta = grafo_residual[v1][v2];
            }
            v2=caminho[v2];
        }
 
        v2 = T;
        while (v2 != S){
            v1 = caminho[v2];
            grafo_residual[v2][v1] += fluxo_aresta;
            grafo_residual[v1][v2] -= fluxo_aresta;
            v2=caminho[v2];
        }

        fluxo += fluxo_aresta;
    }
    return fluxo;
}


int main() {
	long custosVertices[1000];
	long mat[1000][1000];
	long matRes[1000][1000];
	int n, m;
	int a, b;
	long c;

	scanf("%d%d", &n, &m);

	while(n!=0){
		memset(mat, -1, sizeof(mat));
		memset(mat, -1, sizeof(matRes));
		//memset(mat, -1, sizeof(custosVertices));
		
		for(int i=0; i<n-2; i++){
			scanf("%d %ld", &a, &c);
			custosVertices[a-1] = c;
		}

		for(int i=0; i<m; i++){
			scanf("%d %d %ld",&a,&b,&c);
			mat[a-1][b-1] = c;
			mat[b-1][a-1] = c;
		}
		
		for(int i=1; i<n-1; i++){
			mat[i][i+n-1] = custosVertices[i];
			for(int j=0; j<n; j++){
				mat[i+n-1][j] = mat[i][j];
				mat[i][j] = -1;
			}
		}
		/*
		for (int i = 0; i <((n-2)*2)+2; i++) {
            for (int j = 0; j <((n-2)*2)+2; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }*/
        
        printf("%ld", FordFulkerson(mat, 0, n-1, ((n-2)*2)+2, matRes));
        
        
        
  
        scanf("%d%d", &n, &m);
        //if(n!=0)
        printf("\n");
		
	}
	return 0;
}