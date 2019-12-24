#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

#define MAX_V 100005

struct edge{
    int to;
    long long cost;
    edge(int i, long long j) {to = i, cost = j; };
};
typedef pair<long long, int> P; // firstは最短距離、secondは頂点の番号

int V;
vector<edge> G[MAX_V];
long long d[MAX_V];
int pv[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, LLONG_MAX);
    fill(pv, pv + V, -1);
    d[s] = 0;
    que.push(P(0,s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first ) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost ) {
                d[e.to] = d[v] + e.cost;
                pv[e.to] = v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

vector<int> get_path(int t){
    vector<int> path;
    for(; t != -1; t = pv[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}
