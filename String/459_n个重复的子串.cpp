/*����ȫ����Сд��ĸ��string��˵ �Ƿ����һ���Ӵ�str
ʹ��N���ظ���str ����ԭ�е�string*/

#include "func.h"
/*
1.�Ӵ��ĳ�����Ҫ��string�ĳ���
2.�����ظ�����n
3.n���ظ����Ӵ� �Ƿ�equals(string)?
*/
bool repeatSubstringingPattern(string str){
    int strlen = str.length();
    //����Ѱ�Ҹ�Ѹ��
    for(int i=strlen/2;i>=1;i--){
        string temp;
        if(strlen%i == 0){ //�Ӵ����ȱ�����
            int n=strlen/i;
            string token = str.substr(0,i);
            for(int j=0;j<n;j++)
                temp += token;
        }
        if(temp == str) return true;
    }
    return false;
}

int main(){
    string s1="abab";
    string s2="aba";
    cout<<repeatSubstringingPattern(s1)<<endl;
    cout<<repeatSubstringingPattern(s2)<<endl;
    return 0;
}
