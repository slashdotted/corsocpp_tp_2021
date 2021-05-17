#include "privateimpl.h"

void MyDataType::process()
{
    m_tag = "processed";
    m_container["mykey"] = "myvalue";
}

void MyDataType::clear()
{
    m_tag.clear();
    m_container.clear();
}
