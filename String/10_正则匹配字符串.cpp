/*
. �������ַ�
* ����0�������ַ�
*/

//����1: �ݹ�
#include "func.h"
// '*'ֻ�ᵱ���ڶ��ַ���ʹ��

bool isMatch(string text, string pattern){
    if(pattern.empty()) return text.empty();
    bool first_match = (!text.empty() && (pattern.at(0) == text.at(0)
                                          || pattern.at(0)=='.') );
    if(pattern.length() >=2 && pattern.at(1)=='*'){
            //* ��������ַ�  pattern�ӵ������ַ�����Ϊ�µ�����
        return (isMatch(text,pattern.substr(2))
            //* �������ַ� text�ɹ�ƥ��һ���ַ�
                || (first_match && isMatch(text.substr(1),pattern) ));
    }
    //���ַ�������==1 ���� �ڶ����ַ�����'*' (�����ַ�����ƥ��)
    else
        return first_match &&isMatch(text.substr(1),pattern.substr(1));

}

 bool isMatch_2(const char *s, const char *p) {
    string text=s;      //��ʼ�� string text(s);
    string pattern=p;   //string pattern(p);
    if(pattern.empty()) return text.empty();
    bool first_match = (!text.empty() && (pattern.at(0) == text.at(0)
                                          || pattern.at(0)=='.') );
    if(pattern.length() >=2 && pattern.at(1)=='*'){
        return (isMatch(text.c_str(),pattern.substr(2).c_str())
                || (first_match && isMatch(text.substr(1).c_str(),pattern.c_str()) ));
    }
    else return first_match &&isMatch(text.substr(1).c_str(),pattern.substr(1).c_str());

    }

int  main(){
    string text="aab";
    string pattern = "c*a*b";
    cout<<isMatch(text,pattern)<<endl;
    return 0;
}
