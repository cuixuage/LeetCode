/*���� ��������ĸ��д ȫ����ĸ��д  û�д�д�ַ� ����ȷ���ַ���*/

#include "func.h"

//AC 2��
bool detectCapitalUse(string word){
    int count=0;
    if(word.length()==0) return false;
    for(auto w : word){
        if(w>='A' && w<='Z')
            count++;
    }
    if(count==0) return true;
    else if(count==word.length()) return true;
    else if(count==1 && word[0]>='A' && word[0]<='Z') return true;
    else return false;
}

int main(){
    string word = "abcdS";
    cout<<detectCapitalUse(word)<<endl;
    return 0;
}
