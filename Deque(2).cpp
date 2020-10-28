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
int getMax(vector<int> arr){
    Deque *deque = new Deque();
    deque->enqueueFront(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > deque->peekFront()->data){
            deque->enqueueFront(arr[i]);
        }
        else deque->enqueueBack(arr[i]);
    }

    return deque->peekFront()->data;
}

int main(){
    cout << getMax({34,35,64,34,10,2,14,5,353,23,35,63,23}) << endl;//353
};
