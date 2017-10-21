/*
�ַ����ļ��� �����㷨
1.  һ��stack������������
2.  һ��stack����[ ]֮��Ԫ��  ��ע����Ҫ������һ����

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
//**********************��ʽ1**************�������
string decodeString_2(string encode_str)
{
    string res="";
    stack<int> countStack;
    stack<string> result;
    int idx=0;
    result.push("");                  //*************�൱��preָ��  ��ֹ ��ǰȡֵ��ջ���
    while(idx<encode_str.length())
    {
        int num=0;
        if(encode_str[idx]<='9' && encode_str[idx]>='0')      //ע������Ƕ�λ����
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
            string str = result.top();    // ��ǰ[]֮��Ԫ��
            result.pop();
            int times = countStack.top();
            countStack.pop();
            for (int j = 0; j < times; j += 1)
            {
                temp += str;
            }
            string temp_pre = result.top();   //**********���� ��һ��  ****result stack��һ��Ԫ��Ϊ�� ��������Ҳ�п������
            result.pop();
            result.push(temp_pre + temp);
            idx++;
        }
        else
        {   string temp = result.top();         //result��ʼֵ��Ҫ��һ����""Ԫ��  ������������������
            result.pop();
            result.push(temp + encode_str[idx]);
            idx ++;
        }
    }
    //cout<<result.size()<<endl;
    return result.top();
}
//************************��ʽ2***********��̫�����
string decodeString(string encode_str)
{
    string res="";
    stack<int> countStack;
    stack<string> stringStack;
    int idx=0;
    while(idx<encode_str.length())
    {
        int num=0;
        if(encode_str[idx]<='9' && encode_str[idx]>='0')      //ע������Ƕ�λ����
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
            stringStack.push(res);    //���� [ ֮ǰ��Ԫ��
            res="";
            idx++;
        }
        else if(encode_str[idx]!=']')
        {
            res += encode_str[idx];    //����[]֮���Ԫ��
            idx++;
        }
        else if(encode_str[idx]==']')
        {
            string temp = stringStack.top();    //ȡ����Ӧ[֮ǰ���ַ���
            stringStack.pop();
            int repeatTimes = countStack.top();
            countStack.pop();
            while(repeatTimes--)
            {
                temp += res;                    //�ظ�����[]֮���Ԫ��
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
