#include <time.h>

// 返回自系统开机以来的毫秒数（tick）
unsigned long GetTickCount()
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}


int main()
{
/*    struct timespec time1 = { 0, 0 };

    clock_gettime(CLOCK_REALTIME, &time1);
    printf("CLOCK_REALTIME: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &time1);
    printf("CLOCK_MONOTONIC: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC_RAW, &time1);
    printf("CLOCK_MONOTONIC_RAW: %d, %d\n", time1.tv_sec, time1.tv_nsec);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", time1.tv_sec,
           time1.tv_nsec);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", time1.tv_sec,
           time1.tv_nsec);

    printf("\n%d\n", time(NULL));
*/
	unsigned long timebase,timenow;
	unsigned long i,j,k;
	timebase = GetTickCount();
    printf("tick count in ms: %ul\n", GetTickCount());
    for(i=1;i<300000;i++)
		k++;
	timenow = GetTickCount();
    printf("tick count now in ms: %ul\n", timenow);
    unsigned long temp;
	temp = timenow-timebase;
    printf("tick count past in ms: %ul\n", temp);

    for(i=1;i<200000;i++)
		j++;
	timenow = GetTickCount();
	temp = timenow-timebase;
    printf("tick count past in ms: %ul\n", temp);

    return 0;
}
