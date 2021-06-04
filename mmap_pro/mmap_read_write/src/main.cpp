#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct shareFile{
    char* buf;
    uint32_t size;
};

static struct shareFile * s_file;
const char* file_path = "../share_file";

int main(int argc, char* argv[])
{
    s_file = (struct shareFile *)malloc(sizeof(struct shareFile));
    memset(s_file,0,sizeof(struct shareFile));
    struct stat st;
    
    int fd = open(file_path,O_RDWR);
    cout << "fd: " << fd << endl;
    
    int ret = fstat(fd,&st);
    cout << "ret: " << ret << endl;

    s_file->buf =(char*) mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    cout << s_file->buf << endl;

    s_file->size = st.st_size;
    cout << "st.st_size " << st.st_size << endl;

    close(fd);
    std::string str1 = "jacob";
    std::string str2 = "peter";
    std::string str3 = "tony";
    int i = 0;
    cin >> i ;
    while(i){
        cout << "you key it: " << i << endl;
        if(i==1){
            memcpy(s_file->buf,str1.c_str(),strlen(str1.c_str()));
        }
        if(i==2){
            memcpy(s_file->buf,str2.c_str(),strlen(str2.c_str()));
        }
        if(i==3){
            memcpy(s_file->buf,str3.c_str(),strlen(str3.c_str()));
        }
        cin >> i;
    }
	return 0;
}




