#ifndef _SMTESTONE_HPP
#define _SMTESTONE_HPP

#include "smBase.hpp"
#include "smTestTwo.hpp"
#include <string.h>
#include <string>
#include <iostream>
#include <map>

E_SM_STATE testone(){
    cout << "process: test one..." << endl;
    return E_SM_TEST_TWO;
}

class smTestOne :public smBase {
    public:
        smTestOne(){
            setSmName("smTestOne");
            registerFunc(E_SM_START,testone);
        }
        virtual ~smTestOne(){}
        
        virtual E_SM_RET exit(){
            cout << "m_state " << m_state << endl;
            if(E_SM_TEST_TWO == m_state){
                std::shared_ptr<smBase> smtwo(new smTestTwo);
                smtwo->enter(E_SM_START);
            }
            return E_SM_OK;
        }
    protected:

    private:
};


#endif
