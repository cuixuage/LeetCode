/*
�������㷨����ҵ ��������������string���桪������ɾ��kλ���ֺ�,��������п����е���Сֵ
̰��:������ɨ�裬���Ƴ���һ������ֵ��λ; ��ֵ���ִ��������ھӡ������ظ��������k��

̰�Ĺ���ÿ��ɾ��һ������ʱ �������λ��ʼ��Ѱ����������֮���λ���ִ��ڵ�λ���ֵ��������ʱɾ����λ���֡��Ӷ������Ȼ���մ�����˳�����е�������С
����ע��:1.������ʼλ����Ϊ����ӵ�һ������������ֿ�ʼ��
*/
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

string removeKdigits(string num, int k)
{
    //k==num.length() ��numȫ��ɾ�������
    while (k--){
        int i = 0;
        while (i<num.length()-1 && num[i]<=num[i+1])   //Ѱ�ҵ�һ����ֵ
            i++;
        num.erase(i, 1);                               //��������ɾ�����һλ i==num.length()-1
    }
    //ɾ��ǰ����
    int des=0;
    while(des<num.length()-1 && num[des]=='0') des++;
    num.erase(0,des);   //start end
    //k==num.length() ��numȫ��ɾ�������
    return num=="" ? "0":num;
}

//*******************************����
int main(int argc,char** argv){
    string digit="12000";
    int k=2;
    string result = removeKdigits(digit,k);
    cout<<result<<endl;
    return 0;
}
