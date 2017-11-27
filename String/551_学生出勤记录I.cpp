/*字符串中不包含 A多于1次 或者 连续的L多于2次 =》 包含A不多于1次 且 L不多于2次*/

#include "func.h"
//bool checkRecord(string s) {
//    int hashtable[26]={0};     //遇到字母的遍历问题 首先考虑hash表
//    for(auto c : s)
//        hashtable[c-'A'] ++;
//    if(hashtable['A'-'A']<=1 &&
//       hashtable['L'-'A']<=2)      //不多于两个连续的L
//       return true;
//    else
//        return false;
//}


//仍需思考 else if  与 if之间区别
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
