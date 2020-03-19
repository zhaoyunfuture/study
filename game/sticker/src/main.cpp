#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <stdlib.h>       // system
#include <unistd.h>       // sleep
#include <vector>
using namespace std; 

bool flag = false;
int initial=0;
int index=1;
vector<string> vv;

void clearConsole()
{
    system("clear");
}

void init(vector<string>& vv)
{
    vv.push_back("|===============================|");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|                               |");
    vv.push_back("|===============================|");
}

void drawvv(vector<string>& vv)
{
    for(int i=0;i<vv.size();i++){
        cout << vv.at(i) << endl;
    }
}

void processvv(vector<string>& vv)
{
    string line="____";
    string original="|                               |";
    int len = vv.at(0).size();
    if(index+5>len)
        index=1;
    original.replace(index,4,line);
    vv.at(vv.size()-2) = original;
    index++;
}

void draw()
{
    initial++;
    if( initial>25)
        initial=1;
    for(int i=0;i<initial;i++){
        cout << " ";
    }
    cout << "O" << endl;
    for(int i=0;i<initial-1;i++){
        cout << " ";
    }
    cout << "\/|\\"<<endl;
    for(int i=0;i<initial;i++){
        cout << " ";
    }
    cout << "|\\"<<endl;
}

void foo() 
{
    init(vv);
    while(true){
        if(!flag){
            clearConsole();
            //draw();
            processvv(vv);
            drawvv(vv);
        }
        usleep(500000);
    }
}

void press()
{
    while(true){
        char inputmenu;
        cin >> inputmenu;
        if(inputmenu == 'a')
            flag = true;
        else if(inputmenu == 'b')
            flag = false;
    }
}

int main() 
{
    std::thread first (foo);     // spawn new thread that calls foo()
    std::thread second (press);  // spawn new thread that calls bar(0)

    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    return 0;
}



