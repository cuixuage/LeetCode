/*
hard题目
str是只有a-z组成的string
pattern是包含通配符'?'和'*'以及'a-z'模式
迭代判断即可
注意：
'*'匹配零个或多个字符, '?'匹配一个字符
*/
bool isMatch(string str, string pattern) {
    int s=0; int p=0;
    int match=0; int starIdx=-1;
    while(s < str.size()){
        //advancing both pointers
        if(p<pattern.length() && (pattern[p]=='?' || str[s]==pattern[p])){
            s++;
            p++;
        }
        //* found, only advance pattern pointer
        else if(p<pattern.length() && pattern[p]=='*'){
            starIdx = p;
            match = s;
            p++;
        }
        //last pattern pointer is '*'(pattern[p]和str[s]不等,*不能代表空,因为str后续可能匹配到p)
        else if(starIdx != -1){
            p = starIdx + 1;
            match ++;
            s = match;
        }
        //current p is not '*', last p was not *
        //don't match
        else    return false;
    }
    //check for remaining characters in pattern
    while(p<pattern.length() && pattern[p]=='*')
        p++;
    return p == pattern.lenght();
}
