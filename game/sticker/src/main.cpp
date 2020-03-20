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
int row=2;
int currLen = 6;
int lastindex=1;
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
void runvv(vector<string>& vv)
{
    clearConsole();
    string line;
    string original="|                               |";
    for(int i=0;i<currLen;i++)
        line.push_back('_');
    int len = vv.at(0).size();
    if(index+line.length()+1>len)
        index=1;
    original.replace(index,line.length(),line);
    vv.at(vv.size()-row) = original;
    index++;
    drawvv(vv);
}

void drawoneline()
{
    string line;
    string original="|                               |";
    for(int i=0;i<currLen;i++)
        line.push_back('_');
    int len = vv.at(0).size();
    original.replace(index-1,line.length(),line);
    vv.at(vv.size()-row) = original;
}

void processvv(vector<string>& vv)
{
    if(row==2){
        lastindex = index;
        row++;
        return;
    }
    if(row<6){
        if(index<lastindex){
            if(lastindex-index>currLen)
                vv.at(1) = "|        game over              |";
            else{
                currLen -= lastindex-index;
                index=lastindex; 
                drawoneline();
                row++;
            }
        }else{
            if(index-lastindex>currLen)
                vv.at(1) = "|        game over              |";
            else{
                currLen -= index-lastindex;
                drawoneline();
                row++;
            }
        }
    }
    return;
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
        if(flag){
            clearConsole();
            processvv(vv);
            drawvv(vv);
            flag = false;
        }
        runvv(vv);
        usleep(100000);
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



