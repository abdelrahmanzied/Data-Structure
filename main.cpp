#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class singlyList {
    node *head=NULL, *tail=NULL;

public :
    void creatnode(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if (tail == 0) {
            head = tail = temp;
        } else {
            tail->next = temp; // the old node->next = the new node;
            tail = temp; // tail = the new node;
        }
    }

    void display() {
        node *temp = head;
        int i=1;
        while (temp!=0) {
            cout << "The node" << i << " value: " <<  temp->data << ",\t" << "next: " << temp->next << endl;
            temp = temp->next;
            i++;
        }
    }

    void insertStart(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insertEnd(int value) {
        node *temp = new node;
        temp->data = value;
        tail->next = temp;
        tail = temp;
    }

    void insertPosition(int value, int position) {
        node *pre = new node;
        node *cur = head;
        node *temp = new node;

        for (int i=1; i<position; i++) {
            pre = cur;
            cur = cur->next;
        }

        temp->data = value;
        temp->next = cur;
        pre->next = temp;

    }

    void deleteFrist() {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        node *pre = new node;
        node *cur = head;

        while (cur->next != 0) {
            pre = cur;
            cur = cur->next;
        }

        tail = pre;
        pre->next = NULL;
        delete cur;
    }

    void deletePosition(int position) {
        node *pre = new node;
        node *cur = head;

        for (int i=1; i<position; i++) {
            pre = cur;
            cur = cur = cur->next;
        }

        pre->next = cur->next;
    }
};

int main() {

    singlyList list;
    int n,value;
    char c;
    cout << "Enter the number of nodes: "; cin >> n;

    for (int i=0; i<n; i++) {
        cin >> value;
        list.creatnode(value);
    }

    list.display();
    cout << "Do you want any change?\t(1=Yes, o=No) : "; cin >> n;

    if(n) {
        cout << "Do you want insert or delete node?\t(i=Insert, d=Delete) : ";
        cin >> c;
        if (c=='i') {
            cout << "Enter your position\t(1:at the start, 0:at the end, for any position enter its number) : ";
            cin >> n;

            if(n==1) {
                cout << "Enter the value of new node: "; cin >> value;
                list.insertStart(value);
            } else if (n==0) {
                cout << "Enter the value of new node: "; cin >> value;
                list.insertEnd(value);
            } else {
                cout << "Enter the value of new node: "; cin >> value;
                list.insertPosition(value, n);
            }

        } else {
            cout << "Enter your position\t(1:at the start, 0:at the end, for any position enter its number) : ";
            cin >> n;

            if(n==1) list.deleteFrist();

            else if (n==0) list.deleteEnd();

            else list.deletePosition(n);
        }
    }

    cout << endl << ">>>>>>>>>> Your Linked List <<<<<<<<<<" << endl;
    list.display();

    return 0;
}