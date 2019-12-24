#include "union_find.cpp"
#include <algorithm>
#include <tuple>

// cost, from, to
typedef std::tuple<int, int, int> edge;

int kruscal(int v, const std::vector<edge>& es) {
    std::sort(es.begin(), es.end());
    mini_uf uf(v);
    int res = 0;
    for(auto& t: es) {
        int cost, from, to;
        std::tie(cost, from, to) = t;
        if (uf.root(from) != uf.root(to)) {
            uf.join(from, to);
            res += cost;
        }
    }
    return res;
}

/* old version
#include "union_find.cpp"
#include <algorithm>
using namespace std;

#define MAX_E 200010

struct edge {
    long long u, v, cost;
    edge(){};
    edge(long long a, long long b, long long c){
        u = a;
        v = b;
        cost = c;
    }
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

long long kruskal(){
    sort(es, es + E, comp);
    init(V);
    long long res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
*/