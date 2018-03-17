#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;
//返回最大连续子序列和
int maxInAll(vector<int>& order)
{
    vector<int> maxInHere(order.size());
    maxInHere[0] = order[0];
    int maxAll = 0;
    if(order[0]>0) maxAll=order[0];

    for(int i=1; i<order.size(); ++i)
    {
        maxInHere[i] = std::max(order[i],maxInHere[i-1]+order[i]);			//关键  仔细理解
        maxAll = std::max(maxInHere[i],maxAll);
    }
    return maxAll>0?maxAll:0;
}
//如何寻找起始位置？  通过end位置向前寻找 while(maxInHere>0) 终止位置即为start
//连续子序列中每一个元素maxInHere必须要大于零(如果它是小于零的必然可以舍弃)
vector<int> startEnd(vector<int>& order)
{
    vector<int> maxInHere(order.size());
    vector<int> startEndElement;
    maxInHere[0] = order[0];
    int maxAll = 0;
    if(order[0]>0) maxAll=order[0];
    int start=0,End=0;

    for(int i=1; i<order.size(); ++i)
    {
        maxInHere[i] = std::max(order[i],maxInHere[i-1]+order[i]);
        if(maxInHere[i]>maxAll) End = i;
        maxAll = std::max(maxInHere[i],maxAll);
    }
    if(maxAll==0 && order[0]<0)
    {
        cout<<"序列全为负数,返回0"<<endl;
    }
    else
    {
        //子序列起始位置之间所有元素
        for(int i=End; maxInHere[i]>0 && i>=0; --i) //注意判断条件的位置
            start = i;
        for(;start<=End;start++)
            startEndElement.push_back(order[start]);
    }
    return startEndElement;
}

vector<int> getSplit(string str)
{
    stringstream ss(str);
    string temp;
    vector<int> splitInt;
    while(getline(ss,temp,' '))
    {
        splitInt.push_back(std::atoi(temp.c_str()));
    }
    return splitInt;
}
//测试 -2 1 -3 4 -1 2 1 -5 4  output:6 [4,-1,2,1]
//测试  -1                    output: 0  []
//测试 0 0 0 -1               output:4  [0]

int main(int argc,char** argv)
{
    cout<<"按空格切割输入整数若干个: ";
    string str;
    getline(cin,str);
    vector<int> order = getSplit(str);
    int answer = maxInAll(order);            //获取最大子序列和

    vector<int> maxOrder = startEnd(order); //获取最大子序列起始位置之间所有元素
    cout<<"answer: "<<answer<<endl;
    cout<<"[";
    for(auto i=maxOrder.begin();i!=maxOrder.end();i++){
        if(i!=maxOrder.end()-1) cout<<*i<<",";
        else cout<<*i;
    }
    cout<<"]"<<endl;
    return 0;
}
