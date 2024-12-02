#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

typedef struct Edge {
    int cost;
    int from;
    int to;

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
} Edge;

int componentOf[9999];

int find(int x)
{
    if (componentOf[x] != x) {
        componentOf[x] = find(componentOf[x]);
    }
    return componentOf[x];
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        Edge edge = {w, a, b};
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) {
        componentOf[i] = i;
    }

    int lowcost = 0;
    int cnt = 0;
    for (auto &e: edges) {
        int from = e.from; int to = e.to;

        from = find(from);
        to = find(to);

        if (from != to) {
            cnt++;
            lowcost += e.cost;
            componentOf[from] = to;
        }
    }

    if (cnt < n - 1) cout << "impossible";
    else cout << lowcost;
}