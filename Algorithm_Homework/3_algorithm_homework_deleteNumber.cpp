/*
ɾ������  greedy̰���㷨
�Cͨ����������һ���߾��ȵ�������n(n����Чλ����240)��ȥ����������s�����ֺ�ʣ�µ����ְ�ԭ���Ҵ������һ���µ�����������̶Ը�����n ��s��Ѱ��һ�ַ�����ʹ��ʣ�µ�������ɵ�������С��
�C���룺n, s
�C��������ʣ�µ���С��
�C����ʾ��
178543
4
�C���ʾ��
13
*/
/*̰�Ĺ���:
̰�Ĺ���ÿ��ɾ��һ������ʱ �������λ��ʼ��Ѱ����������֮���λ���ִ��ڵ�λ���ֵ��������ʱɾ����λ���֡�
�Ӷ������Ȼ���մ�����˳�����е�������С
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
            cout<<"��Ҫɾ�������ָ���M�������ֳ���"<<endl;
            return 0;
        }
        while(m--){
            int i=0;
            int len=str.length();
            for(i=0;i<len-1;){   //ÿһ�δ�ͷ����������
                if(str[i] > str[i+1]){
                    str.erase(str.begin()+i);
                    break;
                }
                else i++;
            }
        //i++ ��ѯһ��strû�з����������ֳ��ָ�λ���ڵ�λ�����
            if(i==len-1)
                str.erase(str.begin()+i);     //ɾ�����һλ����
        }

        //ɾ������п�ͷΪ0���ַ�
        bool flag=false;
        for(int i=0;i<str.length();i++){
            if(flag==false&&str[i]!='0') flag=true;
            if(flag==true) cout<<str[i];
        }
        if(flag==false) cout<<0;
        cout<<endl;
    }
}
