/*  字符串中的子序列
 选择其中字典序最大的子序列

 substring子集？  sequence序列？
 思路:  从Z-A开始寻找,当string出现后,
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ans;
    int index=0;
    cin>>s;

    //index 记录最大的字典序的字符,在string中可达的最大位置。  下一次遍历时候从index开始就行
    for(int c='z'; c>='a'; c--)
        for(int i=index; i<s.size(); i++)  //for(int i=index; i<s.size(); i++)???
            if(s[i]==c && i>=index){
                ans += c;
                index = i;
            }
    cout<<ans<<endl;
    return 0;
}