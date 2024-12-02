#include "iostream"

using namespace std;

#define Infinity 99999999

int main() {
    int n, m;
    cin >> n >> m;

    int weights[1000][1000];

    for (auto & weight : weights) {
        for (int & j : weight) {
            j = Infinity;
        }
    }

    bool DeterminedFrom1[1000]; // S
    int MinLengthFrom1[1000]; // D

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        weights[a][b] = w;
    }

    for (int v = 1; v <= n; v++) {
        DeterminedFrom1[v] = false;
        MinLengthFrom1[v] = weights[1][v];
    }

    DeterminedFrom1[1] = true;
    MinLengthFrom1[1] = 0;

    // 从第二个顶点开始处理
    for (int i = 2; i <= n; i++) {
        int min = Infinity;
        int v;
        // 从1一直到n，在MinLengthFrom1中选择一条最短的路径
        for (int j = 1; j <= n; j++) {
            if (!DeterminedFrom1[j] && MinLengthFrom1[j] < min) {
                v = j;
                min = MinLengthFrom1[j];
            }
        }

        // 最短路径结果为v
        DeterminedFrom1[v] = true;

        for (int j = 1; j <=n; j++) {
            if (!DeterminedFrom1[j] && (MinLengthFrom1[v] + weights[v][j]) < MinLengthFrom1[j]) {
                MinLengthFrom1[j] = MinLengthFrom1[v] + weights[v][j];
            }
        }
    }

    cout << (MinLengthFrom1[n] < Infinity ? MinLengthFrom1[n] : -1) << endl;
}