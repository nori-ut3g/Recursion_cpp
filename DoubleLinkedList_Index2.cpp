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
        void addNextNode(Node *newNode){
            Node *tempNode = this->next;
            this->next = newNode;
            newNode->next = tempNode;
        };
};
class SinglyLinkedList{
    public:
        vector<int> arr;
        Node *node, *head, *prev, *tail;
        SinglyLinkedList(vector<int> arr){
            if(arr.size() <= 0){
                this->head =  NULL;
                this->tail = this->head;
                return;
            };
            this->head = new Node(arr[0]);
            Node *currentNode = this->head;
            for(int i = 1; i < arr.size(); i++){
                currentNode->next = new Node(arr[i]);
                currentNode->next->prev = currentNode;
                currentNode = currentNode->next;
            };
            this->tail = currentNode;
        };
        Node *at(int index){
            Node *iterator = this->head;
            for(int i = 0; i < index; i++){
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        };

        void reverse(){
            Node *reverse = this->tail;
            Node *iterator = this->tail->prev;

            Node *currentNode = reverse;
            while(iterator != NULL){
                currentNode->next = iterator;

                iterator = iterator->prev;
                if(iterator != NULL) iterator->next = NULL;

                currentNode->next->prev = currentNode;
                currentNode = currentNode->next;
            }

            this->tail = currentNode;
            this->head = reverse;
        }

        void printInReverse(){
            Node *iterator = this->tail;
            string str = "";
            while(iterator != NULL){
                str += to_string(iterator->data) + " ";
                iterator = iterator->prev;
            }
            cout << str << endl;
        }


        void printList(){
            Node *iterator = this->head;
            string str = "";
            while(iterator != NULL){
                str += to_string(iterator->data) + " ";
                iterator = iterator->next;
            }
            cout << str << endl;
        }
};
int main(){
    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});
    numList->printList();
    numList->printInReverse();

    numList->printList();
    numList->reverse();
    numList->printList();

};
