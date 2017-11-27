/*
For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

#include"func.h"
void reverseWords(string &s) {
    vector<string> token;
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        token.push_back(temp);        //˼��:�����Ŀո�temp��Ϊ��  Ҳ�ܼ���vector����
    }
    //****erase+remove���� ���ο�
    token.erase(std::remove(token.begin(), token.end(), ""),     //ɾ����Ԫ��
               token.end());
    reverse(token.begin(),token.end());
    string ans="";
    for(auto i:token){
        ans += i + ' ';
    }
    if(ans.length()!=0)
        ans.erase(ans.length()-1,ans.length());
    s = ans;
    }
}

int main(){
    string s = "   ";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
