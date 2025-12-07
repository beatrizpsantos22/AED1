#include <stdio.h>
#include <stdlib.h>

int visitado[1001];
int contador;
int **grafo;
int n_vertices;


void dfs(int atual) {
    visitado[atual] = 1;
    for (int i = 0; i < n_vertices; i++) {
        if (grafo[atual][i] && !visitado[i]) {
            contador++;    
            dfs(i);
            contador++;    
        }
    }
}

int main() {
    int t; 
    scanf("%d", &t);   

    while (t--) {
        int inicio, arestas;
        scanf("%d %d %d", &inicio, &n_vertices, &arestas);

     
        grafo = (int **)malloc(n_vertices * sizeof(int *));
        for (int i = 0; i < n_vertices; i++) {
            grafo[i] = (int *)calloc(n_vertices, sizeof(int));
        }

      
        for (int i = 0; i < arestas; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a][b] = 1;
            grafo[b][a] = 1;
        }

       
        for (int i = 0; i < n_vertices; i++) {
            visitado[i] = 0;
        }

        contador = 0;
        dfs(inicio);

        printf("%d\n", contador);


        for (int i = 0; i < n_vertices; i++)
            free(grafo[i]);
        free(grafo);
    }

    return 0;
}
