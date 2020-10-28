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


class SinglyLinkedList{
    public:
        Node *head;
        SinglyLinkedList(Node *node){
            this->head = node;
        };
};

int main(){

    vector<int> arr = {35,23,546,67,86,234,56,767,34,1,98,78,555};

    SinglyLinkedList *numList = new SinglyLinkedList(new Node(arr[0]));

    Node *currentNode = numList->head;
    for(int i = 1; i < arr.size(); i++){
        currentNode->next = new Node(arr[i]);
        currentNode = currentNode->next;
    }

    currentNode = numList->head;
    while(currentNode != NULL){
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}
