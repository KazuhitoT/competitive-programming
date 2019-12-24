#include <vector>

struct mini_uf {

    std::vector<int> par;

    mini_uf(int __n): par(std::vector<int>(__n, -1)) {}

    int root(int p) {
        return par[p] < 0 ? p : (par[p] = root(par[p]));
    }

    void join(int p, int q) {
        p = root(p); q = root(q);
        if (p == q) return;
        par[p] += par[q];
        par[q] = p;
    }

    /* use if you need
    bool same(int p, int q) {
        return root(p) == root(q);
    }

    int size(int p) {
        return -par[root(p)];
    }
    */
};

struct union_find {

    int par[UNION_FIND_MAX_N];
    int ran[UNION_FIND_MAX_N];
    int num[UNION_FIND_MAX_N];

    union_find(int __n) {
        init(__n);
    }
    
    void init(int n){
        for(int i=0; i<n; i++){
            par[i] = i;
            ran[i] = 0;
            num[i] = 1;
        }
    }
    
    int find(int x){
        if( par[x] == x ) return x;
        else return par[x] = find(par[x]);
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if( x == y ) return;
    
        if( ran[x] < ran[y] ){
            par[x] = y;
            num[y] += num[x];
            num[x] = 0;
        } else {
            par[y] = x;
            num[x] += num[y];
            num[y] = 0;
            if( ran[x] == ran[y] ) ran[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
};
