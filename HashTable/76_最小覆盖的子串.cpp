#include "func.h"
/*
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
如果存在最小覆盖子串,那么结果是唯一的
思路1:
O(N*N)  for+contain

思路2:
O(N)
寻找满足限制条件的string 往往使用两个辅助指针 + hashtable
*/

/*
三个关键变量
mapT windowS letterCount
注： 在第二个for循环1.fast移动寻找覆盖T的窗口 2.slow进行缩小 3.letter<T.length不进行第二个if判断

画图理解一遍   fast是会移动到S.length位置
*/

string minWindow(string S, string T){
    string result;
    if(S.empty() ||T.empty())  return "";
    unordered_map<char,int> mapT;
    unordered_map<char,int> windowS;
    for(int i=0;i<T.length();i++)
        mapT[T[i]]++;
    int minLen = INT_MAX;
    int letterCount = 0;

    for(int slow=0,fast=0;fast<S.length();fast++){
        char c = S[fast];
        if(mapT.find(c)!=mapT.end()){
            windowS[c]++;
            if(windowS[c] <= mapT[c])
                letterCount++;
        }
        //until fast覆盖T
        if(letterCount >= T.length()){
            char d = S[slow];
            //slow向后移动直到最小子串
            while(mapT.find(d)==mapT.end() || windowS[d]>mapT[d]){
                windowS[d]--;       //等价if(windowS.find(d)!=windowS.end()) windowS[d]--;
                slow++;
                d = S[slow];        //update d  不然无法跳出循环
            }
            //record min length
            if(fast-slow+1 < minLen){
                minLen = fast-slow+1;
                result = S.substr(slow,minLen);     //[)
            }
        }
    }
    return result;
}
