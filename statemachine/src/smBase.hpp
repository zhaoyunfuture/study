#ifndef _SMBASE_HPP
#define _SMBASE_HPP


#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <memory>

typedef enum _sm_ret{
    E_SM_OK = 0,
    E_SM_ERR
}E_SM_RET;

typedef enum _sm_state{
    E_SM_TEST_ONE = 0,
    E_SM_TEST_TWO = 0,
    E_SM_END
}E_SM_STATE;

typedef enum _sm_event{
    E_SM_START = 0,
    E_SM_TIMEOUT,
    E_SM_STOP
}E_SM_EVENT;

typedef E_SM_STATE (*SM_FUNC) ();

class smBase {
    public:
        smBase(){}
        virtual ~smBase(){}

        virtual E_SM_RET enter(E_SM_EVENT event){ 
            cout << "enter " << getSmName()<< " ,with event: " << event <<endl;
            setCurEvent(event);
            run();
            return E_SM_OK;
        }
        virtual E_SM_RET run() {
            cout << "run " << getSmName()<< endl;
            SM_FUNC func = NULL;
            func = getFunc(getCurEvent());
            if(func){
                m_state = func();
            }
            return exit();
        }
        virtual E_SM_RET exit(){ 
            cout << "exit " << getSmName()<< endl;
            return E_SM_OK;
        }
        
        void setSmName(std::string name){m_smName=name;}
        std::string getSmName(){return m_smName;}
        void setCurEvent(E_SM_EVENT event){m_event = event;}
        E_SM_EVENT getCurEvent(){return m_event;}

        void registerFunc(E_SM_EVENT event, SM_FUNC func){
            std::map<E_SM_EVENT,SM_FUNC>::iterator it;
            it = m_evtFuncMap.find(event);
            if(it != m_evtFuncMap.end()){
                cout<< "event " << event << "has registed" << endl;
                return;
            }else{
                m_evtFuncMap.insert(std::pair<E_SM_EVENT,SM_FUNC>(event,func));
            }
        }
        SM_FUNC getFunc(E_SM_EVENT event){
            std::map<E_SM_EVENT,SM_FUNC>::iterator it;
            it = m_evtFuncMap.find(event);
            if(it != m_evtFuncMap.end()){
                return it->second;
            }
            return NULL;
        }
    protected:
        E_SM_STATE m_state;
    private:
        E_SM_EVENT m_event;
        std::map<E_SM_EVENT,SM_FUNC> m_evtFuncMap;
        std::string m_smName;
};


#endif
