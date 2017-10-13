/*
删数问题  greedy贪心算法
–通过键盘输入一个高精度的正整数n(n的有效位数≤240)，去掉其中任意s个数字后，剩下的数字按原左右次序将组成一个新的正整数。编程对给定的n 和s，寻找一种方案，使得剩下的数字组成的新数最小。
–输入：n, s
–输出：最后剩下的最小数
–输入示例
178543
4
–输出示例
13
*/
/*贪心规则:
贪心规则：每次删除一个数字时 都从最高位开始，寻找相邻数字之间高位数字大于低位数字的情况，此时删除高位数字。
从而最后仍然按照从左到右顺序排列的数字最小
*/
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc,char** argv){
    //freopen("./data_boll/7_homework_input.txt","r",stdin);
    string str;
    int m;
    while(cin>>str>>m){
        if(m>str.size()) {
            cout<<"需要删除的数字个数M大于数字长度"<<endl;
            return 0;
        }
        while(m--){
            int i=0;
            int len=str.length();
            for(i=0;i<len-1;){   //每一次从头遍历数整数
                if(str[i] > str[i+1]){
                    str.erase(str.begin()+i);
                    break;
                }
                else i++;
            }
        //i++ 轮询一遍str没有发现相邻数字出现高位大于低位的情况
            if(i==len-1)
                str.erase(str.begin()+i);     //删除最后一位数字
        }

        //删除结果中开头为0的字符
        bool flag=false;
        for(int i=0;i<str.length();i++){
            if(flag==false&&str[i]!='0') flag=true;
            if(flag==true) cout<<str[i];
        }
        if(flag==false) cout<<0;
        cout<<endl;
    }
}
