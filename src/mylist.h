#include <stdexcept>
#include <iostream>


template<typename T, int Size = 200>
class MyList {
public:
    explicit MyList();
    MyList(const MyList &o)=delete;
    MyList(const MyList &&o)=delete;
    T& operator=(const MyList &o)=delete;
    T& operator=(const MyList &&o)=delete;
    virtual ~MyList() noexcept;
    T& operator[](int i);
    const T& operator[](int i)const;
    int size()const;

private:
    T *m_array;
};

template<typename T, int Size>
MyList<T,Size>::MyList() {
    if(Size<=0) {
        throw std::out_of_range("Invalid size");
    }
    m_array=new T[Size];
}

template<typename T, int Size>
const T& MyList<T,Size>::operator[](int i) const
{
    if(i<0||i>=Size)
    {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T, int Size>
T& MyList<T,Size>::operator[](int i) {
    if(i<0||i>=Size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template<typename T, int Size>
int MyList<T,Size>::size()const {
    return Size;
}

template<typename T, int Size>
MyList<T,Size>::~MyList() noexcept {
    delete[]m_array;
}

