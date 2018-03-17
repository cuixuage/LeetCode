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
//����������������к�
int maxInAll(vector<int>& order)
{
    vector<int> maxInHere(order.size());
    maxInHere[0] = order[0];
    int maxAll = 0;
    if(order[0]>0) maxAll=order[0];

    for(int i=1; i<order.size(); ++i)
    {
        maxInHere[i] = std::max(order[i],maxInHere[i-1]+order[i]);			//�ؼ�  ��ϸ���
        maxAll = std::max(maxInHere[i],maxAll);
    }
    return maxAll>0?maxAll:0;
}
//���Ѱ����ʼλ�ã�  ͨ��endλ����ǰѰ�� while(maxInHere>0) ��ֹλ�ü�Ϊstart
//������������ÿһ��Ԫ��maxInHere����Ҫ������(�������С����ı�Ȼ��������)
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
        cout<<"����ȫΪ����,����0"<<endl;
    }
    else
    {
        //��������ʼλ��֮������Ԫ��
        for(int i=End; maxInHere[i]>0 && i>=0; --i) //ע���ж�������λ��
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
//���� -2 1 -3 4 -1 2 1 -5 4  output:6 [4,-1,2,1]
//����  -1                    output: 0  []
//���� 0 0 0 -1               output:4  [0]

int main(int argc,char** argv)
{
    cout<<"���ո��и������������ɸ�: ";
    string str;
    getline(cin,str);
    vector<int> order = getSplit(str);
    int answer = maxInAll(order);            //��ȡ��������к�

    vector<int> maxOrder = startEnd(order); //��ȡ�����������ʼλ��֮������Ԫ��
    cout<<"answer: "<<answer<<endl;
    cout<<"[";
    for(auto i=maxOrder.begin();i!=maxOrder.end();i++){
        if(i!=maxOrder.end()-1) cout<<*i<<",";
        else cout<<*i;
    }
    cout<<"]"<<endl;
    return 0;
}
