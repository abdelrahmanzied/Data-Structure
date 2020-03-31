#include <iostream>
using namespace std;

int queue[5], n=5, front=-1, rear=-1;

void enqueue(int value) {
    if (rear == n-1)
        cout << "Queue overflow" << endl;
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    } else {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
    }
}

void enqueueCQ(int value) {
    if ((front == 0 && rear == n-1) || front == rear+1) {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        if (rear == n-1)
            rear = 0;
        else
            rear ++;
    }
    queue[rear] = value;

}

void dequeueCQ() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Element deleted from queue is : " << queue[front] << endl;

    if (front == rear)
        front = rear = -1;
    else {
        if (front == n-1)
            front = 0;
        else front++;
    }
}

void display() {
    if (front == -1)
        cout << "Queue Underflow";
    else {
        cout << "Queue Elements are : ";
        for (int i=front; i <= rear; i++)
            cout << queue[i] << "\t";
        cout << endl;
    }
}

void displayCQ() {
    int f = front, r = rear;
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue Elements are : ";

    if (f <= r) {
        while (f <= rear) {
            cout << queue[f] << "\t";
            f++;
        }
    } else {
        while (f <= n-1) {
            cout << queue[f] << "\t";
            f++;
        }

        f=0;

        while (f <= r) {
            cout << queue[f] << "\t";
            f++;
        }
    }
    cout << endl;
}

// Lniked List Impplemintation

struct node {
    int data;
    node *next;
};

class dQueue {
    node *front, *rear;

public:
    dQueue() {front = rear = NULL;}

    int enqueue(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;

        if (front == NULL)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        node *temp = front;
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        } else {
            cout << "Element deleted is : " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        node *temp = front;
        cout << "Queue Elements are : ";
        while(temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    dQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.enqueue(60);
    q.display();

    return 0;
}
