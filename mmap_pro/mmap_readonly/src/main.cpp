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
    
    int fd = open(file_path,O_RDONLY);
    cout << "fd: " << fd << endl;
    
    int ret = fstat(fd,&st);
    cout << "ret: " << ret << endl;

    s_file->buf =(char*) mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    cout << s_file->buf << endl;

    s_file->size = st.st_size;
    cout << "st.st_size " << st.st_size << endl;

    close(fd);
    int i = 0;
    cin >> i ;
    while(i){
        cout << "you key it: " << i << endl;
        if(i==1){
           cout << s_file->buf << endl; 
        }
        cin >> i;
    }
	return 0;
}




