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

class Stack{
    public:
        Node *head, *next;
    Stack(){
        this->head = NULL;
        this->next = NULL;
    };

    void push(int data){
        Node *temp = this->head;
        this->head = new Node(data);
        this->head->next = temp;
    };

    int pop(){
        if(this->head == NULL) return 0;
        Node *temp = this->head;
        this->head = this->head->next;
        return temp->data;
    };

    int peek(){
        if(this->head == NULL) return 0;
        return this->head->data;
    };
};

int main(){
    Stack *s = new Stack();
    s->push(2);
    cout << s->peek() << endl;
    s->push(4);
    s->push(3);
    s->push(1);
    s->pop();
    cout << s->peek() << endl;
};
