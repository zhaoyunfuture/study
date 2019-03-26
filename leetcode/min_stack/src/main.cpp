#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {        
		}

		void push(int x) {
			stack.push_back(x);  
			if(min.size() == 0)
				min.push_back(x);
			else
			{   
				for(vector<int>::iterator it=min.begin();it!=min.end();++it)
				{
					if(x < *it)
					{
						min.insert(it,x);
						break;
					}
					if(it+1 == min.end())
					{
						min.push_back(x);
						break;
					}
				}
			}
		}

		void pop() {
			int a = *(stack.rbegin());
			stack.pop_back();
			for(vector<int>::iterator it=min.begin();it!=min.end();++it)
			{
				if(*it == a)
				{
					min.erase(it);
					break;
				}               
			}        
		}

		int top() {
			return *(stack.rbegin());
		}

		int getMin() {
			return *(min.begin());        
		}
	private:
		vector<int> stack;
		vector<int> min;
};
int main(int argc, char* argv[])
{
  
	return 0;
}




