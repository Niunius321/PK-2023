#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int n; // liczba wierzchołków
int m; // liczba krawędzi

struct Edge {
    int u, v;
    int w;
} edges[MAXN];

// Struktura do przechowywania połączeń
struct Connection {
    int v;
    int w;
} connections[MAXN][2];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, int* parent) {
    if (parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

// Funkcja, która znajduje dwie najtańsze połączenia z każdego wierzchołka
void findTwoCheapestConnections() {
    // Sortuj krawędzie według wag
    sort(edges, edges + m, cmp);

    // Inicjalizuj zbiór reprezentujący wierzchołki
    int parent[MAXN];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Przeglądaj krawędzie i dodawaj do drzewa
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int p1 = find(u, parent);
        int p2 = find(v, parent);

        if (p1 != p2) {
            parent[p1] = p2;
            cnt++;
            
            // Dodaj połączenie do listy połączeń
            if (connections[u][0].w == 0 || connections[u][0].w > w) {
                connections[u][1] = connections[u][0];
                connections[u][0] = {v, w};
            } else if (connections[u][1].w == 0 || connections[u][1].w > w) {
                connections[u][1] = {v, w};
            }
            
            if (connections[v][0].w == 0 || connections[v][0].w > w) {
                connections[v][1] = connections[v][0];
                connections[v][0] = {u, w};
            }  else if (connections[v][1].w == 0 || connections[v][1].w > w) {
                connections[v][1] = {u, w};
            }
            
        }
                       if (connections[v][1].w == 0 || connections[v][1].w > w) {
                           connections[v][1] = {u, w};
                       }

                       if (cnt == n - 1) {
                           break;
                       }
                   }
               }

int main() {
               // Wczytaj liczbę wierzchołków i krawędzi
    std::ifstream in("/Users/oskarukleja/Desktop/studia/ppk/1/1/dane.txt");
    std::string line;
    int i=0;
    while(std::getline(in, line)){
        std::stringstream komputer(line);
        int komputer1,komputer2,koszt;
        if(!(komputer>>komputer1)) continue;
        if(!(komputer>>komputer2)) continue;
        if(!(komputer>>koszt)) continue;
        edges[i] = {komputer1, komputer2, koszt};
        i++;
    }
    n=4;
    m=2;
               // Wczytaj krawędzie

               findTwoCheapestConnections();

               // Wyświetl połączenia
               for (int i = 0; i < n; i++) {
                   cout << "Wierzchołek " << i << " ma połączenia:" << endl;
                   cout << "1. Wierzchołek " << connections[i][0].v << " o koszcie " << connections[i][0].w << endl;
                   cout << "2. Wierzchołek " << connections[i][1].v << " o koszcie " << connections[i][1].w << endl;
               }

               return 0;
           }
