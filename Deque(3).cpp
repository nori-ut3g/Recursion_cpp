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
vector<int> getMaxWindows(vector<int>arr, int k){
    if(k > arr.size()) return {};

    vector<int> results = {};
    Deque *deque = new Deque();

    for(int i = 0; i < k; i++){
        while(deque->peekBack() != NULL && arr[deque->peekBack()->data] <= arr[i]){
            deque->dequeueBack();
        }
        deque->enqueueBack(i);
    }

    for(int i = k; i < arr.size(); i++){
        results.push_back(arr[deque->peekFront()->data]);
        while(deque->peekFront() != NULL && deque->peekFront()->data <= i-k){
            deque->dequeueFront();
        };
        while(deque->peekBack() != NULL && arr[deque->peekBack()->data] <= arr[i]){
            deque->dequeueBack();
        } ;
        deque->enqueueBack(i);
    }

    results.push_back(arr[deque->peekFront()->data]);

    return results;
}
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main(){
    printArray(getMaxWindows({34,35,64,34,10,2,14,5,353,23,35,63,23}, 4));
};
