#include <string.h>
#include <string>
#include <iostream>
class KthLargest {
	public:
		struct comp {
			bool operator() (const int& lhs, const int& rhs) const
			{return lhs>rhs;}
		};
		KthLargest(int k, vector<int>& nums) {
			kth = k;
			m.clear();
			int size = nums.size();
			if(size == 0)
				return ;
			for(int i=0;i<size;++i){
				mit = m.find(nums.at(i));
				if(mit == m.end()){
					m.insert(pair<int,int>(nums.at(i),1));
				}else{
					mit->second ++;
				}
			}        
		}

		int add(int val) {
			mit = m.find(val);
			int index=0;
			int output=0;
			if(mit == m.end()){
				m.insert(pair<int,int>(val,1));
			}else{
				mit->second ++;
			}
			for(mit =m.begin();mit!=m.end();mit++){
				index += mit->second;
				if(index < kth)
					continue;
				else if(index == kth){
					output = mit->first;
					break;
				}
				else {
					output = mit->first;
					break;
				} 
			}
			return output;
		}

		int kth;
		map<int,int,comp> m;
		map<int,int,comp>::iterator mit;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */using namespace std;

int main(int argc, char* argv[])
{
  
	return 0;
}




