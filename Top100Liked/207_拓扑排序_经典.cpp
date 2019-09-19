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







//leetcode 答案
//https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};







//AC
class Digraph_Leetcode{
private:
    int V;
    int E;
    vector<vector<int>> adj;            //邻接链表
    void addEdge(int v,int w){
        adj[v].push_back(w);            //区别于无向图
    }
public:
    Digraph_Leetcode(int v):V(v),E(0){adj.resize(v,vector<int>());};
    Digraph_Leetcode(int num_course,vector<vector<int>>& input){
        adj.resize(num_course,vector<int>());
        for( auto tmp : input){
            addEdge(tmp[0],tmp[1]);
        }
        V = num_course;
        E = input.size();
    };
    int getV(){return V;}
    int getE(){return E;}
    int degree(int v){return adj[v].size();}
    vector<int> getadj(int v){return adj[v];}

    //反转图
    Digraph_Leetcode* reverseG(){
        Digraph_Leetcode* revG = new Digraph_Leetcode(V);
        for(int v=0;v<V;v++){
            for(int w : getadj(v))
                revG->addEdge(w,v);
        }
        return revG;
    }

};

class DFSDirectedCycle_Leetcode{
private:
    vector<bool> marked;
    vector<int> edgeTo;
    vector<bool> onstack;
    stack<int> cycle;

public:
    DFSDirectedCycle_Leetcode(Digraph_Leetcode* G){
        marked.resize(G->getV(),false);
        edgeTo.reserve(G->getV());
        onstack.resize(G->getV(),false);
    }
    bool hasCycle(Digraph_Leetcode* G){
        for(int v=0;v<G->getV();v++){
           if(!marked[v] && cycle.empty())
                dfs(G,v);
        }
        if(!cycle.empty()) return false;
        else return true;
    }
    void dfs(Digraph_Leetcode* G,int v){
        marked[v]=true;
        onstack[v]=true;

        //正常的dfs流程
        for(int w:G->getadj(v)){
            if(!cycle.empty()) return;
            else if(!marked[w]){
                edgeTo[w]=v;
                dfs(G,w);
            }
            //判断是否构成环路
            else if(onstack[w]){
                for(int tmp=v;tmp!=w;tmp=edgeTo[tmp])
                    cycle.push(tmp);
                cycle.push(w); //子节点w是环的终点
            }
        }

        onstack[v]=false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Digraph_Leetcode* G_leetcode = new Digraph_Leetcode(numCourses,prerequisites);
        DFSDirectedCycle_Leetcode* dfsDC_leetcode = new DFSDirectedCycle_Leetcode(G_leetcode);
        return dfsDC_leetcode->hasCycle(G_leetcode);
    }
};

