//  see abc066 D

#define MOD 1000000007
#define MAX 200010

long long int f[MAX] = {};
long long int rf[MAX] = {};

long long int pw(long long int x, long long int y) {
    long long ret = 1LL;

    for(long long int mask = 0; mask < 50; ++mask) {
        if(y >> mask & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret % MOD;
}

long long int getComb(int n, int k) {
    if(k > n)
        return 0;
    long long int ret = f[n];
    ret = ret * rf[k] % MOD;
    ret = ret * rf[n - k] % MOD;
    return ret;
}

long long int initComb(int n) {
    rf[0] = f[0] = 1;
    for(int i = 1; i < n + 1; i++) {
        f[i] = f[i - 1] * i % MOD;
        rf[i] = pw(f[i], MOD - 2);
    }
    return 1;
}