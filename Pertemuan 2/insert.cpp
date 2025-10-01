#include <iostream>
using namespace std;

// deklarasi sebuah unsur node
struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

// insert di depan
void insertFirst(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// insert di belakang
void insertLast(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// insert setelah node dengan nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, insert didepan dulu\n";
        return;
    }

    node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan\n";
    } else {
        node *newNode = new node;
        newNode->value = n;
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

// cetak linked list
void printList() {
    node *temp = head;
    cout << "Isi dari linked list: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}
