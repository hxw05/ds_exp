#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

void DFS(vector<int> *g, int v, bool *visited) {
    cout << v << " ";
    visited[v] = true;
    for (int adjV: g[v]) {
        if (!visited[adjV]) DFS(g, adjV, visited);
    }
}

// 注：顶点编号从0开始
int main() {
    int n, e;
    cin >> n >> e;
    vector<int> g[20001];
    bool visited[20001];

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS(g, i, visited);
    }
}