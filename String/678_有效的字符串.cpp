
/*�������ָ�ʽ( * )�ַ��ܷ������������Ϊ��Ҫ����ַ���*/
//����1: �������(��ʱ)
//����2: ��̬�滮
//����3: ̰��greedy

/*
������lo, hi�ֱ�Ϊ�������ŵ���С�������������Ĵ����ַ����еĵ�ǰ�ַ�֮��

����������������ţ�c == '('������ôlo++���������ǿ���дһ�������ţ�����lo--�������������ʲô�����������ţ�c != ')'������ôhi++���������Ǳ���дһ�������ţ�����hi--�����hi < 0����ô�������ǵ�ѡ����ʲô��������ʹ��ǰ��ǰ׺��Ч�����ң�������Զ��������0�������š��������Ӧ�ü�飬���ǿ�������ȷ��0�������š�
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

//*********����
int main(){
    string s = "(**)";
    cout<<checkValidString(s)<<endl;
    return 0;
}
