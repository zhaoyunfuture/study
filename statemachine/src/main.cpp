#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "sm.hpp"
#include "smBase.hpp"
#include "smTestOne.hpp"
#include "smTestTwo.hpp"
using namespace std;

int main(int argc, char* argv[])
{
#if 0
	sm s;
    vector<E_event> vev;
    vev.push_back(E_END);
    vev.push_back(E_START);
    vev.push_back(E_E1);
    vev.push_back(E_END);
    E_ctx* ctx = new E_ctx();
    ctx->v = 1;
    for(unsigned int i=0;i<vev.size();i++)
        s.run(vev.at(i),ctx);
#endif
    std::shared_ptr<smBase> smone(new smTestOne);
    smone->enter(E_SM_START);

    return 0;
}




