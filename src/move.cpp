#include "move.h"

#include <iostream>
#include <stdexcept>

using namespace std;

struct Data {
    Data()
    {
        cout << "Data::Data()" << endl;
    }
    Data(const Data& o)
    {
        cout << "Data::Data(const Data&)" << endl;
    }
    Data& operator=(const Data& o)
    {
        cout << "Data::operator=(const Data&)" << endl;
    }
    ~Data()
    {
        cout << "Data::~Data()" << endl;
    }
};

class MyContainer {
public:
    MyContainer(unsigned int size)
        : m_data{new Data[size]}, m_dim{size}
    {
        cout << "Constructor" << endl;
    }

    ~MyContainer()
    {
        delete[] m_data;
    }

    MyContainer(const MyContainer& o)
        : m_data{new Data[o.m_dim]}, m_dim{o.m_dim}
    {
        cout << "Copy constructor" << endl;
        for (unsigned int i=0; i<m_dim; i++) {
            cout << "Copying data" << endl;
            m_data[i] = o.m_data[i];
        }
    }

    MyContainer& operator= (const MyContainer& o)
    {
        if (o.m_dim > m_dim) throw range_error("Invalid size");
        cout << "Copy assignment operator" << endl;
        for (unsigned int i=0; i<m_dim; i++) {
            cout << "Copying data" << endl;
            m_data[i] = o.m_data[i];
        }
        return *this;
    }

private:
    Data* m_data;
    unsigned int m_dim;
};

MyContainer get()
{
    return MyContainer{3000};
}

void move_run()
{
    MyContainer a{3000};
    MyContainer b{a}; // Copy constructor
    a = b; // Copy assignment
    a = get(); // Copy assignment
}
