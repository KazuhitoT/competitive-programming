#include <vector>
#include <queue>

#define MAX_V 100005

using namespace std;

struct edge {
    int from, to, cost;
    edge (int i, int j, int c) { from = i; to = j; cost = c; }

    bool operator< (const edge& rhs) const {
        return cost < rhs.cost;
    }
};

vector<edge> G[MAX_V];
bool used[MAX_V];
int V;

int prim() {
    fill(used, used + V, false);

    priority_queue<edge> pq;
    for (int i = 0; i < G[0].size(); i++) pq.push(G[0][i]);

    int res = 0;

    while( !pq.empty() ){
        edge e = pq.top(); pq.pop();
        if ( used[e.to] ) continue;

        res += e.cost;

        for (int i = 0; i < G[e.to].size(); i++) pq.push(G[e.to][i]);
    }

    return res;
}

