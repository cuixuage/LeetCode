#include "func.h"
/*
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
如果存在最小覆盖子串,那么结果是唯一的
思路1:
O(N*N) i,j之间的窗口  for + contain

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
    unordered_map<char,int> mapT;       //pattern hashmap
    unordered_map<char,int> windowS;    //window窗口 hashmap
    for(int i=0;i<T.length();i++)       //pattern每个字符出现几次？
        mapT[T[i]]++;

    int minLen = INT_MAX;
    int letterCount = 0;

//////////////  O(N)  遍历fast指针
    for(int slow=0,fast=0;fast<S.length();fast++){
        //1. 移动fast指针到包含pattern位置
        char c = S[fast];
        if(mapT.find(c)!=mapT.end()){
            windowS[c]++;
            if(windowS[c] <= mapT[c])  //
                letterCount++;
        }

        //2. 如果包含字符达到要求: fast已经覆盖掉Pattern时
        if(letterCount >= T.length()){
            char d = S[slow];
            //3. while循环移动slow
            while(mapT.find(d)==mapT.end() || windowS[d]>mapT[d]){ //规则: window[slow]不是pattern中,或者window[slow]出现次数足够 移动slow指针
                windowS[d]--;
                slow++;
                d = S[slow];        //update d  不然无法跳出循环
            }
            //4. 记录当前window record min length
            if(fast-slow+1 < minLen){
                minLen = fast-slow+1;
                result = S.substr(slow,minLen);     //[)
            }
        }
    }
    return result;
}
