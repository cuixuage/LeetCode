/*
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
要求 0/1分别grouped在一起

解决思路: "110001111000000", then groups = [2, 3, 4, 6].
take the sum of min(groups[i-1], groups[i]).  sum=2+3+4=9
*/
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using std::string;
using std::cout;
using std::endl;
using std::vector;
int countBinarySubstrings(string s) {
    vector<int> group(s.size(),0);
    group[0]=1;
    int idx=0;
    //"110001111000000", then groups = [2, 3, 4, 6]  思路:hash 很常用的方法
    for(int i=1;i<s.length();++i){
        if(s.at(i-1) == s.at(i)) group[idx]++;
        else{
            group[++idx]=1;
        }
    }

    int sum=0;
    for(auto i=group.begin();i!=group.end()-1;++i)
        sum += std::min(*i,*(i+1));
    return sum;
}

//*****************测试
int main(int argc,char** argv){
    string s = "11";
    cout<<countBinarySubstrings(s)<<endl;
    return 0;
}
