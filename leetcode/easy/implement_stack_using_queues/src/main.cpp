#include <string.h>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
class MyStack {
	public:
		/** initialize your data structure here. */
		MyStack() {        
		}

		void push(int x) {
            if(a.size())
                a.push(x);
            else
                b.push(x);
	    }

		void pop() {
		    if(a.size()==0&&b.size()==0)
		        return;

	        if(a.size())
            {
                while(a.size())
                {
                    if(a.size()!=1)
                        b.push(a.front());
                    a.pop();
                }
                return;
            }
            else
            {
                while(b.size())
                {
                    if(b.size()!=1)
                        a.push(b.front());
                    b.pop();
                }
            }
		}

		int top() {
            if(a.size())
                return a.back();
            else
                return b.back();
		}
        
        bool empty() {
            return a.empty() && b.empty();
        }
	private:
		queue<int> a;
		queue<int> b;
};
int main(int argc, char* argv[])
{
    queue<int> stack;
    cout << stack.front() << endl;
    stack.push(1);
    stack.push(2);
    cout << stack.front() << endl;
    cout << stack.front() << endl;
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();
    cout << s.empty() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;

	return 0;
}




