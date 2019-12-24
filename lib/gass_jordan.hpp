#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

const int MAX_ROW = 1010; // to be set appropriately
const int MAX_COL = 1010; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

ostream& operator << (ostream& s, BitMatrix A) {
    s << endl; 
    for (int i = 0; i < A.H; ++i) {
        for (int j = 0; j < A.W; ++j) {
            s << A[i][j] << ", ";
        }
        s << endl;
    }
    return s;
}

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
};


int main() {
    int N, M, D;
    while (cin >> M >> N >> D, N) {
        vector<vector<int> > a(N, vector<int>(M, 0));
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> a[i][j];

        BitMatrix A(N*M, N*M);
        vector<int> b(N*M, 0), res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i*M+j][i*M+j] = 1;
                for (int k = 0; k < N; ++k) {
                    for (int l = 0; l < M; ++l) {
                        if (abs(i - k) + abs(j - l) != D) continue;
                        A[i*M+j][k*M+l] = 1;
                    }
                }
                b[i*M+j] = 1 - a[i][j];
            }
        }
        int rank = linear_equation(A, b, res);
        if (rank == -1) cout << 0 << endl;
        else cout << 1 << endl;
    }
}