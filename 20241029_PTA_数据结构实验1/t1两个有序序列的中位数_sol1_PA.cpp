#include <iostream>

using namespace std;

typedef struct Node {
    Node *next;
    int value;
} Node;

int main() {
    int l, cnt = 0;
    cin >> l;
    Node *head, *p;
    head = new Node;
    head->next = nullptr;

    p = head;

    for (int i = 0; i < l; i++) {
        Node *newNode = new Node;
        cin >> newNode->value;
        if (p->value == newNode->value) {
            delete newNode;
            continue;
        }
        newNode->next = nullptr;
        p->next = newNode;
        p = newNode;
        ++cnt;
    }

    for (int i = 0; i < l; i++) {
        Node *newNode = new Node;
        cin >> newNode->value;

        p = head;
        while (p->next && newNode->value > p->next->value) {
            p = p->next;
        }

// newNode.value <= p.next.value
        if (newNode->value != p->value) {
            newNode->next = p->next;
            p->next = newNode;
            cnt++;
        }
    }

    int j = 1;
    p = head;

    while (j <= (cnt + 1) / 2) {
        p = p->next;
        ++j;
    }

    cout << p->value << endl;

    delete head;
}
