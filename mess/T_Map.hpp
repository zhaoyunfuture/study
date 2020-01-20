#ifndef __T_MAP_HPP_
#define __T_MAP_HPP_
#include <string>
using namespace std;
#if 1
#define __DEBUG__
typedef unsigned int     uint32_t;
#endif

namespace formatmgnt
{
template <typename _Key, typename _Tp>

class T_Map
{
public:
    typedef _Key                  key_type;
    typedef _Tp                   data_type;
    typedef pair<const _Key, _Tp> value_type;
    typedef uint32_t (*_hasherFunc)(_Key key);

    class T_Node
    {
    public:
        _Key key_m;
        _Tp  info_m;
        bool isused_m;
        T_Node *next_m;
        T_Node()
        {
            isused_m = false;
            next_m = NULL;
        }
        T_Node(const T_Node &arg)
        {
            key_m = arg.key_m;
            info_m = arg.info_m;
            isused_m = arg.isused_m;
            next_m = arg.next_m;
        }
        
        T_Node& operator=(const T_Node& arg)
        {
            key_m = arg.key_m;
            info_m = arg.info_m;
            isused_m = arg.isused_m;
            next_m = arg.next_m;
        }
    };
    typedef struct
    {
        uint32_t dwTraveIndex;
        T_Node *pCurrentPtr;
    } T_TraveInfo;
private:
    _hasherFunc hasher;
    size_t  totalsize_m; //the size of
    T_Node *pArray;
    size_t  number_m;
    T_TraveInfo traver;

public:
    T_Map(size_t size_i, _hasherFunc hashFunc)
    {
        if((0 == size_i)||(NULL==hashFunc))
        {
            printf("input parameter error !size_i = %d, hashFunc = %p \n",size_i,hashFunc);
            exit(-1);
        }
        pArray = new T_Node[size_i];
        if(NULL == pArray)
        {
            printf("[%s:%d] out of memory\n",__FILE__, __LINE__);
            exit(-1);
        }
        totalsize_m = size_i;
        hasher = hashFunc;
        number_m = 0;
        memset(&traver,0,sizeof(traver));
    }

    T_Map(const T_Map<_Key,_Tp> &arg)
    {
        hasher = arg.hasher;
        totalsize_m = arg.totalsize_m;
        number_m = arg.number_m;
        traver = arg.traver;
        for(size_t i = 0; i < totalsize_m; i++)
        {
            if(false == arg.pArray[i].isused_m)
            {
                continue;
            }
            pArray[i] = arg.pArray[i];
            T_Node *currNode = &pArray[i];
            for(T_Node *confict=currNode->next_m; confict!=NULL; confict=confict->next_m)
            {
                T_Node *newNode = allocNode();
                *newNode = *confict->next_m;
                newNode.next_m = NULL;
                currNode.next_m = newNode;
                currNode = newNode;
            }
        }
    }

    ~T_Map()
    {
        for(size_t i = 0; i < totalsize_m; i++)
        {
            if(false == pArray[i].isused_m)
            {
                continue;
            }
            T_Node *currNode = &pArray[i];
            for(T_Node *confict=currNode->next_m; confict!=NULL;)
            {
                currNode = confict;
                confict = currNode->next_m;
                deallocNode(currNode);
            }
        }
        delete []pArray;
        pArray = NULL;
    }

    T_Node *allocNode()
    {
#ifdef __DEBUG__
        T_Node *p = new T_Node;
#else
        ;
#endif
        if(NULL == p)
        {
            printf("[%s:%d] out of memory\n",__FILE__, __LINE__);
            exit(-1);
        }
        return p;
    }

    void deallocNode(T_Node *p)
    {
        p->isused_m = false;
#ifdef __DEBUG__
        delete p;
#else
        ;
#endif
        return;
    }


    bool insert(const pair<const _Key, _Tp> node)
    {
        uint32_t index = hasher(node.first);
        if(index > totalsize_m)
        {
            printf("hasher func definiciton error! \n");
            return false;
        }
        T_Node *currNode = &pArray[index];
        if(false == currNode->isused_m)
        {
            currNode->key_m = node.first;
            currNode->info_m = node.second;
            currNode->isused_m = true;
            currNode->next_m = NULL;
        }
        else
        {
            //same key exist? so go through the conflict list.
            for(; currNode!=NULL;)
            {
                if(currNode->key_m == node.first)
                {
                    printf("the node has been exist in map\n");
                    currNode->info_m = node.second;
                    break;
                }
                if(NULL == currNode->next_m)
                {
                    T_Node *newNode = allocNode();
                    currNode->next_m = newNode;
                    newNode->key_m = node.first;
                    newNode->info_m = node.second;
                    newNode->isused_m = true;
                    currNode = newNode->next_m;
                }
                else
                {
                    currNode = currNode->next_m;
                }
            }
        }
        return true;
    }

