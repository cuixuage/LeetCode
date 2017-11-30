/*
由单词和' '组成的字符串 求最后一个单词的长度
例如: "a " return 1;
    "   "  return 0;
*/

#include "func.h"

int lengthOfLastWord(string s)
{
    stringstream ss(s);
    string temp;
    vector<string> ans;             //关键:保存每一个被' '切割后的string
    ans.reserve(32);
    while(getline(ss,temp,' '))
    {
        ans.push_back(temp);
    }
    std::reverse(ans.begin(),ans.end());
    for(auto i : ans)
    {
        if(i!="") return i.length();           //避免: "a " 返回0
    }
    return 0;
}
