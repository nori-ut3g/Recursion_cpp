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
        // リストの先頭から要素をpopします。O(1)
        void popFront(){
            this->head = this->head->next;
            this->head->prev = NULL;
        };

        // リストの末尾から要素をpopします。O(1)
        void pop(){
            this->tail = this->tail->prev;
            this->tail->next = NULL;
        };


        void preappend(Node *newNode){
            this->head->prev = newNode;
            newNode->next = this->head;
            newNode->prev = NULL;
            this->head = newNode;
        };
        void append(Node *newNode){
            this->tail->next = newNode;
            newNode->next = NULL;
            newNode->prev = this->tail;
            this->tail = newNode;
        };

        void addNextNode(Node *node, Node *newNode){
            Node *tempNode = node->next;
            node->next = newNode;
            newNode->next = tempNode;
            newNode->prev = node;
            if(node == this->tail) this->tail = newNode;
            else tempNode->prev = newNode;
        };
        // 与えられたノードをO(1)で削除します。
        void deleteNode(Node *node){
            if(node == this->tail) return this->pop();
            if(node == this->head) return this->popFront();

            node->prev->next = node->next;
            node->next->prev = node->prev;
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
    // pop
    numList->printList();

    numList->popFront();
    numList->pop();

    numList->printList();
    numList->printInReverse();

    // 要素を削除します
    cout << "Deleting in O(1)" << endl;
    numList->printList();

    numList->deleteNode(numList->at(3));
    numList->deleteNode(numList->at(9));
    numList->deleteNode(numList->at(0));

    numList->printList();
    numList->printInReverse();
};
