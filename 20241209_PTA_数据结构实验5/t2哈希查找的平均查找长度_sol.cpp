#include "iostream"
#include "vector"
#include <iomanip>

using namespace std;
int K;

int h(int key) {
    return key % K;
}

int main() {
    int n, M;
    while (cin >> n) {
        cin >> M >> K;
        int hashmap[M + 1];
        int keywords[n];
        bool isOccupied[M + 1];

        vector<int> searchOKLength;
        vector<int> searchFailLength;

        for (int i = 0; i < M + 1; i++) {
            isOccupied[i] = false;
        }

        for (int i = 0; i < n; i++) {
            cin >> keywords[i];
            int okLength = 1;
            int j = h(keywords[i]);
            while (isOccupied[j]) {
                j = (j + 1) % M;
                okLength++;
            }
            hashmap[j] = keywords[i];
            isOccupied[j] = true;
            searchOKLength.push_back(okLength);
        }

        // 是K不是M（只针对K个入口进行统计，而不是整个表）
        for (int i = 0; i < K; i++) {
            int failLength = 1;
            int j = i;
            while (isOccupied[j]) {
                j = (j + 1) % M;
                failLength++;
            }

            searchFailLength.push_back(failLength);
        }

        int sum = 0;
        for (int okLength: searchOKLength) sum += okLength;
        double res1 = sum * 1.0 / searchOKLength.size();
        sum = 0;
        for (int failLength: searchFailLength) sum += failLength;
        double res2 = sum * 1.0 / K;

        cout << fixed << setprecision(2);
        cout << res1 << " " << res2 << endl;
    }
}