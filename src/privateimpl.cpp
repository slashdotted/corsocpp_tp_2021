#include "privateimpl.h"
#include <string>
#include <map>

static void foo(int& m_tag);
static void process(int& m_tag, std::map<std::string,std::string>& m_container);
struct MyDataType::pimpl {
    std::map<std::string,std::string> m_container;
    int m_tag;
    double m_value;
};

//MyDataType::MyDataType() : m_pimpl{new pimpl} {}
MyDataType::MyDataType() : m_pimpl{std::make_unique<pimpl>()} {}

/*MyDataType::~MyDataType() noexcept {
    delete m_pimpl;
}*/

MyDataType::~MyDataType() noexcept = default;

/*void MyDataType::foo() {
    m_pimpl->m_tag = 16;
}

void MyDataType::process()
{
    m_pimpl->m_tag = 1;
    m_pimpl->m_container["mykey"] = "myvalue";
}*/

void MyDataType::clear()
{
    m_pimpl->m_tag = 0;
    m_pimpl->m_container.clear();
    process(m_pimpl->m_tag, m_pimpl->m_container);
}


static void foo(int& m_tag) {
    m_tag = 16;
}

static void process(int& m_tag, std::map<std::string,std::string>& m_container)
{
    m_tag = 1;
    m_container["mykey"] = "myvalue";
}