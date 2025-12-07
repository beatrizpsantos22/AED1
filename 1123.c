#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta *prox;
} Aresta;

Aresta *grafo[256];

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
} Nodo;


int dijkstra(int inicio, int fim, int c, int n) {
    int dist[256][2];
    int usado[256][2];

    for (int i = 0; i < n; i++) {
        dist[i][0] = dist[i][1] = INF;
        usado[i][0] = usado[i][1] = 0;
    }

    dist[inicio][ (inicio < c ? 0 : 1) ] = 0;

    while (1) {
        int menor_v = -1, menor_estado = -1;

     
        for (int v = 0; v < n; v++) {
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

            int prox_estado = menor_estado;

        
            if (menor_estado == 0) {
                if (menor_v < c) {
                    if (prox != menor_v + 1) {
                        aux = aux->prox;
                        continue;
                    }
                }

                if (prox >= c) prox_estado = 1;
            }

            if (dist[menor_v][menor_estado] + peso < dist[prox][prox_estado]) {
                dist[prox][prox_estado] = dist[menor_v][menor_estado] + peso;
            }

            aux = aux->prox;
        }
    }


    int ans = dist[fim][0];
    if (dist[fim][1] < ans) ans = dist[fim][1];
    return ans;
}

int main() {
    int n, m, c, k;

    while (1) {
        scanf("%d %d %d %d", &n, &m, &c, &k);
        if (n == 0 && m == 0 && c == 0 && k == 0) break;


        for (int i = 0; i < n; i++) grafo[i] = NULL;


        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adicionar_aresta(u, v, p);
            adicionar_aresta(v, u, p);
        }

        int resposta = dijkstra(k, c - 1, c, n);
        printf("%d\n", resposta);
    }

    return 0;
}
