#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class LFUCache {
public:
    typedef struct{
        int hit;
        int stamp;
    }T_info;
    typedef struct{
        T_info info;
        int value;
    }T_val;
    struct classcomp {
        bool operator() (const T_info& lhs, const T_info& rhs) const
        { 
            if(lhs.hit==rhs.hit){
                return lhs.stamp<rhs.stamp;
            }
            return lhs.hit<rhs.hit;
        }
    };
    int cap;
    map<int,T_val> kv;
    map<int,T_val>::iterator kv_iter;
    map<T_info,int,classcomp> lfu;
    map<T_info,int,classcomp>::iterator lfu_iter;
    LFUCache(int capacity) {
        cap = capacity;
        kv.clear();
        lfu.clear();
    }
    
    int get(int key) {
        kv_iter = kv.find(key);
        if(kv_iter == kv.end())
            return -1;
        else{
            kv_iter->second.info.hit++;
            kv_iter->second.info.stamp = clock();
        }
        return kv_iter->second.value;
    }
    void findlfu(){
        lfu.clear();
        for(kv_iter = kv.begin();kv_iter!=kv.end();kv_iter++){
            T_info info;
            info.hit = kv_iter->second.info.hit;
            info.stamp = kv_iter->second.info.stamp;
            lfu.insert(pair<T_info,int>(info,kv_iter->first));
        }
    }
    void put(int key, int value) {
        int size = kv.size();
        if(cap==0)
            return;
        if(size<cap){
            kv_iter = kv.find(key);
            if(kv_iter == kv.end()){
                T_val val;
                val.info.hit = 1;
                val.info.stamp = clock();
                val.value = value;
                kv.insert(pair<int,T_val>(key,val));
            }else{
                kv_iter->second.info.hit++;
                kv_iter->second.info.stamp = clock();
                kv_iter->second.value = value;
            }
        }else{
            kv_iter = kv.find(key);
            if(kv_iter != kv.end()){
                kv_iter->second.info.hit++;
                kv_iter->second.info.stamp = clock();
                kv_iter->second.value = value;   
            }else{
                findlfu();
                lfu_iter = lfu.begin();
                kv.erase(lfu_iter->second);
                T_val val;
                val.info.hit = 1;
                val.info.stamp = clock();
                val.value = value;
                kv.insert(pair<int,T_val>(key,val));
            }            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char* argv[])
{
  
	return 0;
}




