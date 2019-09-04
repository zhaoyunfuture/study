#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
        // It's the unique ID of each node.
        //     // unique id of this employee
        //         int id;
        //             // the importance value of this employee
        //                 int importance;
        //                     // the id of direct subordinates
        //                         vector<int> subordinates;
        //                         };

class Solution {
public:
    void storeSub(vector<Employee*> employees,set<int>& s,int id){
        int size = 0;
        for(int i=0;i<employees.size();++i){
            if(employees.at(i)->id == id){
                size = employees.at(i)->subordinates.size();
                if(size == 0)
                    return;
                else{
                    for(int j=0;j<size;++j){
                        s.insert(employees.at(i)->subordinates.at(j));
                        storeSub(employees,s,employees.at(i)->subordinates.at(j));
                    }
                }
            }

        }
    }
    int importanceID(vector<Employee*> employees, int id){
        for(int i=0;i<employees.size();++i){
            if(employees.at(i)->id == id)
                return employees.at(i)->importance;
        }
        return 0;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        set<int> s;
        for(int i=0;i<employees.size();++i){
            if(employees.at(i)->id == id){
                sum += employees.at(i)->importance;
                storeSub(employees,s,id);
                for (set<int>::iterator it=s.begin(); it!=s.end(); ++it){
                    sum +=importanceID(employees,*it);
                }                               
            }
        }
        return sum;        
    }
};

int main(int argc, char* argv[])
{
  
	return 0;
}




