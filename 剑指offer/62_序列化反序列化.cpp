/*
对于二叉树的序列化反序列化,  Tree序列化string
思路1:
BFS 按层级保存保存节点value,NULL指针保存为"$"
反序列化时: queue用来按层级遍历,每个Node对应string中两个value 
e.g. TreeNode* root = new TreeNode(int);

思路2：
DFS

*/

#include "func.h"

//BFS
string encoder(TreeNode* root){
    string ans="";
    queue<TreeNode*> q;
    if(root==NULL) return ans;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        if(top==NULL) ans += "$,";
        else{
            q.push(top->left);
            q.push(top->right);
            ans += std::to_string(top->val) + ",";
        }
    }
    return ans;
}

TreeNode* decoder(string s){
    if(s.size()==0) return NULL;
    queue<TreeNode*> q;
    vector<string> values;
    stringstream iss(s);
    string tmp;
    while(getline(iss,tmp,',')) values.push_back(tmp);
    TreeNode* left = new TreeNode(std::atoi(values[i].c_str()));
    q.push(root);
    for(int i=1; i<values.size(); i++){
        TreeNode* curRoot = q.front();
        q.pop();
        if(values[i] != "$"){
            TreeNode* left = new TreeNode(std::atoi(values[i].c_str()));
            curRoot->left = left;
            q.push(left);
        }
        if(values[++i] != "$"){
            TreeNode* right = new TreeNode(std::atoi(values[i].c_str()));
            curRoot->right = right;
            q.push(right);
        }
    }
    return root;
} 

//DFS preorder
string encoder(TreeNode* root){
    stringstream out;
    encoderHelp(root,out);
    return out.str();
}
void encoderHelp(TreeNode* root,stringstream& out){
    if(root==NULL)
        out<<"# ";
    else{
        out<<root->val<<' ';
        encoderHelp(root->left,out);
        encoderHelp(root->right,out);
    }
}

TreeNode* decoder(string s){
    stringstream in(s);
    return decoderHelp(in);
}
TreeNode* decoderHelp(stringstream& in){
    string val;
    in >> val;      //stringstream默认按照空格切分
    if(val == "#")  return NULL;
    TreeNode* root = new TreeNode(std::stoi(val));
    root->left = decoderHelp(in);
    root->right = decoderHelp(in);
    return root;
}

/*  C++11 stoi
std::stoi("45") is 45
std::stoi("3.14159") is 3
std::stoi("31337 with words") is 31337
*/