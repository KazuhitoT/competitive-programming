#define BELLMAN_FORD_MAX_E 10005
#define BELLMAN_FORD_MAX_V 10005

#include <memory.h>

struct edge {
  int from, to, cost;
  edge() {}
  edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

edge es[BELLMAN_FORD_MAX_E];

int d[BELLMAN_FORD_MAX_V];
bool negative[BELLMAN_FORD_MAX_V];
int V, E;

void shortest_path(int s, bool is_find_negative_loop) {
  for (int i = 0; i < V; i++)
    d[i] = (1 << 30);

  d[s] = 0;
  for (int j = 0; j < V; j++) {
    bool update = false;
    for (int i = 0; i < E; i++) {
      const edge &e = es[i];
      if (d[e.from] != (1 << 30) && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update)
      break;
  }

  if (is_find_negative_loop) {
    for (int i = 0; i < V; i++) {
      negative[i] = false;
    }

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < E; j++) {
        const edge &e = es[j];
        if (d[e.from] != (1 << 30) && d[e.to] > d[e.from] + e.cost) {
          negative[e.to] = true;
        }

        if (negative[e.from]) {
          negative[e.to] = true;
        }
      }
    }
  }
}
