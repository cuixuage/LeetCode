/*
Input: "Hello, my name is John"
Output: 5
*/

#include "func.h"
int countSegments(string s)
{
    int segmentCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((i == 0 || s.at(i-1) == ' ') && s.at(i) != ' ')
        {
            //һ���µ�segement
            segmentCount++;
        }
    }
    return segmentCount;
}
////��������
//int countSegments(string s)
//{
//    int count = 0;
//    string temp;
//    stringstream ss(s);
//    while(getline(ss,temp,' ') && temp.find(' ')==string::npos){
//
//        count++;
//    }
//    return count;
//}

int main()
{
    string s = "   ";
    cout<<countSegments(s)<<endl;
    return 0;
}
