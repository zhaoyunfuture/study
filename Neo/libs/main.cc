#include <iostream>

#include "neodebug.h"
#include "neomemmanager.h"
#include "neoqueue.h"
#include "neolog.h"
#include "neothread.h"
#include "neobaselib.h"


using namespace NEOLIB;
using namespace std;

int main()
{
	char str[50] = "\0";
	char buffer[50] = "\0";
	int len = SafePrintf(str,15,"safeprintftest");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEODynamicBuffer>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOLowDebug *debug = new CNEOLowDebug(".","neolibs");
	CNEOMemPoolWithLock *mempool = new CNEOMemPoolWithLock(debug);
	CNEODynamicBuffer *dbufer = new CNEODynamicBuffer(mempool);
	CNEOStaticBuffer *sbufer = new CNEOStaticBuffer(mempool);

	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOPopBuffer>>>>>>>>>>>>>>>>>>>>>>>>\n");
	char pop[1000] = {""};
	const char * pop1 = "a";
	CNEOPopBuffer *pbufer = new CNEOPopBuffer(pop,1000);
/*	pbufer->AddLast(pop1,strlen(pop1));
	pbufer->PrintInside();
	pbufer->AddLast("asdcvf",7);
	pbufer->PrintInside();
	pbufer->AddLast("1234567890",11);
	pbufer->PrintInside();
	pbufer->AddLast("1234567890",11);
	pbufer->PrintInside();
	pbufer->AddLast(dbufer);
	pbufer->PrintInside();
	pbufer->AddLast(sbufer);
	pbufer->PrintInside();
	printf("%d\n",pbufer->GetTokenCount());
	printf("%d\n",pbufer->GetAllBytes());
	printf("%d\n",pbufer->GetFirstTokenLength());
	char out[200] = {""};
	pbufer->GetFirst(out,200);
	printf("%s\n",out);
	pbufer->GetFirst(dbufer);
	pbufer->GetFirst(sbufer);
	pbufer->DeleteFirst();
	pbufer->PrintInside();
//	pbufer->GetAndDeleteFirst(out,200);
//	printf("%s\n",out);
//	pbufer->PrintInside();
//	pbufer->MoveAllData(NULL,NULL);
//	pbufer->PrintInside();

	char out[200] = {""};
	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOMemQueue>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOMemQueue *mbufer = new CNEOMemQueue(debug,mempool,"test");
	mempool->PrintInfo();
	mempool->PrintTree();
	printf("%d\n",mbufer->GetTokenCount());
	mbufer->AddLast(pop1,1);
	mempool->PrintInfo();
	mempool->PrintTree();
	printf("%d\n",mbufer->GetTokenCount());
	mbufer->AddLast("asdcvf",6);
	mempool->PrintInfo();
	mempool->PrintTree();
	printf("%d\n",mbufer->GetTokenCount());
	mbufer->AddLast("12345678901234567890123456789012345678901234567890",50);
	mempool->PrintInfo();
	mempool->PrintTree();
	printf("%d\n",mbufer->GetTokenCount());
	printf("%d\n",mbufer->GetFirstLength());
	mbufer->PrintInside();
	printf("\n");
	mbufer->GetFirst(out,200);
	printf("%s\n",out);
	mbufer->GetFirst(dbufer);
	mbufer->DeleteFirst();
	mbufer->PrintInside();
	mbufer->AddLast("12345678901234567890123456789012345678901234567890",50);
	mbufer->PrintInside();
	mbufer->GetAndDeleteFirst(out,200);
	printf(">>>>>out0000>>%s\n",out);
	mbufer->PrintInside();
	mbufer->GetAndDeleteFirst(out,200);
	printf(">>>>>out>>>>>%s\n",out);
	mbufer->PrintInside();
	mbufer->AddLast("abcdefghij",10);
	mbufer->PrintInside();
	char out1[100]="";
	mbufer->PopFromFirst(out1,100);
	printf(">>>>out111>>>%s\n",out1);
	mbufer->PrintInside();
	mbufer->PushToLast(out1,100);
	mbufer->PrintInside();
	mbufer->WriteToFile("queue");
	mbufer->PrintInside();
	mbufer->ReadFromFile("queue");
	mbufer->PrintInside();

	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOMemQueueWithLock>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOMemQueueWithLock *mlbufer = new CNEOMemQueueWithLock(debug,mempool,"test");
	printf("%d\n",mlbufer->GetTokenCount());
	mlbufer->AddLast(pop1,1);
	printf("%d\n",mlbufer->GetTokenCount());
	mlbufer->AddLast("asdcvf",6);
	printf("%d\n",mlbufer->GetTokenCount());
	mlbufer->AddLast("12345678901234567890123456789012345678901234567890",50);
	mempool->PrintInfo();
	mempool->PrintTree();
	printf("%d\n",mlbufer->GetTokenCount());
	mlbufer->PrintInside();
	mlbufer->GetFirst(out,200);
	printf("%s\n",out);
	mlbufer->GetFirst(dbufer);
	mlbufer->DeleteFirst();
	mlbufer->PrintInside();
	mlbufer->AddLast("12345678901234567890123456789012345678901234567890",50);
	mlbufer->PrintInside();
	mlbufer->GetAndDeleteFirst(out,200);
	printf("%s\n",out);
	mlbufer->PrintInside();
	mlbufer->GetAndDeleteFirst(out,200);
	printf("%s\n",out);
	mlbufer->PrintInside();
	char out2[100]="";
	mlbufer->PopFromFirst(out2,100);
	printf("%s\n",out2);
	mlbufer->PrintInside();
	mlbufer->PushToLast(out2,100);
	mlbufer->PrintInside();
	mlbufer->WriteToFile("queue1");
	mlbufer->PrintInside();
	mlbufer->ReadFromFile("queue1");
	mlbufer->PrintInside();
	
*/	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOLog>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOLog *plog = new CNEOLog(debug,mempool,".","test");
//	plog->_XGDebugForBin("_XGDebugForBin",15);
//	plog->_XGSysLog("_XGSysLog:%d",15);
//	plog->_XGDebug("_XGDebug:%s","hahahhah");
//	plog->_XGDebug2("_XGDebug2:%s","asdsadada");

	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOThreadPool>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOThreadPool *pthreadpool = new CNEOThreadPool(debug);
/*	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo_jacob,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	pthreadpool->ThreadPoolRegTask(printThreadInfo_jacob,pthreadpool);
//	Sleep(OPEN_THREAD_DELAY);
	Sleep(OPEN_THREAD_DELAY*50);
	Sleep(OPEN_THREAD_DELAY);
	pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
	Sleep(OPEN_THREAD_DELAY);
	//pthreadpool->ThreadPoolRegTask(printThreadInfo,pthreadpool);
*/
//	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOTaskPool>>>>>>>>>>>>>>>>>>>>>>>>\n");
	CNEOTaskPool *ptaskpool = new CNEOTaskPool(debug,mempool,plog);
//	ptaskpool->PrintInfo();
//	ptaskpool->RegisterATask(printTaskPoolInfo,ptaskpool);

	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOTaskRunInfo>>>>>>>>>>>>>>>>>>>>>>>>\n");
	SNEOTaskRunInfo taskInfo;
	//CNEOTaskRunInfo *pTaskRunInfo = new CNEOTaskRunInfo(&taskInfo);
	new CNEOTaskRunInfo(&taskInfo);
	Sleep(OPEN_THREAD_DELAY);

	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOTaskRun>>>>>>>>>>>>>>>>>>>>>>>>\n");
    //CNEOTaskRun *pTaskRun = new CNEOTaskRun(mempool,plog,ptaskpool);
    new CNEOTaskRun(mempool,plog,ptaskpool);

//	printf(">>>>>>>>>>>>>>>>>>>>>>>>CNEOBaseLibrary>>>>>>>>>>>>>>>>>>>>>>>>\n");
	//CNEOBaseLibrary *pBaseLib = new CNEOBaseLibrary("baselib",".","log",NULL);
	//CNEOBaseLibrary *pBaseLib = CNEOBaseLibrary::getInstance("baselib",".","log",NULL);
//	CNEOBaseLibrary::getInstance("baselib",".","log",NULL);
	//CNEOBaseLibrary *pBaseLib1 = CNEOBaseLibrary::getInstance("baselib",".","log",NULL);
//	CNEOBaseLibrary::getInstance("baselib",".","log",NULL);
    
#ifdef WIN32
    system("pause");
#else
#endif
    return 0;

}
