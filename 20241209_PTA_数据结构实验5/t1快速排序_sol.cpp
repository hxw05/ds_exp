#include "iostream"

using namespace std;

#define MAXSIZE 50     // MAXSIZE为最大数据元素数目

typedef int ElemType;
typedef struct {
    ElemType r[MAXSIZE + 1];    // r[0]闲置或另作它用
    int length;
} SqList;

int part(SqList &L, int low, int high) {
    int p = L.r[low];
    L.r[0] = L.r[low];
    while (low < high) {
        while (low < high && L.r[high] >= p) high--;
        L.r[low] = L.r[high];
        while (low < high && L.r[low] <= p) low++;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}

void QSort(SqList &L, int low, int high) {
    if (low < high) {
        int p = part(L, low, high);
        QSort(L, low, p - 1);
        QSort(L, p + 1, high);
    }
}

void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
}

int main() {
    int n;
    cin >> n;
    SqList list;
    list.length = n;
    for (int i = 1; i <= n; i++) {
        cin >> list.r[i];
    }

    QuickSort(list);

    for (int i = 1; i <= n; i++) {
        cout << list.r[i];
        if (i != n) cout << " ";
    }
}