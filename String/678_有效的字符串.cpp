
/*仅有三种格式( * )字符能否按照所给规则成为所要求的字符串*/
//方案1: 暴力求解(超时)
//方案2: 动态规划
//方案3: 贪心greedy

/*
让我们lo, hi分别为打开左括号的最小和最大可能数量的处理字符串中的当前字符之后。

如果我们遇到左括号（c == '('），那么lo++，否则我们可以写一个右括号，所以lo--。如果我们遇到什么可以是左括号（c != ')'），那么hi++，否则我们必须写一个右括号，所以hi--。如果hi < 0，那么无论我们的选择是什么，都不能使当前的前缀有效。而且，我们永远不会少于0打开左括号。最后，我们应该检查，我们可以有正确的0打开左括号。
*/
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;

bool checkValidString(string s)
{
    int lo = 0, hi = 0;
    for (char c: s)
    {
        lo += c == '(' ? 1 : -1;
        hi += c != ')' ? 1 : -1;
        if (hi < 0) break;
        lo = std::max(lo, 0);
    }
    return lo == 0;
}

//*********测试
int main(){
    string s = "(**)";
    cout<<checkValidString(s)<<endl;
    return 0;
}
