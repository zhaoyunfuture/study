#ifndef _SMTESTTWO_HPP
#define _SMTESTTWO_HPP

#include "smBase.hpp"
#include <string.h>
#include <string>
#include <iostream>
#include <map>

E_SM_STATE testtwo(){
    cout << "process: test two..." << endl;
    return E_SM_END;
}

class smTestTwo :public smBase {
    public:
        smTestTwo(){
            setSmName("smTestTwo");
            registerFunc(E_SM_START,testtwo);
        }
        virtual ~smTestTwo(){}
        
        virtual E_SM_RET exit(){
            if(E_SM_END == m_state){
                cout << "all finished" << endl;
            }
            return E_SM_OK;
        }
    protected:

    private:
};


#endif
