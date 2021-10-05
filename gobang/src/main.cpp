#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h> //for system clear
using namespace std;

int keys[15][15];
void prepareTable(int keys[15][15])
{
	const int size = 15*2+14+1;
	char filled[size];
	memset(filled,0,size);

	printf("%s\n","  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15");
	for(int i=1; i<=15; i++){
		printf("%02d",i);
		//reset filled part for new line
		for(int i=0;i<size-1;i++){
			if((i+1)%3 == 0){
				filled[i] = '|';
			}else {
				filled[i] = ' ';
			}
		}
		for(int j=1;j<=15;j++){
			switch (keys[i-1][j-1]) {
				case 1:
					filled[(j-1)*3] = '[';
					filled[(j-1)*3+1] = ']';
					break;
				case 2:
					filled[(j-1)*3] = '(';
					filled[(j-1)*3+1] = ')';
					break;
			}
			
		}
		printf("%s\n",filled);
	}
}

int main(int argc, char* argv[])
{
	
	memset(keys,0,sizeof(keys));
	int steps = 0;
	int row, col;
	char* role[2] = {"[rectangle]", "[circle]"};

	while(1){
		system("clear");
		prepareTable(keys);
		cout << role[steps%2] << " input your position(row/col): " ;
		cin >> row >> col;
		keys[row-1][col-1] = steps%2 + 1;
		steps++;
	}

	return 0;
}




