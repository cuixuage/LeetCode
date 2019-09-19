#include "func.h"
/*
一共有0,1,2...,n-1门课程; 给定先决条件,判断是否能上完这n门课程
先决条件array = [[after_curse,pre_course],[after_course,pre_course]]
*/

/*
目标: 判断图是不是有环
无权有向图  ==> 二维邻接数组保存顶点和顶点的方向  && 一维数组保存顶点的入度大小
只有入度为零的顶点,才会加入队列
*/
bool cycleJudge(vector<vector<int>>& edge, vector<int>& inDegree, int nodeNum){
    queue<int> Q;
    for(int i=0;i<inDegree.size();i++)
        if(inDegree[i]==0) Q.push(i);          //入度为0的顶点加入Queue
    int my_count = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        my_count ++;
        for(int i=0;i<edge[cur].size();i++){   //1.相连节点的入度减一 2.入度为0,则加入Queue
            int other_node = edge[cur][i];
            inDegree[other_node] --;
            if(inDegree[other_node] == 0)
                Q.push(other_node);
        }
    }
    return my_count==nodeNum?true:false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> edge(numCourses,vector<int>());
    vector<int> inDegree(numCourses,0);
        for(auto tmp : prerequisites){
            edge[tmp[1]].push_back(tmp[0]);
            inDegree[tmp[0]]++;
        }
    return cycleJudge(edge, inDegree, numCourses);
}