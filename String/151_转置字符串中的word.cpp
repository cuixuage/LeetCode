/*
For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

#include"func.h"
void reverseWords(string &s) {
    vector<string> token;
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        token.push_back(temp);        //思考:连续的空格temp就为空  也能加入vector当中
    }
    //****erase+remove方法 记牢咯
    token.erase(std::remove(token.begin(), token.end(), ""),     //删除空元素
               token.end());
    reverse(token.begin(),token.end());
    string ans="";
    for(auto i:token){
        ans += i + ' ';
    }
    if(ans.length()!=0)
        ans.erase(ans.length()-1,ans.length());
    s = ans;
    }
}

int main(){
    string s = "   ";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
