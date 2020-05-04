#ifndef __DATA_H__
#define __DATA_H__

#define IPC_MAX_LEN 500
#define OFFSET(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER ) 
struct data
{
    int len;
    char c[IPC_MAX_LEN];
};

#endif
