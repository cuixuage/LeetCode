#include "func.h"
/*
最近的共同父节点  假设元素都是不相同的
思路: 保存root->结点得路径,这两条路径的最后一个公共节点即为公共父节点
转化:
root->node的路径问题
*/

/////////////////////////////////////AC’
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

//1.寻找root到leaf的路径
void findPath(TreeNode* root,vector<TreeNode*>& mypath,vector<TreeNode*>& store_path,int val){
    if(root==NULL) return ;
    mypath.push_back(root);
    if(root->val == val) {store_path = mypath;return;}                  //前序遍历思想:  将路径保存下来
    if(root->left) findPath(root->left,mypath,store_path,val);
    if(root->right) findPath(root->right,mypath,store_path,val);
    mypath.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return NULL;
    TreeNode* root_tmp = root;
    vector<TreeNode*> path_p;
    vector<TreeNode*> path_q;
    vector<TreeNode*> store_p;
    vector<TreeNode*> store_q;
    findPath(root_tmp,path_p,store_p,p->val);
    findPath(root,path_q,store_q,q->val);
    int index = 0;
    for(int i=0;i<std::min(store_p.size(),store_q.size()); i++){
        if(store_p[i]->val == store_q[i]->val)
            index = i;
        else
            break;
    }
    return store_p[index];
}

/////////////////////////////   思路: 自顶向下  时间O(N^2)  空间O(N)

/*查找二叉树中两个结点最低公共祖先结点*/
node* LCA(node *root, node *p, node *q) 
{
    if (hasNode(root->left, p) && hasNode(root->left, q)) //p和q都在左子树中        
        return LCA(root->left, p, q);
    if (hasNode(root->right, p) && hasNode(root->right, q)) //p和q都在右子树中
        return LCA(root->right, p, q);
    return root;             //关键                           //p和q一个在左子树，一个在右子树中，直接返回root
}
 
/*判断root为根的树是否包含结点p*/
bool hasNode(struct node* root, struct node* p)
{
    if (!root) return false;
    if (root == p)
        return true;
    return hasNode(root->left, p) ||  hasNode(root->right, p);
}

//////////////////////////////  思路:  自底向上  O(N)时间复杂度
typedef struct node Node;
//两个节点要么在左子树上，要么在右子树上
Node *LCA(Node *root, Node *p, Node *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  Node *L = LCA(root->left, p, q);
  Node *R = LCA(root->right, p, q);
  if (L && R) return root;  // 如果p和q位于不同的子树  
  return L ? L : R;  //p和q在相同的子树，或者p和q不在子树中   
}

//////////////////////////////非递归  思路: 前序遍历 + hashmap保存节点的父节点
