#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next, *prev;
        Node(int value){
            this->data = value;
            this->next = NULL;
            this->prev = NULL;
        };
};

class Deque{
    public:
        Node *head, *tail;
        Deque(){
            this->head = NULL;
            this->tail = NULL;
        }

        Node *peekFront(){
            if(this->head == NULL) return NULL;
            return this->head;
        }

        Node *peekBack(){
            if(this->tail == NULL) return NULL;
            return this->tail;
        }

        void enqueueFront(int data){
            if(this->head == NULL){
                this->head = new Node(data);
                this->tail = this->head;
            }else{
                Node *node = new Node(data);
                this->head->prev = node;
                node->next = this->head;
                this->head = node;
            }
        }

        void enqueueBack(int data){
            if(this->head == NULL){
                this->head = new Node(data);
                this->tail = this->head;
            }else{
                Node *node = new Node(data);
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
        }

        Node *dequeueFront(){
            if(this->head == NULL) return NULL;

            Node *temp = this->head;
            this->head = this->head->next;
            if(this->head != NULL) this->head->prev = NULL;
            else this->tail = NULL;
            return temp;
        }

        Node *dequeueBack(){
            if(this->tail == NULL) return NULL;

            Node *temp = this->tail;
            this->tail = this->tail->prev;

            if(this->tail != NULL) this->tail->next = NULL;
            else this->head = NULL;
            return temp;
        }
};

int main(){
    Deque *q = new Deque();

    q->enqueueBack(4);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    q->enqueueBack(50);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    cout << "dequeued :" + to_string(q->dequeueFront()->data) << endl;
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    q->enqueueFront(36);
    q->enqueueFront(96);
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    cout << "dequeued :" + to_string(q->dequeueBack()->data) << endl;
    cout << q->peekFront()->data << endl;
    cout << q->peekBack()->data << endl;

    cout << "Emptying" << endl;
    q->dequeueBack();
    q->dequeueBack();
    q->dequeueBack();
    q->dequeueBack();

    // cout << "Emptying" << endl;
    // q->dequeueFront();
    // q->dequeueFront();
    // q->dequeueFront();
    // q->dequeueFront();

    // cout << q->peekFront()->data << endl;
    // cout << q->peekBack()->data << endl;
};
