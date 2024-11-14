#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, cnt = 0;
    cin >> l;
    int *a = new int[99999];
    int *b = new int[99999];
    for (int i = 0; i < 2 * l; i++) {
        cin >> a[i];
    }
    sort(a, a + 2 * l);
    cout << a[l-1];

    delete[] a;
    delete[] b;
}