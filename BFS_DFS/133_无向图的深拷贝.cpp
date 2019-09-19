/*
无向图,没有自环,没有重复边的图
关键: 如何避免同一个节点被多次拷贝？   ==>  UNorderedmap标记
*/

#include "func.h"
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*,Node*> copies;
public:
//BFS
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*> Q;
        Q.push(node);
        Node* copy = new Node(node->val,{});
        copies[node]  = copy;   //新旧节点的对应
        while(!Q.empty()){
            Node* cur = Q.front();
            Q.pop();
            for(Node* neighbor : cur->neighbors){
                if(copies.find(neighbor) == copies.end()){
                    copies[neighbor] = new Node(neighbor->val, {});
                    Q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;        //不要再局部函数内malloc
    }
};