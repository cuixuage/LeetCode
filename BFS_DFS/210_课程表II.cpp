/*
课程表问题拓展:  获取拓扑排序的遍历顺序
题目: 只要求返回一种可能性
*/
#include "func.h"
vector<int> cycleJudge(vector<vector<int>>& edge, vector<int>& inDegree, int nodeNum){
    queue<int> Q;
    for(int i=0;i<inDegree.size();i++)
        if(inDegree[i]==0) Q.push(i);          //入度为0的顶点加入Queue
    int my_count = 0;
    vector<int> ans;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        my_count ++;
        ans.push_back(cur);
        for(int i=0;i<edge[cur].size();i++){   //1.相连节点的入度减一 2.入度为0,则加入Queue
            int other_node = edge[cur][i];
            inDegree[other_node] --;
            if(inDegree[other_node] == 0)
                Q.push(other_node);
        }
    }
    return my_count==nodeNum?ans:vector<int>();
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edge(numCourses,vector<int>());
    vector<int> inDegree(numCourses,0);
    for(auto tmp : prerequisites){
        edge[tmp[1]].push_back(tmp[0]);
        inDegree[tmp[0]]++;
    }
    return cycleJudge(edge, inDegree, numCourses);
}