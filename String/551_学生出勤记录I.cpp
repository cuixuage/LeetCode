/*�ַ����в����� A����1�� ���� ������L����2�� =�� ����A������1�� �� L������2��*/

#include "func.h"
//bool checkRecord(string s) {
//    int hashtable[26]={0};     //������ĸ�ı������� ���ȿ���hash��
//    for(auto c : s)
//        hashtable[c-'A'] ++;
//    if(hashtable['A'-'A']<=1 &&
//       hashtable['L'-'A']<=2)      //����������������L
//       return true;
//    else
//        return false;
//}


//����˼�� else if  �� if֮������
bool checkRecord(string s){
    int a=0,l=0;
    for(auto c:s){
        if(a>1 || l>2) break;
        if(c!='L') l=0;
        if(c=='L') l++;
        if(c=='A') a++;
    }
    if(a>1 || l>2) return false;
    else return true;
}

int main(){
    string s = "AAAA";
    cout<<checkRecord(s)<<endl;
    return 0;
}
