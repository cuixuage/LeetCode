/*
vector<int>数组所有元素组成的最小整数
思路:
由于最后的位数是一样的,所以数组元素转化string后重写compare函数
（可能会溢出,所以使用string； 不能直接按照字典序排列）
*/

#include "func.h"
//compare函数写在类内的时候  需要加上static标识


//思路1:  求全排列问题 再拼接起来比较大小
//思路2: 
static bool compare(const string& a,const string& b){   //关键
    string t1 = a+b;        //拼接字符串 e.g. “321”+“32”=="32132"
    string t2 = b+a;
    return t1<t2?true:false;
}
string int2str(int a){
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}
string PrintMinNumber(vector<int>& numbers){
    int length = numbers.size();
    vector<string> numbers_str(length,"");
    for(int i=0;i<length;i++)
        numbers_str[i] = int2str(numbers[i]);
    std::sort(numbers_str.begin(),numbers_str.end(),compare);
    string ans = "";
    for(auto i:numbers_str)
        ans += i;
    return ans;
}