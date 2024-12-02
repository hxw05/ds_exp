#include "iostream"
#include "deque"
#include "stack"
#include "vector"

using namespace std;

// 注：顶点编号从1开始
int main() {
    int n, m;
    cin >> n >> m;
    vector<deque<int> > g = vector<deque<int> >(100);
    vector<int> indeg = vector<int>(100);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_front(b);
        indeg[b]++;
    }

    stack<int> topoStack;
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) topoStack.push(i);
    }

    int total = 0;
    while (!topoStack.empty()) {
        int current = topoStack.top();
        result.push_back(current);
        topoStack.pop();
        total++;
        for (int v : g[current]) {
            --indeg[v];
            if (indeg[v] == 0) topoStack.push(v);
        }
    }

    for (int r : result) {
        cout << r << " ";
    }

    if (total < n) {
        cout << endl << 0;
    }
}