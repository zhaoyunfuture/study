#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <stdlib.h>       // system
#include <unistd.h>       // sleep
#include <vector>
using namespace std; 
string game_over = "|        game over              |";
string you_win   = "|        you win!!              |";
bool flag = false;
int initial=0;
int index=1;
vector<string> vv;
int row=2;
int currLen = 6;
int lastindex=1;
int speed=100000;
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
    if(row<8){
    for(int i=0;i<currLen;i++)
        line.push_back('_');
    int len = vv.at(0).size();
    if(index+line.length()+1>len)
        index=1;
    original.replace(index,line.length(),line);
    vv.at(vv.size()-row) = original;
    index++;
    }
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
    if(row<8){
        if(index<lastindex){
            if(lastindex-index>currLen)
                vv.at(1) = game_over;
            else{
                currLen -= lastindex-index;
                index=lastindex; 
                drawoneline();
                row++;
            }
        }else{
            if(index-lastindex>currLen)
                vv.at(1) = game_over;
            else{
                currLen -= index-lastindex;
                drawoneline();
                row++;
            }
        }
        return;
    }
    if(row==8)
        vv.at(1) = you_win;
}

void play() 
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
        usleep(speed);
    }
}

void press()
{
    while(true){
        char inputmenu;
        cout << "\n\n"
            << "MENU\n\n"
            << "1: easy\n"
            << "2: medium\n"
            << "3: hard\n"
            << "4: quit\n\n\n"
            << "Input: ";
        cin >> inputmenu;
        switch (inputmenu){
            case '1': currLen=7;
                      speed=150000;
                      break;
            case '2': currLen=6;
                      speed=100000;
                      break;
            case '3': currLen=5;
                      speed=80000;
                      break;
            case 'a': flag = true;break;
            case 'b': flag = false;break;
            case '4':
            case 'q':
            default : break;
        }
    }
}

int main() 
{
    std::thread first (play);     // spawn new thread that calls foo()
    std::thread second (press);  // spawn new thread that calls bar(0)

    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    return 0;
}



