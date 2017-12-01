/*
Ѱ�ҵ�n�������  string����
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211
 */

#include "func.h"
string countAndSay(int n)
{

    if (0 == n) return "";
    if (1 == n) return "1";

    std::string res="1";
    std::string s;

    for (int i = 1; i < n; i++)     // run from starting to generate second string
    {

        int len = res.size();

        //cheack all digits in the string
        for (int j = 0; j < len; j++)
        {

            int count=1; // we have at least 1 occourence of each digit

            //�ؼ� �������һ���ַ� �� ��ǰ�ַ��ͺ���һ���ַ���ͬ
            // get the number of times same digit occurred (be carefull with the end of the string)
            while ((j + 1 < len) && (res[j] == res[j + 1]))
            {
                count++;
                j++;        // we need to keep increasing the index inside of the string
            }

            // add to new string "count"+"digit itself"
            s += string::to_string(count) + res[j];
        }

        // save temporary result
        res = s;

        // clean our string-helper
        s.clear();

    }

    return res;
}

int main(){
    cout<<countAndSay(10)<<endl;
    return 0;
}
