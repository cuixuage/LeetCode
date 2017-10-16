/*给定函数调用形式 得到每一个函数实际运行时间
Input:
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]

说明：
功能0在时间0开始，然后执行2个单位的时间并到达时间结束1。
现在函数0 调用函数1，函数1在时间2开始，执行4个单位的时间并在时间5结束。
功能0在时间6再次运行，并且在时间6结束，从而执行1个单位的时间。
所以函数0完全执行2 + 1 = 3个单位的时间，功能1完全执行4个单位的时间。

https://leetcode.com/problems/exclusive-time-of-functions/solution/
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<cassert>
#include <cstdlib>
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;
struct Log{          //**********************用来保存 函数id 时间timstamp 两者的对应关系
    int id;
    string status;
    int timestamp;
    friend std::ostream& operator <<(std::ostream &os,const Log& log);
};
std::ostream& operator <<(std::ostream &os,const Log& log){
    os<<log.timestamp;
    return os;
}
vector<int> exclusiveTime(int n,vector<string>& logs){
    vector<int> times(n,0);      //********* 1
    stack<Log> stack_Log;        //************保存start状态的函数
    for(string log:logs){        //**********2
        int colon1 = log.find(":", 0);
        int colon2 = log.find(":", colon1 + 1);
        string temp = log.substr(0, colon1);
        string temp2 = log.substr(colon1 + 1, colon2 - (colon1 + 1));
        string temp3 = log.substr(colon2 + 1);

        Log item = {std::atoi(temp.c_str()),temp2,std::atoi(temp3.c_str())};

        if(item.status=="start"){   //******************3   每次start 将timestamp时间加入stack
            stack_Log.push(item);
        }else{
            //************************4
            int time_added = item.timestamp -stack_Log.top().timestamp+1;
            times[item.id] += time_added;
            stack_Log.pop();
            //***********************5  stack.top().id是上一级调用层
            if(!stack_Log.empty()){
                //assert(st.top().status == "start");
                times[stack_Log.top().id] -= time_added;
            }
        }
   }
    return times;
}

//*************************************测试
int main(int argc,char** argv){
    vector<string> logs;
    logs.reserve(64);
    vector<int> result;
    result.reserve(64);
    logs.push_back("0:start:0");
    logs.push_back("1:start:2");
    logs.push_back("1:end:5");
    logs.push_back("0:end:6");
    result = exclusiveTime(2,logs);
    for(auto i:result){
        cout<<i<<endl;
    }
    return 0;

}
/*
注释：
1. hash思想 按照id号保存时间  必须知道函数编号个数N
2. 字符串切割
       std::stringstream ss(log);
       string temp,temp2,temp3;
       getline(ss,temp,':');   //默认是换行符切割
       getline(ss,temp2,':');
       getline(ss,temp3,':');
3. assert(st.top().id==item.id);   //每一个end必然和stack top配对  感觉和逆波兰表达式相似
   id函数time = end - start +1 -(递归调用函数时间)
4.stack.top是上一级调用层 ;上一级函数 - 被调用id函数使用时间
*/

/*/***********getline的定义 istream + string + char
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                           std::basic_string<CharT,Traits,Allocator>& str,
                                           CharT delim );
*/
