/*
给定一个字符串 按照前序遍历验证其是否能构建二叉树   根->前->后
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;
using std::stringstream;

//切割字符串 stringstream+getline
vector<string> splitElement(string preorder){
    stringstream ss(preorder);
    string temp;
    vector<string> res;
    while(getline(ss,temp,',')){
        res.push_back(temp);
    }
    return res;
}
//判断 前序序列能否构建二叉树
//前提 string前序序列所有的叶子节点都是按照 # 占据  即二叉树将始终是满的
/*
当您遍历预订遍历字符串时，对于每个字符：

情况1：你看到一个数字c，意味着你开始扩展一个以c为根的新树，你把它推到堆栈

情况2.1：你看到一个＃，而顶部的堆栈是一个数字，你知道这是一个左空的孩子，把它作为下一个来的节点k的标记，知道它是正确的孩子。

情况2.2：你看到＃，而顶部的堆栈是＃，你知道你认为这个＃作为一个空的小孩，你现在取消这个子树的子树（例如，根据t）。但等待，取消后，你继续检查堆栈是否＃或一个数字：

----如果一个数字，说你，你知道你刚刚取消了一个是u的孩子的节点t。您需要在堆栈顶部留下＃标记。所以下一个节点知道这是一个正确的孩子。

----如果一个＃，你知道你刚刚取消了一棵树，它的根t是你的右边孩子。所以你继续取消你的子树，这个过程是继续的。
*/
bool isValidSerialization(string preorder){
    if(preorder == "") return false;
    stack<string> tree;
    vector<string> element = splitElement(preorder);
    for(unsigned i=0;i<element.size();i++){
        string curr = element.at(i);
        while(curr=="#" && !tree.empty() && tree.top()=="#"){
            tree.pop();
            if(tree.empty()) return false;
            tree.pop();
        }
        tree.push(curr);
    }
    return tree.size()==1 && tree.top()=="#" ? true:false;
}

//方法2: 度数  postorder(倒序排列验证则可以先string反转)
/*
当下一个节点到来时，我们然后减少diff1，因为节点提供了一个度数。
如果节点不是null，我们增加差异2，因为它提供两个度数。如果序列化是正确的，diff不应该是负的，并且在完成时diff将为零
*/
bool isValidSerialization_2(string preorder){
    vector<string> nodes = splitElement(preorder);
    int diff = 1;
    for (auto node : nodes) {
        if (--diff < 0) return false;
        if (node != "#") diff += 2;
    }
    return diff == 0? true:false;
}


//*****************************测试
int main(int argc,char** argv){
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool res = isValidSerialization_2(preorder);
    cout<<res<<endl;

    return 0;
}
