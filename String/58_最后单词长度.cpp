/*
�ɵ��ʺ�' '��ɵ��ַ��� �����һ�����ʵĳ���
����: "a " return 1;
    "   "  return 0;
*/

#include "func.h"

int lengthOfLastWord(string s)
{
    stringstream ss(s);
    string temp;
    vector<string> ans;             //�ؼ�:����ÿһ����' '�и���string
    ans.reserve(32);
    while(getline(ss,temp,' '))
    {
        ans.push_back(temp);
    }
    std::reverse(ans.begin(),ans.end());
    for(auto i : ans)
    {
        if(i!="") return i.length();           //����: "a " ����0
    }
    return 0;
}
