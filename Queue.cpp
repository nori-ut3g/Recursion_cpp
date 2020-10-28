#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            this->data = value;
            this->next = NULL;
        };
};

class Queue{
    public:
        Node *head, *tail;
    Queue(){
        this->head = NULL;
        this->tail = NULL;
    }

    Node *peekFront(){
        if(this->head == NULL) return NULL;
        return this->head;
    }

    Node *peekBack(){
        if(this->tail == NULL) return this->peekFront();
        return this->tail;
    }

    void enqueue(int data){
        if(this->head == NULL){
            this->head = new Node(data);
        }
        else if(this->tail == NULL){
            this->tail = new Node(data);
            this->head->next = this->tail;
        }
        else{
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
        }
    }

    Node *dequeue(){
        if(this->head == NULL) return NULL;
        Node *temp = this->head;

        if(this->head->next == NULL){
            this->head = NULL;
            this->tail = NULL;
        }
        else this->head = this->head->next;

        return temp;
    }
};

int main(){
    Queue *q = new Queue();

    q->enqueue(4);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    q->enqueue(50);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    q->enqueue(64);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    cout << "dequeued :" + to_string(q->dequeue()->data) << endl;
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;
}
