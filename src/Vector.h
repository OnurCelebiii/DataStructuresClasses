template <class T> class Vector
{
  private:
    T *m_data;
    int m_capacity;
    int m_index;

  public:
    Vector()
    {
        m_capacity = 1;
        m_index = 0;
        m_data = new T[m_capacity];
    }
    int get_capacity() const { return m_capacity; }

    int get_index() const { return m_index; }

    void push_back(T var)
    {
        if (m_index == m_capacity)
        {
            int newCapacity = m_capacity * 2;
            T *tempData = new T[newCapacity];
            for (int i = 0; i < m_index; i++)
            {
                tempData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = tempData;
            m_capacity = newCapacity;
        }
        m_data[m_index] = var;
        m_index++;
    }

    void push_front(T var)
    {
        if (m_index == m_capacity)
        {
            int newCapacity = m_capacity * 2;
            T *tempData = new T[newCapacity];
            tempData[0] = var;
            for (int i = 0; i < m_index; i++)
            {
                tempData[i + 1] = m_data[i];
            }
            delete[] m_data;
            m_data = tempData;
            m_capacity = newCapacity;
        }
        else
        {
            T *tempData = new T[m_capacity];
            tempData[0] = var;
            for (int i = 0; i < m_index; i++)
            {
                tempData[i + 1] = m_data[i];
            }
            delete[] m_data;
            m_data = tempData;
        }
        m_index++;
    }

    void pop_back()
    {
        if (m_index != 0)
        {
            m_index--;
        }
        if (m_index < m_capacity / 2)
        {
            int newCapacity = m_capacity / 2;
            if (newCapacity < 1)
            {
                m_capacity = 1;
            }
            else
            {
                T *tempData = new T[newCapacity];
                for (int i = 0; i < m_index; i++)
                {
                    tempData[i] = m_data[i];
                }
                delete[] m_data;
                m_data = tempData;
                m_capacity = newCapacity;
            }
        }
    }

    bool isFind(T var)
    {
        bool find = false;
        for (int i = 0; i < m_index; i++)
        {
            if (m_data[i] == var)
            {
                find = true;
            }
        }
        return find;
    }

    void print_vector()
    {
        std::cout << "Vector: " << std::endl;
        for (int i = 0; i < m_index; i++)
        {
            std::cout << i << ". " << m_data[i] << std::endl;
        }
    }

    T getValueInIndex(int ind)
    {
        if (ind >= 0 && ind <= m_index - 1)
        {
            return m_data[ind];
        }
        else
        {
            return 0;
        }
    }

    T getFirstItem()
    {
        if (m_index > 0)
        {
            return m_data[0];
        }
        else
        {
            return T(0);
        }
    }

    T getLastItem()
    {
        if (m_index > 0)
        {
            return m_data[m_index - 1];
        }
        else
        {
            return T(0);
        }
    }

    int sizeVector() { return sizeof(T) * m_index; }

    T *returnBeginAddress() { return m_data; }

    T *returnLastElementAddress() { return m_data + m_index; }

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
        if (ind >= 0 && ind < m_index)
        {
            return m_data[ind];
        }
        else
        {
            throw "No Valid Index !!";
        }
    }

    T &operator[](int ind)
    {
        if (ind >= 0 && ind < m_index)
        {
            return m_data[ind];
        }
        else
        {
            throw "No Valid Index !!";
        }
    }

    void reset_vector()
    {
        delete[] m_data;
        m_index = 0;
        m_capacity = 1;
    }

    void clear_vector()
    {
        reset_vector();
        m_data = new T[m_capacity];
    }
    void capacity_control()
    {
        if (m_index == m_capacity)
        {
            int newCapacity = m_capacity * 2;
            T *tempData = new T[newCapacity];
            for (int i = 0; i < m_index; i++)
            {
                tempData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = tempData;
            m_capacity = newCapacity;
        }
        if (m_index < m_capacity / 2)
        {
            int newCapacity = m_capacity / 2;
            if (newCapacity < 1)
            {
                m_capacity = 1;
            }
            else
            {
                T *tempData = new T[newCapacity];
                for (int i = 0; i < m_index; i++)
                {
                    tempData[i] = m_data[i];
                }
                delete[] m_data;
                m_data = tempData;
                m_capacity = newCapacity;
            }
        }
    }

    void insertUsingIndex(int ind, T var)
    {
        static int counter = 0;
        capacity_control();
        T *tempVect = new T[m_capacity];
        for (int i = 0; i < m_index + 1; i++)
        {
            if (ind == i)
            {
                tempVect[i] = var;
            }
            else
            {
                tempVect[i] = m_data[counter];
                counter++;
            }
        }
        delete[] m_data;
        m_data = tempVect;
        m_index++;
        capacity_control();
    }
    void deleteSpesificIndex(int ind)
    {
        if (ind >= 0 && ind <= m_index)
        {
            capacity_control();
            static int counter = 0;
            T *tempVect = new T[m_capacity];
            for (int i = 0; i < m_index; i++)
            {
                if (ind == i)
                {
                    counter++;
                }
                tempVect[i] = m_data[counter];
                counter++;
            }
            delete[] m_data;
            m_data = tempVect;
            m_index--;
            capacity_control();
        }
    }
};
