#include <iostream>

// Node Struct
template <class T> struct Node
{
    T variable;
    Node *next;
};

// LinkedList Class
template <class T> class LinkedList
{
  private:
    int index;
    Node<T> *tail;
    Node<T> *head;

    void emptyListAddNode(Node<T> *var)
    {
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

    LinkedList(T var)
    {
        Node<T> *temp = new Node<T>;
        temp->variable = var;
        temp->next = nullptr;
        emptyListAddNode(temp);
        index = 1;
    }

    const int getIndex() { return index; }

    const bool isEmpty() { return (index == 0 || head == nullptr); }

    void push_back(T var)
    {
        Node<T> *temp = new Node<T>;
        temp->variable = var;
        temp->next = nullptr;
        if (head == nullptr || index == 0)
        {
            emptyListAddNode(temp);
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        index++;
    }

    void push_front(T var)
    {
        Node<T> *temp = new Node<T>;
        temp->variable = var;
        temp->next = nullptr;
        if (head == nullptr || index == 0)
        {
            emptyListAddNode(temp);
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        index++;
    }

    void print_list()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->variable << std::endl;
            temp = temp->next;
        }
    }

    bool search(T var)
    {
        Node<T> *temp = head;
        bool find = false;
        while (temp != nullptr)
        {
            if (temp->variable == var)
            {
                find = true;
            }
            temp = temp->next;
        }
        return find;
    }

    void deleteLast()
    {
        if (!isEmpty())
        {
            Node<T> *currentNode = head;
            Node<T> *previousNode = head;
            while (currentNode->next != nullptr)
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

    void deleteFirst()
    {
        if (!isEmpty())
        {
            Node<T> *temp = head;
            temp = temp->next;
            delete head;
            head = temp;
            index--;
        }
    }

    void deleteIndex(int ind)
    {
        if (!isEmpty())
        {
            if (ind == 1)
            {
                deleteFirst();
            }
            else if (ind == index)
            {
                deleteLast();
            }
            else
            {
                static int counter = 1;
                Node<T> *currentAddr = head;
                Node<T> *prevAddr = head;

                while (counter < ind)
                {
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
    Node<T> *searchReturnAddr(T var)
    {
        Node<T> *returnAddr = nullptr;
        Node<T> *currentAddr = head;
        while (currentAddr != nullptr)
        {
            if (currentAddr->variable == var)
            {
                returnAddr = currentAddr;
            }
            currentAddr = currentAddr->next;
        }
        return returnAddr;
    }

    void deleteValue(T val)
    {
        if (search(val) == true)
        {
            if (head->variable == val)
            {
                deleteFirst();
            }
            else if (tail->variable == val)
            {
                deleteLast();
            }
            else
            {
                Node<T> *current = head;
                Node<T> *prev = head;
                while (current != nullptr)
                {
                    if (current->variable == val)
                    {
                        break;
                    }
                    prev = current;
                    current = current->next;
                }
                prev->next = current->next;
                delete current;
            }
        }
    }

    void insertAfterIndex(T var, int ind)
    {

        if (ind < 1 || ind > index + 1)
        {
            return;
        }
        Node<T> *temp = new Node<T>;
        temp->variable = var;
        temp->next = nullptr;
        if (ind == 1)
        {
            temp->next = head->next;
            head->next = temp;
        }
        else
        {
            Node<T> *current = head;
            int counter = 1;

            while (counter < ind)
            {
                current = current->next;
                counter++;
            }

            temp->next = current->next;
            current->next = temp;
        }
        index++;
    }
};
