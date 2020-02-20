#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
public :
    list() {head=tail=NULL;}

    void creatnode(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next=temp;
            tail=temp;
        }
    }

    void display() {
        node *temp;
        temp = head;
        while (temp!=NULL) {
            cout << temp->data << "\t" << temp->next << endl;
            temp = temp->next;
        }
    }

private:
    node *head,*tail;
};



int main() {

    int n,value;
    cin >> n;
    list x;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        x.creatnode(value);
    }

    x.display();

    return 0;
}