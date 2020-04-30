#include "sm.hpp"

static void nullfunc(sm* s,E_event e,E_ctx* ctx){
    cout <<"[" << __FUNCTION__ << "]" <<"current state:[" << s->getStateName()<< "] with event:[" << s->getEventName(e) << "]"<< endl;
    cout << "do nothing"<< endl;
}

static void begin(sm* s,E_event e,E_ctx* ctx){
    cout <<"[" << __FUNCTION__ << "]" <<"current state:[" << s->getStateName()<< "] with event:[" << s->getEventName(e) << "]"<< endl;
    
    if(ctx->v == 1)
        s->setState(E_S1);
    else if(ctx->v == 2)
        s->setState(E_S2);
    else
        s->setState(E_IDLE);
}

static void end(sm* s,E_event e,E_ctx* ctx){
    cout <<"[" << __FUNCTION__ << "]" <<"current state:[" << s->getStateName()<< "] with event:[" << s->getEventName(e) << "]"<< endl;
    s->setState(E_IDLE);
}

static void next(sm* s,E_event e,E_ctx* ctx){
    cout <<"[" << __FUNCTION__ << "]" <<"current state:[" << s->getStateName()<< "] with event:[" << s->getEventName(e) << "]"<< endl;
    s->setState(E_S2);
}

static PTRFUN lookup[E_state_bottom][E_event_bottom] 
{
    begin,nullfunc,end, /* E_IDLE */
    nullfunc,next,end, /* E_S1 */
    nullfunc,nullfunc,end  /* E_S2 */
};

E_ret sm::run(E_event event,E_ctx* ctx)
{
   PTRFUN f;
   f = lookup[m_state][event];
   if(f)
       f(this,event,ctx);
   return E_OK;
}

void sm::setState(E_state state)
{
    m_state = state;
    cout <<"[" << __FUNCTION__ << "]" <<"update state:[" << getStateName()<< "]"<< endl;
}
