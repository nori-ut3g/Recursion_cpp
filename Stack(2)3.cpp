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
        //intでnullは0?
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
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
};
vector<int> consecutiveWalk(vector<int>arr){
    Stack *stack = new Stack();
    stack->push(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(stack->peek()->data < arr[i]){
            while(stack->pop() != NULL);
        }
        stack->push(arr[i]);
    }
    vector<int> results = {};
    while(stack->peek() != NULL) results.insert(results.begin(), stack->pop()->data);
    return results;
};
int main(){
    printArray(consecutiveWalk({3,4,20,45,56,6,4,3,5,3,2})); // [5,3,2]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54})); // [64, 3, 0, -34, -54]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54,4})); // [4]
}
