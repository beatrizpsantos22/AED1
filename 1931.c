#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta *prox;
} Aresta;

Aresta *grafo[20005];

void adicionar_aresta(int u, int v, int p) {
    Aresta *nova = (Aresta*) malloc(sizeof(Aresta));
    nova->destino = v;
    nova->peso = p;
    nova->prox = grafo[u];
    grafo[u] = nova;
}

typedef struct {
    int vertice;
    int estado;
    int distancia;
} Entrada;


int dijkstra_par(int inicio, int fim, int n) {
    int dist[20005][2];
    int usado[20005][2];

    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = INF;
        usado[i][0] = usado[i][1] = 0;
    }

    dist[inicio][0] = 0;  

    while (1) {
        int menor_v = -1, menor_estado = -1;

        for (int v = 1; v <= n; v++) {
            for (int e = 0; e < 2; e++) {
                if (!usado[v][e] &&
                    (menor_v == -1 || dist[v][e] < dist[menor_v][menor_estado])) {
                    menor_v = v;
                    menor_estado = e;
                }
            }
        }

        if (menor_v == -1) break;
        usado[menor_v][menor_estado] = 1;

        Aresta *aux = grafo[menor_v];
        while (aux != NULL) {
            int prox = aux->destino;
            int peso = aux->peso;

            int prox_estado = 1 - menor_estado; 

            if (dist[menor_v][menor_estado] + peso < dist[prox][prox_estado]) {
                dist[prox][prox_estado] = dist[menor_v][menor_estado] + peso;
            }

            aux = aux->prox;
        }
    }

    return dist[fim][0]; 
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        grafo[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        adicionar_aresta(u, v, p);
        adicionar_aresta(v, u, p);
    }

    int resposta = dijkstra_par(1, n, n);

    if (resposta >= INF)
        printf("-1\n");
    else
        printf("%d\n", resposta);

    return 0;
}
