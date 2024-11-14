#include "iostream"

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[99999];
    int b[99999];

    int sorted[99999];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int tgIndex = (2 * n - 1) / 2;

    int pa = 0, pb = 0;
    int j = 0;

    while (j <= tgIndex) {
        if (a[pa] < b[pb]) {
            sorted[j] = a[pa];
            if (pa + 1 < n) pa++;
        } else {
            sorted[j] = b[pb];
            if (pb + 1 < n) pb++;
        }

        j++;
    }

    cout << sorted[tgIndex] << endl;
}