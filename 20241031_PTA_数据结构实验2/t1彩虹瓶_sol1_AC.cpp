#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int totalColor, capacity, tasks;
    cin >> totalColor >> capacity >> tasks;

    int **t = new int *[tasks];

    for (int i = 0; i < tasks; i++) {
        t[i] = new int[totalColor];
        for (int j = 0; j < totalColor; j++) {
            std::cin >> t[i][j];
        }

        int currentColor = 1;
        int j = 0;
        int flag = 1;
        stack<int> st;

        while (currentColor <= totalColor) {
            int incoming = t[i][j];

            if (currentColor == incoming) {
                ++j;
                ++currentColor;
                continue;
                // 注意检测栈是否为空 st.empty()
            } else if (!st.empty() && currentColor == st.top()) {
                st.pop();
                ++currentColor;
                continue;
            } else if (j < totalColor) {
                st.push(incoming);
                if (st.size() > capacity) {
                    flag = 2; // OVERFLOW = 2
                    break;
                }
                ++j;
                continue;
            } else {
                flag = 3; // TOO_DEEP = 3
                break;
            }
        }

        cout << (flag == 1 ? "YES" : "NO") << endl;
    }

    delete[] t;
}
