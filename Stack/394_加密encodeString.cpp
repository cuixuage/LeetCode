/*
字符串的加密 解密算法
1.  一个stack保存整数数字
2.  一个stack保存[ ]之间元素  （注意需要更新上一级）

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<ctype.h>
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::string;
//**********************方式1**************方便理解
string decodeString_2(string encode_str)
{
    string res="";
    stack<int> countStack;
    stack<string> result;
    int idx=0;
    result.push("");                  //*************相当于pre指针  防止 向前取值的栈溢出
    while(idx<encode_str.length())
    {
        int num=0;
        if(encode_str[idx]<='9' && encode_str[idx]>='0')      //注意可能是多位数字
        {
            while(idx<encode_str.length() && encode_str[idx]<='9' && encode_str[idx]>='0')
            {
                num = 10*num + (encode_str[idx]-'0');
                idx++;
               // cout<<idx<<endl;
            }
            countStack.push(num);
        }
        else if (encode_str[idx] == '[')
        {
            result.push("");
            idx++;
        }
        else if (encode_str[idx] == ']')
        {
            string temp="";
            string str = result.top();    // 当前[]之间元素
            result.pop();
            int times = countStack.top();
            countStack.pop();
            for (int j = 0; j < times; j += 1)
            {
                temp += str;
            }
            string temp_pre = result.top();   //**********更新 上一级  ****result stack第一个元素为空 否则这里也有可能溢出
            result.pop();
            result.push(temp_pre + temp);
            idx++;
        }
        else
        {   string temp = result.top();         //result初始值需要有一个空""元素  否则程序崩溃？？？？
            result.pop();
            result.push(temp + encode_str[idx]);
            idx ++;
        }
    }
    //cout<<result.size()<<endl;
    return result.top();
}
//************************方式2***********不太好理解
string decodeString(string encode_str)
{
    string res="";
    stack<int> countStack;
    stack<string> stringStack;
    int idx=0;
    while(idx<encode_str.length())
    {
        int num=0;
        if(encode_str[idx]<='9' && encode_str[idx]>='0')      //注意可能是多位数字
        {
            while(idx<encode_str.length() && encode_str[idx]<='9' && encode_str[idx]>='0')
            {
                num = 10*num + (encode_str[idx]-'0');
                idx++;
            }
            countStack.push(num);
        }
        else if(encode_str[idx]=='[')
        {
            stringStack.push(res);    //保存 [ 之前的元素
            res="";
            idx++;
        }
        else if(encode_str[idx]!=']')
        {
            res += encode_str[idx];    //保存[]之间的元素
            idx++;
        }
        else if(encode_str[idx]==']')
        {
            string temp = stringStack.top();    //取出对应[之前的字符串
            stringStack.pop();
            int repeatTimes = countStack.top();
            countStack.pop();
            while(repeatTimes--)
            {
                temp += res;                    //重复加上[]之间的元素
            }
            res = temp;
            idx++;
        }
    }
    return res;
}

int main(int argc,char** argv)
{
    string encode_str="3[a]2[bc]";
    cout<<decodeString_2(encode_str)<<endl;
    return 0;
}
