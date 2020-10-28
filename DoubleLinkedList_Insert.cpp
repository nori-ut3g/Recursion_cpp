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

    // 45をpreappend
    numList->preappend(new Node(45));
    cout << numList->head->data << endl;
    numList->printList();

    // 71をappend
    numList->append(new Node(71));
    cout << numList->tail->data << endl;
    numList->printList();
    cout << "" << endl;

    // ノードの後に新しいノードを追加
    numList->addNextNode(numList->at(3), new Node(4));
    numList->printList();
    cout << numList->tail->data << endl;

    numList->addNextNode(numList->at(15), new Node(679));
    numList->printList();
    cout << numList->tail->data << endl;

    numList->printInReverse();
};
