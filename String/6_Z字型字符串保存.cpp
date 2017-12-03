/*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4

输入按照Z字型;输出时横向输出
思路: vector<vector<int>>  保存整个数组
*/

#include "func.h"
string convert(string s,int rows){
    string temp = s;
    int len = temp.length();
    vector<string> str(rows,"");            //初始化很关键 不然后面vector无法直接使用索引
    //str.reserve(rows);
    int i=0;
    while(i<len){
        for (int idx=0;idx<rows&&i<len;idx++)   //垂直顺序
            str[idx] += temp.at(i++);   //i++ 后加加
        for (int idx=rows-2;idx>=1&&i<len;idx--) //Z 斜着的的数字
            str[idx] += temp.at(i++);
    }
    string ans="";
    for(auto sb:str)
        ans +=sb;
    return ans;
}

int main(){
    string test="PAYPALISHIRING";
    cout<<convert(test,3)<<endl;
    return 0;
}
