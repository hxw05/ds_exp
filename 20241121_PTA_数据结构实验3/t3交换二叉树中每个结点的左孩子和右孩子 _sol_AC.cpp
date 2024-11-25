#include "iostream"

using namespace std;

typedef struct Node {
    Node *lchild = nullptr;
    Node *rchild = nullptr;
    char value;
} Tree;

Tree *preOrderTraverseInput(Tree *t) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        return nullptr;
    } else {
        if (t == nullptr) t = new Tree;
        t->value = ch;
        t->lchild = preOrderTraverseInput(t->lchild);
        t->rchild = preOrderTraverseInput(t->rchild);
        return t;
    }
}

void midOrderTraverseOutput(Tree *t) {
    if (t == nullptr) return;
    midOrderTraverseOutput(t->lchild);
    cout << t->value;
    midOrderTraverseOutput(t->rchild);
}

void swap(Tree *t) {
    if (t == nullptr) return;
    Node* temp = t->lchild;
    t->lchild = t->rchild;
    t->rchild = temp;
    swap(t->lchild);
    swap(t->rchild);
}

int main() {
    Tree *tree = new Tree;
    preOrderTraverseInput(tree);
    midOrderTraverseOutput(tree);
    swap(tree);
    cout << endl;
    midOrderTraverseOutput(tree);
    delete tree;
}