#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
			if(rec1.at(0)<rec2.at(0)){
				if(rec1.at(2)<=rec2.at(0))
					return false;
				else {
					if(rec1.at(3)<=rec2.at(1) || rec1.at(1)>=rec2.at(3))
						return false;
					else
						return true;
				}
			}else if(rec1.at(0) == rec2.at(0)){
				if(rec1.at(3)<=rec2.at(1) || rec1.at(3)>=rec2.at(3))
					return false;
				else
					return true;
			}else {
				if(rec1.at(0) >= rec2.at(2))
					return false;
				else {
					if(rec1.at(1) >= rec2.at(3))
						return false;
					else {
						if(rec1.at(1)<=rec2.at(1)) {
							if(rec1.at(3)>=rec2.at(1))
								return true;
							else
								return false;
						}else
							return true;                        
					}
				}                    
			}
		}
};

int main(int argc, char* argv[])
{

	return 0;
}

class Solution {
	public:
		bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
			if(rec1[0]>=rec2[2] || rec1[2]<=rec2[0])return false;
			if(rec1[1]>= rec2[3] || rec1[3]<= rec2[1]) return false;
			return true;
		}
};


