#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct El {
    int value;
    int nextAddr;
    int addr;
};

void printRes(vector<El> els) {
    for (int i = 0; i < els.size(); i++) {
        El e = els[i];
        printf("%05d %d ", e.addr, e.value);
        if (i + 1 == els.size()) printf("-1");
        else printf("%05d\n", els[i+1].addr);
    }
}

int main() {
    int length, firstAddr;
    cin >> firstAddr >> length;

    vector<El> a, b;
    El* all = new El[1e6+10];
    int* next = new int[1e6+10];
    bool* seen = new bool[1e6+10];

    while (length--) {
        El current{};
        cin >> current.addr >> current.value >> current.nextAddr;
        next[current.addr] = current.nextAddr;
        all[current.addr] = current;
    }

    for (int current = firstAddr; current != -1; current = next[current]) {
        El e = all[current];
        if (seen[abs(e.value)]) {
            b.push_back(e);
        } else {
            a.push_back(e);
            seen[abs(e.value)] = true;
        }
    }

    printRes(a);
    printf("\n");
    printRes(b);

    delete[] all;
    delete[] next;
    delete[] seen;
}
