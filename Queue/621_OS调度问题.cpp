/*
���ȫ��������С�ļ��ʱ��
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
n��ִ����ͬ����֮�������n�����

Ϊ�˱���CPU�����޵�����ѡ��Ͳ��ò���������Ƶ����ȴ��������Ҫ���Ǳ�������صĶ����Ծ����ܳ�
*/

/*
count �����ֵĴ���
n �������
c count==�����ִ��� && ���ִ�����ͬ����ĸ����
ans = (count-1)*(n+1) + c
ans = max(task.size(),ans);

�����пղ��趼����ʱ������������һ������������ʹ��������������񽫸����������뵽���������顣����ֻ�ǷŴ�����ǰ�ļƻ�����֮��ľ��룬���Ҳ��������µĿղ���
*/

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

int leastInterval(vector<char>& tasks, int n){
    std::unordered_map<char,int>mp;
    int count = 0;
    for(auto e : tasks)
    {
        mp[e]++;
        count = std::max(count, mp[e]);
    }

    int ans = (count-1)*(n+1);
    for(auto e : mp)
        if(e.second == count) ans++;

    return std::max((int)tasks.size(), ans);
}

//**********************����
int main(int argc,char** argv){
    vector<char> task;
    task.reserve(64);
    task.push_back('A');
    task.push_back('A');
    task.push_back('A');
    task.push_back('B');
    task.push_back('B');
    task.push_back('B');

    cout<<leastInterval(task,2)<<endl;
    return 0;
}
