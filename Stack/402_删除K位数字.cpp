/*
相似于算法课作业 大整数————string保存————删除k位数字后,结果是所有可能中的最小值
贪心:从左到右扫描，并移除第一个“峰值”位; 峰值数字大于其右邻居。可以重复这个过程k次

贪心规则：每次删除一个数字时 都从最高位开始，寻找相邻数字之间高位数字大于低位数字的情况，此时删除高位数字。从而最后仍然按照从左到右顺序排列的数字最小
额外注意:1.最终起始位置若为零则从第一个不是零的数字开始输
*/
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

string removeKdigits(string num, int k)
{
    //k==num.length() 将num全部删除的情况
    while (k--){
        int i = 0;
        while (i<num.length()-1 && num[i]<=num[i+1])   //寻找第一个峰值
            i++;
        num.erase(i, 1);                               //递增序列删除最后一位 i==num.length()-1
    }
    //删除前导零
    int des=0;
    while(des<num.length()-1 && num[des]=='0') des++;
    num.erase(0,des);   //start end
    //k==num.length() 将num全部删除的情况
    return num=="" ? "0":num;
}

//*******************************测试
int main(int argc,char** argv){
    string digit="12000";
    int k=2;
    string result = removeKdigits(digit,k);
    cout<<result<<endl;
    return 0;
}
