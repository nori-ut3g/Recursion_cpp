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
        //int型だとNULLが使えないのでNode型に変更した
        Node *pop(){
            if(this->head == NULL) return NULL;
            Node *temp = this->head;
            this->head = this->head->next;
            return temp;
        };

        Node *peek(){
            if(this->head == NULL) return NULL;
            return this->head;
        };
};
vector<int> reverse(vector<int> arr){
    Stack *stack = new Stack();
    for(int i = 0; i < arr.size(); i++){
        stack->push(arr[i]);
    };
    vector<int> reversed = {};
    while(stack->peek() != NULL){
        reversed.push_back(stack->pop()->data);
    };
    return reversed;
};
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
};
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    printArray(reverse(arr));
};
