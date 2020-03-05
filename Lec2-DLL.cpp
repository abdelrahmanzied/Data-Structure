#include <iostream>
using namespace std;

struct node {
    int data;
    node *next, *prev;
};

class dll {
    node *head, *tail;

public:
    dll() {head=tail=NULL;}
    void createnode(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = temp->prev = NULL;

        if (head==NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void displayFR() {
        node *temp = head;
        while (temp!=NULL) {
            cout << temp->prev << "\t" << temp->data << "\t" << temp->next << endl;
            temp = temp->next;
        }
    }

    void displayRF() {
        node *temp = tail;
        while (temp!=NULL) {
            cout << temp->prev << "\t" << temp->data << "\t" << temp->next << endl;
            temp = temp->prev;
        }
    }

    void display() {
        //cout << head->prev << "\t" << head << "\t" << head->next << endl;
        cout << tail->prev << "\t" << tail << "\t" << tail->next << endl;
    }

    void insertFirst(int value) {
        node *temp = new node;
        temp->data = value;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertEnd(int value) {
        node *temp = new node;
        temp->data = value;
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

    void insertPosition(int value, int pos) {
        node *pre, *cur;
        node *temp = new node;
        cur = head;
        for (int i=1; i<pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        temp->prev = pre;
        temp->next = cur;
        pre->next = temp;
        cur->prev = temp;
    }

    void deleteFirst() {
        node *temp;
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void deleteLast() {
        node *temp;
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void deletePosition(int pos) {
        node *pre, *cur;
        cur = head;
        for (int i=1; i<pos; i++) {
            pre = cur;
            cur = cur->next;
        }

        pre->next = cur->next;
        delete cur;
        cur = pre->next;
        cur->prev = pre;
    }
};



int main() {

    dll list;
    list.createnode(10);
    list.createnode(20);
    list.createnode(30);
    list.createnode(40);
    list.createnode(50);
    list.displayFR();
    cout << endl;

    list.deletePosition(3);
    list.displayFR();
    cout << endl;

    return 0;
}