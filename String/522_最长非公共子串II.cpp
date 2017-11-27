/*
�Ա� 521��
522 ����Լ��խ Ŀ�ⲻ�ü��ϳ̶��ж� ֱ�ӱ�������
*/

/*˼·2:
sort �����ַ����������� ���û���ظ�,����ַ�����Ϊ���
max.length�ַ����ظ� ���ճ���˳���ж���һ�� + ��һ���ַ��������������ַ���(other bigger str)���Ӵ�
*/

#include "func.h"
bool hasCommon(string a,string b)
{
    int remine = a.size();
    int remine2 = b.size();
    for(; remine>0&&remine2>0;)
    {
        int i = a.size()-remine;    //��0��ʼ����Ԫ��
        int j = b.size()-remine2;
        if(a.at(i) == b.at(j))
        {
            remine--;
            remine2--;
        }
        else                      //Ѱ��b����һ������a��һ����ͬԪ��
        {
            remine2--;
        }
    }
    return remine==0;
}
////����ش�  ��Ҫ�ж� b���ܷ�Ѱ�ҵķ��������Ӵ� == a
////���Ǽ򵥵������Ӵ�������ϵ
//bool hasCommon(string a,string b){
//    if(a.find(b)!=string::npos || b.find(a)!=string::npos)
//        return true;
//    else
//        return false;
//}

int findLUSlength(vector<string>& strs)
{
    int maxLen = -1;
    int i,j;
    for(i = 0; i<strs.size(); ++i)  //����ÿһ��Ԫ��
    {
        int currentLen = strs[i].length();              //str����
        bool all = true;
        //***�����������0 ��ʼ�������� ��Ҫ��֤ÿһ��biggerԪ�ض�������Ԫ��
        for(j= 0; j<strs.size(); ++j)
        {
            if(i!=j && hasCommon(strs[i], strs[j]))      //Ѱ�Ҵ�str ����������Ԫ�ص����ǹ����Ӵ�
            {
                all = false;
                break;
            }
        }
        if(all==true)
        {
            maxLen = maxLen<currentLen?currentLen:maxLen;   //maxlen�������ֵ
        }
    }
    return maxLen;
}


int main()
{
    vector<string> strs;
    strs.reserve(32);
    strs.push_back("aaa");
    strs.push_back("aaa");
    strs.push_back("aa");
    cout<<findLUSlength(strs)<<endl;

    return 0;
}
