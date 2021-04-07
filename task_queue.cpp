#include <iostream>
#include <functional>
#include <string>

using namespace std;

class Node {
public:
    function<void()> data;
    Node* next;

    Node(function<void()> data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;

    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    function<void()> peekFront() {
        if(this->head == nullptr) return nullptr;
        else return this->head->data;
    }

    void enqueue(function<void()> data) {
        if(this->head == nullptr) {
            this->head = new Node(data);
        }else if(this->tail == nullptr) {
            this->tail = new Node(data);
            this->head->next = this->tail;
        }else {
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
        }
    }

    function<void()> dequeue() {
        if(this->head == nullptr) return nullptr;
        Node* temp = this->head;

        if(this->head->next == nullptr) {
            this->head = nullptr;
            this->tail = nullptr;
        }else {
            this->head = this->head->next;
        }
        return temp->data;
    }
};

class TaskQueue {
public:
    Queue* queue;

    TaskQueue() {
        this->queue = new Queue();
    }

    void push(function<void()> callback) {
        this->queue->enqueue(callback);
    }

    bool taskExists() {
        return this->queue->peekFront() != nullptr;
    }

    void run() {
        function<void()> callback = this->queue->dequeue();
        if(callback != nullptr) callback();
    }
};

int main() {
    TaskQueue* scheduler = new TaskQueue();
    scheduler->push([]{cout << "1. Running the first function!!!" << endl;});
    scheduler->push([]{cout << "2. Running the first function!!!" << endl;});
    scheduler->push([]{cout << "3. Running the first function!!!" << endl;});
    scheduler->push([]{cout << "4. Running the first function!!!" << endl;});

    while(scheduler->taskExists()) scheduler->run();
}