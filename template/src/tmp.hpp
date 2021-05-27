#ifndef _TMP_HPP_
#define _TMP_HPP_

#include <list>

#include "allocA.hpp"
#include "allocB.hpp"

template <typename alloc = ::allocA >
class tmp {
    public:
        tmp(alloc* a=0):m_alloc(a) {}
    //private:
        alloc* m_alloc;
};

typedef tmp<> t_tmp;

class insta :public t_tmp {
    public:
};


typedef const char* myString;

template<typename VAL_TYPE>
class listWrapper : public std::list<VAL_TYPE> {
protected:
    bool m_available;

public:
    listWrapper():std::list<VAL_TYPE>(), m_available(false) {}
    virtual ~listWrapper() {}
    virtual void freeVal() {}
    listWrapper(const listWrapper& rhs): std::list<VAL_TYPE>(rhs), m_available(rhs.m_available){}
    listWrapper& operator=(const listWrapper& rhs){
        std::list<VAL_TYPE>::operator=(rhs);
        m_available = rhs.m_available;
        return *this;
    }

    void clean(){
        freeVal();
        std::list<VAL_TYPE>::clear();
        m_available = false;
    }

    void push_back(const VAL_TYPE& rhs){
        std::list<VAL_TYPE>::push_back(rhs);
        m_available = true;
    }

    bool available() const { return m_available; }
};

class myStringlist : public listWrapper<myString> {
private:
    virtual void freeVal() {
        for(myStringlist::iterator it = begin(); it != end(); it ++) {
            if( NULL != (*it) ){
                delete [] (*it);
                (*it) = NULL;
            }
        }
    }
    void clone(const myStringlist& rhs) {
        for(myStringlist::const_iterator it = rhs.begin(); it != rhs.end(); it ++) {
            push_back(*it);
        }
        m_available = rhs.m_available;
    }
    
public:
    myStringlist():listWrapper<myString>(){}
    virtual ~myStringlist(){
        clean();
    }
    myStringlist(const myStringlist& rhs): listWrapper<myString>() {
        clone(rhs);
    }
    myStringlist& operator=(const myStringlist& rhs) {
        clone(rhs);
        return *this;
    }
    void push_back(const myString& rhs){
        char* p = NULL;
        if(NULL != rhs){
            p = new char[strlen(rhs)+1];
            strcpy(p,rhs);
        }
        listWrapper<myString>::push_back(p);
        m_available = true;
    }
};



#endif
