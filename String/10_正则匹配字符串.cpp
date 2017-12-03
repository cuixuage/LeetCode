/*
. 代表单个字符
* 代表0个或多个字符
*/

//方案1: 递归
#include "func.h"
// '*'只会当做第二字符来使用

bool isMatch(string text, string pattern){
    if(pattern.empty()) return text.empty();
    bool first_match = (!text.empty() && (pattern.at(0) == text.at(0)
                                          || pattern.at(0)=='.') );
    if(pattern.length() >=2 && pattern.at(1)=='*'){
            //* 代表零个字符  pattern从第三个字符起作为新的正则
        return (isMatch(text,pattern.substr(2))
            //* 代表多个字符 text成功匹配一个字符
                || (first_match && isMatch(text.substr(1),pattern) ));
    }
    //当字符串长度==1 或者 第二个字符不是'*' (后面字符重新匹配)
    else
        return first_match &&isMatch(text.substr(1),pattern.substr(1));

}

 bool isMatch_2(const char *s, const char *p) {
    string text=s;      //初始化 string text(s);
    string pattern=p;   //string pattern(p);
    if(pattern.empty()) return text.empty();
    bool first_match = (!text.empty() && (pattern.at(0) == text.at(0)
                                          || pattern.at(0)=='.') );
    if(pattern.length() >=2 && pattern.at(1)=='*'){
        return (isMatch(text.c_str(),pattern.substr(2).c_str())
                || (first_match && isMatch(text.substr(1).c_str(),pattern.c_str()) ));
    }
    else return first_match &&isMatch(text.substr(1).c_str(),pattern.substr(1).c_str());

    }

int  main(){
    string text="aab";
    string pattern = "c*a*b";
    cout<<isMatch(text,pattern)<<endl;
    return 0;
}
