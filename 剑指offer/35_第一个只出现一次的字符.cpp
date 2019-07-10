#include "func.h"
//AC
int FirstNotRepeatingChar(string str){
    int hashtable[256] = {0};
    for(char c : str){
        hashtable[c] ++;
    }
    for(int i=0;i<str.size();i++)
        if(hashtable[str[i]] == 1) return i;
    return -1;
}