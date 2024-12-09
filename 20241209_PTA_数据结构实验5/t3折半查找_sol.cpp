#include "iostream"

using namespace std;

#define MAXSIZE 50
typedef int ElemType;
typedef struct {
    ElemType r[MAXSIZE + 1];
    int length;
} SSTable;

int find(SSTable &table, int tg) {
    int low = 0, high = table.length - 1, mid;
    while (low <= high) {
        mid = (high + low) / 2;
        if (table.r[mid] == tg) return mid;
        if (table.r[mid] < tg) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, tg;
    SSTable s;
    cin >> n;
    s.length = n;
    for (int i = 0; i < n; i++) {
        cin >> s.r[i];
    }
    cin >> tg;

    int res = find(s, tg);
    if (res == -1) cout << "NOT FOUND";
    else cout << res+1;
}