#include <string.h>
#include <string>
#include <iostream>
using namespace std;
//for all positive
int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
}
//for negtive and positive
int getSum(int a, int b) {
    int carry=0,sum,res=0,k=0;
    while(a!=0 ||  b!=0 || k<32 )
    {
        int x=(a&1)!=0?1:0;
        int y=(b&1)!=0?1:0;
        a>>=1;
        b>>=1;

        sum=(x+y+carry)%2;
        carry=(x+y+carry)/2;
        sum=sum<<k;
        res=res|sum;
        k++;
        if(k>31)
            break;       
    } 
    return res;
}

int main(int argc, char* argv[])
{
    cout << getSum(3,4) << endl;  
	return 0;
}




