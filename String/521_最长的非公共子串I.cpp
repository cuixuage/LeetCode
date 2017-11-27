/*
思考 abc abd的最长非公共子串并不是 'c'or'd'  而是  'abc'or'abd'
这是因为 子序列是包含原序列的

思考:原字符串减去最长公共字符串的结果？这种考题是否会出现？

a=b. If both the strings are identical, it is obvious that no subsequence will be uncommon. Hence, return -1.

length(a)=length(b)length(a)=length(b) and a \ne ba≠b. Example: abcabc and abdabd. In this case we can consider any string i.e. abcabc or abdabd as a required subsequence, as out of these two strings one string will never be a subsequence of other string. Hence, return length(a)length(a) or length(b)length(b).

length(a) \ne length(b)length(a)≠length(b). Example abcdabcd and abcabc. In this case we can consider bigger string as a required subsequence because bigger string can't be a subsequence of smaller string. Hence, return max(length(a),length(b))max(length(a),length(b)).
*/

#include"func.h"
int findLUSlength(string a, string b) {
    if(a==b) return -1;   //思考:只有完全相同时 而非使用contains？(只是判断是否包含)
    else
        return std::max(a.length(),b.length());
}

int main(){
    string str1="abc";
    string str2="abd";
    cout<<findLUSlength(str1,str2);
    return 0;
}
