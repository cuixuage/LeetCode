/*
完成全部任务最小的间隔时间
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
n是执行相同任务之间必须有n个间隔

为了避免CPU在有限的任务选择和不得不坐在那里频繁冷却，至关重要的是保持任务池的多样性尽可能长
*/

/*
count 最多出现的次数
n 给定间隔
c count==最多出现次数 && 出现次数相同的字母个数
ans = (count-1)*(n+1) + c
ans = max(task.size(),ans);

当所有空步骤都填满时，就像我们有一个完整的任务和处理其余的任务就像将更多的任务插入到完整的数组。插入只是放大了以前的计划任务之间的距离，并且不会引入新的空步骤
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

//**********************测试
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
