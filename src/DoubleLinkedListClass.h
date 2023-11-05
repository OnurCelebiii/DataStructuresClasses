#include<iostream>
using namespace std;

template<class T>
struct Node{
    Node* next;
    Node* prev;
    T variable;
};

template<class T>
class DoubleLinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int m_length;
        void createFirstItem(Node<T>* item){
            item->next = nullptr;
            item->prev = nullptr;
            head = item;
            tail = item;
            m_length = 1;
        };
    public:
        DoubleLinkedList(){
            head = nullptr;
            tail = nullptr;
            m_length = 0;
        }
        DoubleLinkedList(T var)
        {
            Node<T>* temp = new Node<T>;
            temp->variable = var;
            createFirstItem(temp);
        }

        int getLength()const{return m_length;}
        
        void forwardPrintList(){
            Node<T>* temp = head;
            while(temp != nullptr){
                cout<<temp->variable<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void backwardPrintList()
        {
            Node<T>* temp = tail;
            while(temp != nullptr){
                cout<<temp->variable<<" ";
                temp = temp->prev;
            }
            cout<<endl;
        }
        void addFirst(T var)
        {
            Node<T>* temp = new Node<T>;
            temp->variable = var;
            if(m_length == 0){
                createFirstItem(temp);
            }
            else{
                temp->next = head;
                head->prev = temp;
                head = temp;
                temp->prev = nullptr;
                m_length++;
            }
        }
        void addLast(T var){
            Node<T>* temp = new Node<T>;
            temp->variable = var;
            if(m_length == 0)
            {
                createFirstItem(temp);
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                tail->next = nullptr;
                m_length++;
            }
        }
        void deleteFirst(){
            if(m_length == 1){
                head = nullptr;
                tail == nullptr;
            }
            else{
                Node<T>* temp = head;
                temp = temp->next;
                delete head;
                head = temp;
                temp->prev = nullptr;
            }
            m_length--;
        }
        void deleteLast(){
            if(m_length == 1){
                head = nullptr;
                tail == nullptr;
            }
            else{
                Node<T>* temp = tail;
                temp = temp->prev;
                delete tail;
                temp->next = nullptr;
                tail = temp;
            }
            m_length--;

        }
        bool isDoubleListEmpty(){
            bool check = false;
            if(m_length == 0 || head == nullptr || tail == nullptr)
            { 
                check = true;
            }
            return check;
        }
        Node<T>* getIndex(int index){
            if (m_length == 0 || index < 0 || index > m_length) 
            {
                return nullptr;
            }
            Node<T>* temp;
            if(index < m_length / 2){
                temp = head;
                for(int i = 0 ; i < index ; i++)
                {
                    temp = temp->next;
                }
            }
            else{
                temp = tail;
                for(int i = m_length ; i > index ; i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }
};
