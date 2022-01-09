#if !defined(t_HPP)
#define t_HPP
#include <string.h>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
typedef function<int()> func;

class a{
    public:
        a(){m_a = 0;}
        a(int a) {m_a = a;}
        a(const a& rhs){
            m_a = rhs.m_a;
        }
        void set(int a){m_a = a;}
        int get(){return m_a;}
    private:
        int m_a;
};

class t
{
    public:
        t(){
            m_a = 0;
            p_a = nullptr;
        }
        t(int a){
            cout << "con" << endl;
            m_a = a;
            p_a = nullptr;
        }
        ~t() {}
        t(const a& ra) {
            cout << "copy con" << endl;
            p_a = new a(ra);
        }
        t(t&& from){
            cout << "move con" << endl;
            m_a = from.m_a;
            p_a = from.p_a;
            from.m_a = 0;
            from.p_a = nullptr;
        }
        t& operator=(const t& rhs){
            cout << "op const &" << endl;
            m_a = rhs.m_a;
            if(rhs.p_a)
                p_a = new a(*rhs.p_a);
            else
                p_a = nullptr;
            return *this;
        }
        t& operator=(t&& rhs){
            cout << "op move &&" << endl;
            m_a = rhs.m_a;
            p_a = rhs.p_a;
            rhs.m_a = 0;
            rhs.p_a = nullptr;
            return *this;
        }
        int get() {return m_a;}
        void set(int a);
        void setPtr(a* p){p_a = p;}
        a* getPtr(){return p_a;}
        func getbyfunc();
        bool validPtr(){return p_a?true:false;}
    private:
        int m_a;
        a* p_a;
};

#endif
