#include "move.h"

#include <iostream>
#include <stdexcept>
#include <vector>

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
        return *this;
    }
    Data(Data&& o)
    {
        cout << "Data::Data(Data&&)" << endl;
    }
    Data& operator=(Data&& o)
    {
        cout << "Data::operator=(Data&&)" << endl;
        return *this;
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

    // move constructor
    MyContainer(MyContainer&& o) : m_data{move(o.m_data)}, m_dim{o.m_dim} {
        cout << "Move constructor operator" << endl;
        o.m_data = nullptr;
        o.m_dim = 0;
    }

    // move assignment operator
    MyContainer& operator= (MyContainer&& o) {
        cout << "Move assignment operator" << endl;
        delete[] m_data;
        m_data = move(o.m_data);
        m_dim = o.m_dim;
        o.m_data = nullptr;
        o.m_dim = 0;
        return *this;
    }

private:
    Data* m_data;
    unsigned int m_dim;
};

MyContainer get()
{
    return MyContainer{2};
}

void move_run()
{
    MyContainer a{2};
    MyContainer b{a}; // Copy constructor
    a = b; // Copy assignment operator
    cout << "--- Prima di assegnamento ---\n";
    a = get(); // Move assignment operator
    MyContainer c{get()}; // Return Value Optimization
    cout << "--- Fine di move_run ---\n";
    a = move(b);


    // Spostamento di dati dentro a un contenitore
    std::vector<Data> x;
    x.reserve(10);
    for (int i{0}; i<10; ++i) {
        x.emplace_back(Data{});
        // oppure x.emplace_back(move(Data{}));
    }

    // Spostamento di dati tra contenitori
    std::vector<Data> y;
    cout << "Copia di dati tra contenitori\n";
    y = x; // copia
    cout << "y.size()=" << y.size() << " x.size()=" << x.size() << '\n';
    cout << "Spostamento di dati tra contenitori\n";
    y = move(x); // spostamento (std::move "genera" una r-value a partire da una l-value)
    cout << "y.size()=" << y.size() << " x.size()=" << x.size() << '\n';

}
