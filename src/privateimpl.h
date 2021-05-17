#ifndef PRIVATEIMPL_H
#define PRIVATEIMPL_H
#include <memory>

struct MyDataType
{
    MyDataType();
    virtual ~MyDataType() noexcept;

    MyDataType(const MyDataType&) = delete;
    MyDataType& operator=(const MyDataType&) = delete;

    void clear();

private:
    //void process();
    //void foo();
    struct pimpl;
    //pimpl* m_pimpl;
    std::unique_ptr<pimpl> m_pimpl;
};

#endif // PRIVATEIMPL_H
