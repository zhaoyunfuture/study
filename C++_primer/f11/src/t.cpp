#include "t.hpp"

func t::getbyfunc()
{
    return bind(&t::get,this);
};
void t::set(int a)
{
    m_a = a;
}
