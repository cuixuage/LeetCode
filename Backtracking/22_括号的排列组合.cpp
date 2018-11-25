/*
给定数量的括号 选择所有的括号的排列组合
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
*/

//回溯 DFS
//思路：二叉树的左右子树  左边加"("  右边加")"
//如果当left<right说明出现 ")(" 
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesis(n,n,"",res);
    return res;
}

void generateParenthesis(int left,int right,string out,vector<string>& res){
    //剩余的左括号数量大于右括号数量
    if(left > right) return;
    if(left==0 && right==0) res.push_back(out);
    else{
        if(left > 0) generateParenthesis(left-1,right,out+"(",res);
        if(right > 0) generateParenthesis(left,right-1,out+")",res);
    }
}
