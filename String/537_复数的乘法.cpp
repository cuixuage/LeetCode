/*
str1= a+bi
str2= c+di  其中a,b,c,d ∈ [-100,100]
求 str1*str2 的结果
*/

#include "func.h"
string complexNumberMultiply(string str1, string str2) {
    int a, b, c, d;
    char buff;                   //***********思考为什么不能用string
    stringstream aa(str1), bb(str2), ans;
    aa >> a >> buff >> b >> buff;
    bb >> c >> buff >> d >> buff;
    ans << a*c - b*d << "+" << a*d + c*b << "i";
    //cout<<buff<<endl;
    return ans.str();
}

int main(){
    string str1="1+1i";
    string str2="1+1i";
    cout<<complexNumberMultiply(str1,str2)<<endl;
    return 0;
}
