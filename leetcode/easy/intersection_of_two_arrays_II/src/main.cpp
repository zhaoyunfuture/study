#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#if 0
class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			vector<int> v;
			if(nums1.size()==0 || nums2.size()==0)
				return v;
			map<int,int(*)[2]> m;
			map<int,int(*)[2]>::iterator mit;
			int a[2] = {0};
			for(int i=0;i<nums1.size();++i){
				mit = m.find(nums1.at(i));
				if(mit == m.end()) {
					a[0] = 1;
					a[1] = 0;
					m.insert(pair<int,int(*)[2]>(nums1.at(i),&a));
				}else {
					(*(mit->second))[0] +=1;
				}
			}

			for(int j=0;j<nums2.size();++j){
				mit = m.find(nums2.at(j));
				if(mit == m.end()) {
					a[0] = 0;
					a[1] = 1;
					m.insert(pair<int,int(*)[2]>(nums2.at(j),&a));
				}else {
					(*(mit->second))[1] +=1;
				}
			}
			int n1 = 0;
			int n2 = 0;
			int con = 0;
			for(mit = m.begin();mit!=m.end();++mit){
				n1 = (*(mit->second))[0];
				n2 = (*(mit->second))[1];
				cout << "val:" << mit->first << " n1:" << n1 << " n2:" << n2 <<endl;
				if( n1!= 0 && n2!= 0 ){
					con = n1>n2?n2:n1;
					for(;con>0;--con)
						v.push_back(mit->first);
				}
			}
			return v;            
		}
};
#endif

class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			vector<int> v;
			if(nums1.size()==0 || nums2.size()==0)
				return v;
			map<int,vector<int>> m;
			map<int,vector<int>>::iterator mit;
			int a[2] = {0};
			for(int i=0;i<nums1.size();++i){
				vector<int> t;
				mit = m.find(nums1.at(i));
				if(mit == m.end()) {
					t.push_back(1);
					t.push_back(0);                
					m.insert(pair<int,vector<int>>(nums1.at(i),t));
				}else {
					(mit->second).at(0) +=1;
				}
			}

			for(int j=0;j<nums2.size();++j){
				vector<int> r;
				mit = m.find(nums2.at(j));
				if(mit == m.end()) {
					r.push_back(0);
					r.push_back(1);           
					m.insert(pair<int,vector<int>>(nums2.at(j),r));
				}else {
					(mit->second).at(1) +=1;
				}
			}
			int n1 = 0;
			int n2 = 0;
			int con = 0;
			for(mit = m.begin();mit!=m.end();++mit){
				n1 = (mit->second).at(0);
				n2 = (mit->second).at(1);
				cout << "val:" << mit->first << " n1:" << n1 << " n2:" << n2 <<endl;
				if( n1!= 0 && n2!= 0 ){
					con = n1>n2?n2:n1;
					for(;con>0;--con)
						v.push_back(mit->first);
				}
			}
			return v;            
		}
};

int main(int argc, char* argv[])
{
  
	return 0;
}




