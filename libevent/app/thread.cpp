#include <thread>  
#include <string> 

    void my_thread()  
    {  
        puts("hello, world");  
    }  
      
    int main(int argc, char *argv[])  
    {  
        std::thread t(my_thread);  
        t.join();  
      
        system("pause");  
        return 0;  
    } 
