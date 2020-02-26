#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void appendpad(string& s,int c){
        for(int i=0;i<c;i++)
            s.append(" ");
    }
    string formatlast(int b,int e,vector<string>& words){
        string out;
        for(int i=b;i<=e;i++){
            out.append(words.at(i));
            if(i!=e)
                out.append(" ");            
        }
        return out;
    }
    string format(int b,int e,int wordTotalLen,vector<string>& words,int maxWidth){
        string out;
        int padCont = e-b;
        int padSpace = maxWidth - wordTotalLen;
        if(padCont==0){
            out.append(words.at(e));
            appendpad(out,padSpace);
            return out;
        }
        bool ispad=false;
        int padlen=0;
        int padplus=0;
        padlen = padSpace/padCont;
        if(padSpace%padCont == 0){            
            ispad = true;
        }else{
            padplus = padSpace%padCont;
        }
        //cout << padSpace<<' '<<padCont<< ' ' <<padlen <<' '<< padplus << endl;
        for(int i=b;i<=e;i++){
            out.append(words.at(i));
            if(i==e)
                break;
            if(ispad){
                appendpad(out,padlen);
            }else{
                if(padplus!=0){
                    appendpad(out,padlen+1);
                    padplus -= 1;
                }else
                    appendpad(out,padlen);
            }                
        }
        return out;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size();
        vector<string> v;
        if(len==0)
            return v;
        if(len==1){
            string s(words.at(0));
            int lastlen = s.length();
            appendpad(s,maxWidth-lastlen);
            v.push_back(s);
            return v;
        }
        int bg=0;
        int end=0;
        int wordnum=0;
        int wordnextlen=0;
        int wordlen=words.at(bg).length();
        int strlen=words.at(bg).length();
        
        string s;
        bool finalstep = false;
        while(end<len){
            wordnum=0;
            while(strlen<=maxWidth){
                wordnum +=1;
                wordnextlen = words.at(end+1).length();
                strlen = wordlen+wordnextlen+wordnum;
                if(strlen<=maxWidth){
                    end += 1;                    
                    wordlen += wordnextlen;
                    if(end == len-1){
                        finalstep = true;
                        break;
                    }
                }
            }
            if(!finalstep){
                s = format(bg,end,wordlen,words,maxWidth);            
                v.push_back(s);
                bg = end+1;
                end = bg;
                if(end == len-1){
                    string lastline = words.at(end);
                    appendpad(lastline,maxWidth-words.at(end).length());
                    v.push_back(lastline);
                    break;
                }
                wordlen = words.at(bg).length();
                strlen = wordlen;
            }else{
                s = formatlast(bg,len-1,words);
                int lastlen = s.length();
                appendpad(s,maxWidth-lastlen);
                v.push_back(s);
                break;
                //end = len-1;
            }
        }
        return v;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string str[]= {"What","must","be","acknowledgment","shall","be"};
    vector<string> v(str,str+6);
    for(int i=0;i<v.size();i++)
        cout << v.at(i) << " ";
    cout << endl;
    s.fullJustify(v,16);
	return 0;
}


