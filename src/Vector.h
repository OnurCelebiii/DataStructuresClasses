template <class T> class Vector
{
  private:
    T *data;
    int capacity;
    int index;

  public:
    Vector()
    {
        capacity = 1;
        index = 0;
        data = NULL;
        data = new T[capacity];
    }
    int get_capacity() const { return capacity; }

    int get_index() const { return index; }

    void push_back(T var)
    {
        if (index == capacity)
        {
            int newCapacity = capacity * 2;
            T *tempData = new T[newCapacity];
            for (int i = 0; i < index; i++)
            {
                tempData[i] = data[i];
            }
            delete[] data;
            data = tempData;
            capacity = newCapacity;
        }
        data[index] = var;
        index++;
    }

    void push_front(T var)
    {
        if (index == capacity)
        {
            int newCapacity = capacity * 2;
            T *tempData = new T[newCapacity];
            tempData[0] = var;
            for (int i = 0; i < index; i++)
            {
                tempData[i + 1] = data[i];
            }
            delete[] data;
            data = tempData;
            capacity = newCapacity;
        }
        else
        {
            T *tempData = new T[capacity];
            tempData[0] = var;
            for (int i = 0; i < index; i++)
            {
                tempData[i + 1] = data[i];
            }
            delete[] data;
            data = tempData;
        }
        index++;
    }

    void pop_back()
    {
        if (index != 0)
        {
            index--;
        }
        if (index < capacity / 2)
        {
            int newCapacity = capacity / 2;
            if (newCapacity < 1)
            {
                capacity = 1;
            }
            else
            {
                T *tempData = new T[newCapacity];
                for (int i = 0; i < index; i++)
                {
                    tempData[i] = data[i];
                }
                delete[] data;
                data = tempData;
                capacity = newCapacity;
            }
        }
    }

    bool isFind(T var)
    {
        bool find = false;
        for (int i = 0; i < index; i++)
        {
            if (data[i] == var)
            {
                find = true;
            }
        }
        return find;
    }

    void print_vector()
    {
        std::cout << "Vector: " << std::endl;
        for (int i = 0; i < index; i++)
        {
            std::cout << i << ". " << data[i] << std::endl;
        }
    }

    T getValueInIndex(int ind)
    {
        if (ind >= 0 && ind <= index - 1)
        {
            return data[ind];
        }
        else
        {
            return 0;
        }
    }

    T getFirstItem()
    {
        if (index > 0)
        {
            return data[0];
        }
        else
        {
            return NULL;
        }
    }

    T getLastItem()
    {
        if (index > 0)
        {
            return data[index - 1];
        }
        else
        {
            return NULL;
        }
    }

    int sizeVector() { return sizeof(T) * index; }

    T *returnBeginAddress() { return data; }

    T *returnLastElementAddress() { return data + index; }

    void printWithAddress()
    {
        T *first = returnBeginAddress();
        T *last = returnLastElementAddress();
        while (first != last)
        {
            std::cout << *first << std::endl;
            first++;
        }
    }

    T &indexValueChange(int ind)
    {
        if (ind >= 0 && ind < index)
        {
            return data[ind];
        }
        else
        {
            throw "No Valid Index !!";
        }
    }

    T &operator[](int ind)
    {
        if (ind >= 0 && ind < index)
        {
            return data[ind];
        }
        else
        {
            throw "No Valid Index !!";
        }
    }

    void reset_vector()
    {
        delete[] data;
        index = 0;
        capacity = 1;
    }

    void clear_vector()
    {
        reset_vector();
        T *data = new T[capacity];
    }
    void capacity_control()
    {
        if (index == capacity)
        {
            int newCapacity = capacity * 2;
            T *tempData = new T[newCapacity];
            for (int i = 0; i < index; i++)
            {
                tempData[i] = data[i];
            }
            delete[] data;
            data = tempData;
            capacity = newCapacity;
        }
        if (index < capacity / 2)
        {
            int newCapacity = capacity / 2;
            if (newCapacity < 1)
            {
                capacity = 1;
            }
            else
            {
                T *tempData = new T[newCapacity];
                for (int i = 0; i < index; i++)
                {
                    tempData[i] = data[i];
                }
                delete[] data;
                data = tempData;
                capacity = newCapacity;
            }
        }
    }

    void insertUsingIndex(int ind, T var)
    {
        static int counter = 0;
        capacity_control();
        T *tempVect = new T[capacity];
        for (int i = 0; i < index + 1; i++)
        {
            if (ind == i)
            {
                tempVect[i] = var;
            }
            else
            {
                tempVect[i] = data[counter];
                counter++;
            }
        }
        delete[] data;
        data = tempVect;
        index++;
        capacity_control();
    }
    void deleteSpesificIndex(int ind)
    {
        if (ind >= 0 && ind <= index)
        {
            capacity_control();
            static int counter = 0;
            T *tempVect = new T[capacity];
            for (int i = 0; i < index; i++)
            {
                if (ind == i)
                {
                    counter++;
                }
                tempVect[i] = data[counter];
                counter++;
            }
            delete[] data;
            data = tempVect;
            index--;
            capacity_control();
        }
    }
};
