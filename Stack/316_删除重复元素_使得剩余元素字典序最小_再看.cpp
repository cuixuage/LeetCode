/*
ɾ��string�ظ�Ԫ�� ͬʱʹ��result�����������п�����������˳����С��һ��
*/

//greedy ����string˳�� �����ұ���
//Ѱ�����ظ���Ԫ�� ���ֵ�����С����һ�� ���ڽ���������
//������ֵ�����С��Ԫ���Ƿ��ظ��� ˵���Ǳ��������result�е� ����ѭ��

#include<string.h>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;

//******************��ϸ��� + ������д�ķ���Ϊʲô����
//��https://discuss.leetcode.com/topic/31404/a-short-o-n-recursive-greedy-solution/10
//p ����// the position for the smallest s[i]
string removeDuplicateLetters(string s)
{
    string res;
    int p=0;
    while(p<s.size())
    {
        vector<int> cnt(256,0);
        for(int i=p; i<s.size(); i++) if(s[i]!='}') cnt[s[i]]++;
        int nxtp=p;
        for(int i=p; i<s.size(); i++)
        {
            if(s[i]<s[nxtp]) nxtp=i;    //��ǰ�ֵ�����С��λ��
            if(--cnt[s[i]]==0) break; //unique in suffix s[i...]
        }
        for(int j=p; j<s.size(); j++)
        {
            // s[j]�ظ���Ԫ�ش���nxtp����ȫ��ɾ��
            if(j<nxtp || s[j]==s[nxtp] && j>nxtp) s[j]='}';
        }
        while(p<=nxtp || s[p]=='}') p++;   //����p��λ�õ���δɾ�����ظ���Ԫ�� ��λ��
    }
    for(auto c: s) if(c!='}') res.push_back(c);
    return res;
}




//string removeDuplicateLetters(string s)
//{
//    int cnt[26]={0};
//    int pos = 0; // the position for the smallest s[i]
//    for (int i = 0; i < s.length(); i++)   //��¼stringÿһ��Ԫ���Ƿ��ظ� >1
//        cnt[s.at(i) - 'a']++;
//
//    for (int i = 0; i < s.length(); i++)  //string������Ѱ���ֵ�����СԪ��
//    {
//        if (s.at(i) < s.at(pos)) pos = i;
//        if (--cnt[s.at(i) - 'a'] == 0) break;   //�����������з��ظ���Ԫ�� ��ֹ����
//    }
//
//    string temp="";
//    if(s.length()==0) return "";
//    else {
//        temp= s.substr(pos+1);
//        cout<<temp<<endl;
//        int k = temp.find(s.at(pos),0);
//        while(k!=string::npos){   //ע�� s.at ԭ���ַ�����posλ��
//            temp.erase(k,k+1);
//            k = temp.find(s.at(pos),k);
//        }
//    }
//
//    return s.at(pos)+removeDuplicateLetters(temp);
//    /*
//    �����replace��ʽ
//    string temp = s.substr(pos+1,s.length());    //0��ʼ [pos+1,end() )
//    temp.replace(temp.begin(),temp.end(),""+s.at(pos), "");
//    */
//
//    //return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters
//    //(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
//}

int main()
{
    string s="cbacdcbc";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;
}
