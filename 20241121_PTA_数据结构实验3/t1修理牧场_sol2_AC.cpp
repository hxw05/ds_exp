#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > minHeap; // 最小堆

    // 读取输入并构建最小堆
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minHeap.push(x);
    }

    int s = 0;

    // 模拟哈夫曼树构建过程
    while (minHeap.size() > 1) {
        int min1 = minHeap.top();
        minHeap.pop();
        int min2 = minHeap.top();
        minHeap.pop();

        int sum = min1 + min2;
        s += sum;

        minHeap.push(sum);
    }

    cout << s << endl;
    return 0;
}