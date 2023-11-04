#include <iostream>
using namespace std;


// Node Struct
template <class anyType>
struct Node{
    anyType variable;
    Node* next;
};

// LinkedList Class
template <class anyType>
class LinkedList{
    private:

        int index;
        Node<anyType>* tail;
        Node<anyType>* head;

        void emptyListAddNode(Node<anyType>* var){
            head = var;
            tail = var;
            tail->next = nullptr;
        }
    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
            index = 0;
        }
        LinkedList(anyType var){
            Node<anyType>* temp = new Node<anyType>;
            temp->variable = var;
            temp->next = nullptr;
            emptyListAddNode(temp);
            index = 1;
        }
        int getIndex()const{return index;}
        bool isEmpty(){
            bool empt = false;
            if(index == 0 || head == nullptr){
                empt = true;
            }
            return empt;
        }
        void push_back(anyType var){
            Node<anyType>* temp = new Node<anyType>;
            temp->variable = var;
            temp->next = nullptr;
            if(head == nullptr || index == 0)
            {
                emptyListAddNode(temp);
            }
            else{
                tail ->next = temp;
                tail = temp;
            }
            index++;
        }
        void push_front(anyType var){
            Node<anyType>* temp = new Node<anyType>;
            temp->variable = var;
            temp->next = nullptr;
            if(head == nullptr || index == 0){
                emptyListAddNode(temp);
            }
            else{
                temp->next = head;
                head = temp;
            }
            index++;
        }
        void print_list(){
            Node<anyType>* temp = head;
            while(temp != nullptr){
                cout<<temp->variable<<endl;
                temp = temp->next;
            }
        }
        bool search(anyType var){
            Node<anyType>* temp = head;
            bool find = false;
            while(temp != nullptr){
                if(temp->variable == var){
                    find = true;
                }
                temp = temp->next;
            }
            return find;
        }

        void deleteLast(){
            if(isEmpty() == true)
            {
                cout<<"List Empty !!"<<endl;
            }
            else
            {
                Node<anyType>* currentNode = head;
                Node<anyType>* previousNode = head;
                while(currentNode->next != nullptr)
                {
                    previousNode = currentNode; 
                    currentNode = currentNode->next;
                }
                delete currentNode;
                tail = previousNode;
                tail->next = nullptr;
                index--;
            }
        }
        void deleteFirst(){
            if(isEmpty() == true)
            {
                cout<<"List Empty !!"<<endl;
            }
            else
            {
                Node<anyType>* temp = head;
                temp = temp->next;
                delete head;
                head = temp;
                index--;
            }
        }
        void deleteIndex(int ind)
        {
            if(isEmpty() == true)
            {
                cout<<"List Empty !!"<<endl;
            }
            else
            {
                if(ind == 1)
                {
                    deleteFirst();
                }
                else if(ind == index)
                {
                    deleteLast();
                }
                else
                {
                    static int counter = 1;
                    Node<anyType>* currentAddr = head;
                    Node<anyType>* prevAddr = head;

                    while(counter < ind){
                        prevAddr = currentAddr;
                        currentAddr = currentAddr->next;
                        counter++;
                    }
                    prevAddr->next = currentAddr->next;
                    delete currentAddr;
                }
                index--;
            }
        }
        Node<anyType>* searchReturnAddr(anyType var)
        {
            Node<anyType>* returnAddr = nullptr;
            Node<anyType>* currentAddr = head;
                while(currentAddr != nullptr){
                    if(currentAddr->variable == var){
                        returnAddr = currentAddr;
                    }
                    currentAddr = currentAddr->next;
                }
            return returnAddr;
        }
        void deleteValue(anyType val)
        {
            if(search(val) == true){
                if(head->variable == val){
                    deleteFirst();
                }
                else if(tail->variable == val){
                    deleteLast();
                }
                else{
                    Node<anyType>* current = head;
                    Node<anyType>* prev = head;
                    while(current != nullptr){
                        if(current->variable == val){
                            break;
                        }
                        prev = current;
                        current = current->next;

                    }
                    prev->next = current->next;
                    delete current;
                }
            }
            else
            {
                cout<<"Value not fount !!!"<<endl;
            }
        }
        void insertAfterIndex(anyType var, int ind){
            
            if (ind < 1 || ind > index + 1) {
                cout << "Invalid index" << endl;
                return;
            }
            Node<anyType>* temp = new Node<anyType>;
            temp->variable = var;
            temp->next = nullptr;
            if(ind == 1){
                temp->next = head->next;
                head->next = temp; 
            }
        else 
        {
            Node<anyType>* current = head;
            int counter = 1;

            while (counter < ind) {
                current = current->next;
                counter++;
            }

            temp->next = current->next;
            current->next = temp;
        }
            index++;
        }
};
