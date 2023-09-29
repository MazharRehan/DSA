// array based implementation of complete binary tree
#include <iostream>
#include <cmath>
using namespace std;

class CompleteBinaryTree {
private:
    int* treeArray;
    int capacity;
    int size;

public:
    CompleteBinaryTree(int maxCapacity) {
        capacity = maxCapacity;
        treeArray = new int[capacity];
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insert(int value) {
        if (isFull()) {
            cout << "The tree is full. Cannot insert more elements." << endl;
            return;
        }

        treeArray[size] = value;
        size++;
    }

    void display() {
        if (isEmpty()) {
            cout << "The tree is empty." << endl;
            return;
        }

        int levels = log2(size) + 1;
        int currLevel = 0;
        int nodesInLevel = 1;
        int currNode = 0;

        while (currLevel < levels) {
            for (int i = 0; i < nodesInLevel && currNode < size; i++) {
                cout << treeArray[currNode] << " ";
                currNode++;
            }

            cout << endl;
            currLevel++;
            nodesInLevel *= 2;
        }
    }

    ~CompleteBinaryTree() {
        delete[] treeArray;
    }
};

int main() {
    CompleteBinaryTree tree(10);

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    tree.display();

    return 0;
}