    T_Node* find(const _Key& key)
    {
        T_Node *pfind = NULL;
        uint32_t index = hasher(key);
        if(index > totalsize_m)
        {
            printf("hasher func definiciton error! \n");
            return NULL;
        }
        T_Node *currNode = &pArray[index];
        for(; currNode!=NULL;)
        {
            if(currNode->key_m == key)
            {
                printf("the currNode has been exist in map \n");
                pfind = currNode;
                break;
            }
            {
                currNode = currNode->next_m;
            }
        }
        return pfind;
    }

    bool erase(const _Key& key)
    {
        bool ret = false;
        T_Node *pfind = NULL;
        uint32_t index = hasher(key);
        if(index > totalsize_m)
        {
            printf("hasher func definiciton error! \n");
            return false;
        }
        T_Node *currNode = &pArray[index];
        if(currNode->key_m == key)
        {
            printf("the node has been exist in map\n");
            pfind = currNode;
            T_Node *tmpNode = pfind->next_m;
            *pfind = *pfind->next_m;
            deallocNode(tmpNode);
            ret = true;
        }
        else
        {
            T_Node *preNode = currNode;
            for(currNode = currNode->next_m; currNode!=NULL;)
            {
                if(currNode->key_m == key)
                {
                    printf("the node has been exist in map\n");
                    pfind = currNode;
                    preNode->next_m = pfind->next_m;
                    deallocNode(pfind);
                    ret = true;
                    break;
                }
                else
                {
                    preNode = currNode;
                    currNode = currNode->next_m;
                }
            }
        }
        return ret;
    }

    void clear()
    {
        for(size_t i = 0; i < totalsize_m; i++)
        {
            if(false == pArray[i].isused_m)
            {
                continue;
            }
            T_Node *currNode = &pArray[i];
            currNode->isused_m = false;
            for(T_Node *confict=currNode->next_m; confict!=NULL;)
            {
                currNode = confict;
                confict = currNode->next_m;
                deallocNode(currNode);
            }
        }
    }

    T_Node * begin()
    {
        for(traver.dwTraveIndex = 0; traver.dwTraveIndex < totalsize_m; traver.dwTraveIndex++)
        {
            traver.pCurrentPtr = &pArray[traver.dwTraveIndex];

            if(true == traver.pCurrentPtr->isused_m)
            {
                return traver.pCurrentPtr;
            }
        }
        return NULL;
    }

    T_Node * next()
    {
        traver.pCurrentPtr = traver.pCurrentPtr->next_m;
        if(NULL != traver.pCurrentPtr)
        {
            if(true == traver.pCurrentPtr->isused_m)
            {
                return traver.pCurrentPtr;
            }
            else
            {
                printf("error [%s:%d], pCurrentPtr.isused_m should be true.",__FILE__,__LINE__);
                return NULL;
            }
        }
        for(traver.dwTraveIndex++; traver.dwTraveIndex < totalsize_m; traver.dwTraveIndex++)
        {
            traver.pCurrentPtr = &pArray[traver.dwTraveIndex];

            if(true == traver.pCurrentPtr->isused_m)
            {
                return traver.pCurrentPtr;
            }
        }
        return NULL;
    }

    typedef void (*_PrintOneNode)(const _Tp &info);
    void printAllNode(_PrintOneNode printFunc)
    {
        for(size_t i = 0; i < totalsize_m; i++)
        {
            if(false == pArray[i].isused_m)
            {
                continue;
            }
            else
            {
                printf("=========begin index %d==============\n",i);
                T_Node *currNode = &pArray[i];
                printFunc((const _Tp)currNode->info_m);
                for(T_Node *confict=currNode->next_m; confict!=NULL;)
                {
                    int iConflict = 0;
                    printf("----- conflict (%d) :-----\n",++iConflict);
                    currNode = confict;
                    confict = currNode->next_m;
                    printFunc((const _Tp)currNode->info_m);
                }
                printf("=========end index %d==============\n",i);
            }
        }
    }

};

}

#endif
