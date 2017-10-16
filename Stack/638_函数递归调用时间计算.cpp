/*��������������ʽ �õ�ÿһ������ʵ������ʱ��
Input:
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]

˵����
����0��ʱ��0��ʼ��Ȼ��ִ��2����λ��ʱ�䲢����ʱ�����1��
���ں���0 ���ú���1������1��ʱ��2��ʼ��ִ��4����λ��ʱ�䲢��ʱ��5������
����0��ʱ��6�ٴ����У�������ʱ��6�������Ӷ�ִ��1����λ��ʱ�䡣
���Ժ���0��ȫִ��2 + 1 = 3����λ��ʱ�䣬����1��ȫִ��4����λ��ʱ�䡣

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
struct Log{          //**********************�������� ����id ʱ��timstamp ���ߵĶ�Ӧ��ϵ
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
    stack<Log> stack_Log;        //************����start״̬�ĺ���
    for(string log:logs){        //**********2
        int colon1 = log.find(":", 0);
        int colon2 = log.find(":", colon1 + 1);
        string temp = log.substr(0, colon1);
        string temp2 = log.substr(colon1 + 1, colon2 - (colon1 + 1));
        string temp3 = log.substr(colon2 + 1);

        Log item = {std::atoi(temp.c_str()),temp2,std::atoi(temp3.c_str())};

        if(item.status=="start"){   //******************3   ÿ��start ��timestampʱ�����stack
            stack_Log.push(item);
        }else{
            //************************4
            int time_added = item.timestamp -stack_Log.top().timestamp+1;
            times[item.id] += time_added;
            stack_Log.pop();
            //***********************5  stack.top().id����һ�����ò�
            if(!stack_Log.empty()){
                //assert(st.top().status == "start");
                times[stack_Log.top().id] -= time_added;
            }
        }
   }
    return times;
}

//*************************************����
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
ע�ͣ�
1. hash˼�� ����id�ű���ʱ��  ����֪��������Ÿ���N
2. �ַ����и�
       std::stringstream ss(log);
       string temp,temp2,temp3;
       getline(ss,temp,':');   //Ĭ���ǻ��з��и�
       getline(ss,temp2,':');
       getline(ss,temp3,':');
3. assert(st.top().id==item.id);   //ÿһ��end��Ȼ��stack top���  �о����沨�����ʽ����
   id����time = end - start +1 -(�ݹ���ú���ʱ��)
4.stack.top����һ�����ò� ;��һ������ - ������id����ʹ��ʱ��
*/

/*/***********getline�Ķ��� istream + string + char
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
                                           std::basic_string<CharT,Traits,Allocator>& str,
                                           CharT delim );
*/
