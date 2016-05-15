/*************************************************************************
    > File Name: bufcpy.cpp
    > Author: Jacob
    > Mail: zyfuture@qq.com 
    > Created Time: 2016年05月14日 星期六 10时28分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#define MAX_BUF_LENGTH 256
using namespace std;

class CBufTest {
public:
	static CBufTest *get_instance();
	int setBuf(const char * p_data,int length);
	char * getBuf(){return buf;};
	std::string &getStr(){return str;};
	int * &getint(){return pint;};
	std::vector<std::string> &getvname(){return vname;};
private:
	static CBufTest * pCBufTest;
	char buf[MAX_BUF_LENGTH];
	std::string str; 
	int * pint;
	std::vector<std::string> vname;
};
