#ifndef __SM_HPP__
#define __SM_HPP__

#include <string.h>
#include <string>
#include <iostream>
using namespace std;

typedef enum{
    E_IDLE,
    E_S1,
    E_S2,
    E_state_bottom
}E_state;

typedef enum{
    E_START,
    E_E1,
    E_END,
    E_event_bottom
}E_event;

static string gEventName[] = {
    "E_START",
    "E_E1",
    "E_END"
};

static string gStateName[] = {
    "E_IDLE",
    "E_S1",
    "E_S2"
};

typedef struct{
    int v;
}E_ctx;

typedef enum{
    E_OK,
    E_NOK
}E_ret;

class sm;
typedef void (*PTRFUN)(sm*,E_event,E_ctx*);

class sm
{
    public:
        sm(){m_state=E_IDLE;}
        sm(E_state state):m_state(state){};
        ~sm(){};
        E_ret run(E_event event,E_ctx* ctx);
        void setState(E_state state);

        /*********debug*************/
        string getStateName(){return gStateName[m_state];}
        string getEventName(E_event e){return gEventName[e];}
    private:
        E_state m_state;
};

#endif



