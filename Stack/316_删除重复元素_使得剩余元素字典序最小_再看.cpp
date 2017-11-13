/*
删除string重复元素 同时使得result序列是在所有可能性中排列顺序最小的一个
*/

//greedy 按照string顺序 从左到右遍历
//寻找有重复的元素 的字典序最小的那一个 排在结果的最左边
//如果此字典序最小的元素是非重复性 说明是必须包含在result中的 跳出循环

#include<string.h>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;

//******************仔细理解 + 后面我写的方法为什么不对
//答案https://discuss.leetcode.com/topic/31404/a-short-o-n-recursive-greedy-solution/10
//p 保存// the position for the smallest s[i]
string removeDuplicateLetters(string s)
{
    string res;
    int p=0;
    while(p<s.size())
    {
        vector<int> cnt(256,0);
        for(int i=p; i<s.size(); i++) if(s[i]!='}') cnt[s[i]]++;
        int nxtp=p;
        for(int i=p; i<s.size(); i++)
        {
            if(s[i]<s[nxtp]) nxtp=i;    //当前字典序最小的位置
            if(--cnt[s[i]]==0) break; //unique in suffix s[i...]
        }
        for(int j=p; j<s.size(); j++)
        {
            // s[j]重复的元素处于nxtp后面全部删除
            if(j<nxtp || s[j]==s[nxtp] && j>nxtp) s[j]='}';
        }
        while(p<=nxtp || s[p]=='}') p++;   //更新p的位置到尚未删除的重复性元素 首位置
    }
    for(auto c: s) if(c!='}') res.push_back(c);
    return res;
}




//string removeDuplicateLetters(string s)
//{
//    int cnt[26]={0};
//    int pos = 0; // the position for the smallest s[i]
//    for (int i = 0; i < s.length(); i++)   //记录string每一个元素是否重复 >1
//        cnt[s.at(i) - 'a']++;
//
//    for (int i = 0; i < s.length(); i++)  //string从左到右寻找字典序最小元素
//    {
//        if (s.at(i) < s.at(pos)) pos = i;
//        if (--cnt[s.at(i) - 'a'] == 0) break;   //遍历过程中有非重复性元素 终止遍历
//    }
//
//    string temp="";
//    if(s.length()==0) return "";
//    else {
//        temp= s.substr(pos+1);
//        cout<<temp<<endl;
//        int k = temp.find(s.at(pos),0);
//        while(k!=string::npos){   //注意 s.at 原有字符串的pos位置
//            temp.erase(k,k+1);
//            k = temp.find(s.at(pos),k);
//        }
//    }
//
//    return s.at(pos)+removeDuplicateLetters(temp);
//    /*
//    错误的replace方式
//    string temp = s.substr(pos+1,s.length());    //0开始 [pos+1,end() )
//    temp.replace(temp.begin(),temp.end(),""+s.at(pos), "");
//    */
//
//    //return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters
//    //(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
//}

int main()
{
    string s="cbacdcbc";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;
}
