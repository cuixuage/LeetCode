/*
给定有效时间,在可以重复使用当前时间数字的情况下如何使得时间最小？
Input: "23:59"
Output: "22:22"
思路: 将时间转化为分钟,遍历一整天24*60分钟寻找其结果时间的每一位数字都在原时间内
*/
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<cstdlib>
using std::string;
using std::cout;
using std::endl;
using std::stringstream;

string nextClosestTime(string time) {
    stringstream ss(time);
    string hour,minute;
    getline(ss,hour,':');
    getline(ss,minute,':');
    int curr=std::atoi(hour.c_str())*60+std::atoi(minute.c_str())*1;
    string newtime="0000";
    int mins[]={600,60,10,1};

    for(int i=1, d=0;i<=24*60,d<4;i++)   //对于curr后面的每一分钟;注意d的作用
    {
        int next=(curr+i)%(24*60);       //思考:为什么要取余数？

        for(d=0;d<4;d++){                //digit属于time 则d++
            newtime[d]='0'+next/mins[d];
            next %= mins[d];
            if(time.find(newtime[d]) == string::npos) break;
        }
    }
    //d==4  digit全部属于time时
    return newtime.substr(0,2)+":"+newtime.substr(2,2);
}

//***************************
int main(){
    cout<<nextClosestTime("23:59")<<endl;
    return 0;
}


/*//*********************substr实例
basic_string substr( size_type pos = 0,
                     size_type count = npos ) const;


#include <string>
#include <iostream>

int main()
{
    std::string a = "0123456789abcdefghij";

    // count is npos, returns [pos, size())
    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';

    // both pos and pos+count are within bounds, returns [pos, pos+count)
    std::string sub2 = a.substr(5, 3);
    std::cout << sub2 << '\n';

    // pos is within bounds, pos+count is not, returns [pos, size())
    std::string sub4 = a.substr(a.size()-3, 50);
    std::cout << sub4 << '\n';

    try {
        // pos is out of bounds, throws
        std::string sub5 = a.substr(a.size()+3, 50);
        std::cout << sub5 << '\n';
    } catch(const std::out_of_range& e) {
        std::cout << "pos exceeds string size\n";
    }
}
*/
