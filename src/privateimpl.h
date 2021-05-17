#ifndef PRIVATEIMPL_H
#define PRIVATEIMPL_H

#include <string>
#include <map>

struct MyDataType
{
    void process();
    void clear();

private:
    std::map<std::string,std::string> m_container;
    std::string m_tag;
};

#endif // PRIVATEIMPL_H
