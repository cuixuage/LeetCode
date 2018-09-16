/*
两个篮子 每个篮子只能存放同一种水果
连续遍历水果树 遍历元素最多的值是多少？
Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.
*/

//连续相同object的变型  object指的是两个basket
//递推公式

//Accept   一次
int totalFruit(vector<int>& tree){
    int len = tree.size();
    if(len <= 2) return len;
    int maxRes = 0;
    vector<int> ans(len,0);         //每个元素为止的水果树遍历数目
    vector<int> basket;
    vector<int> tmp(len,1);        //当前元素之前连续相同的个数
    ans[0]=1; ans[1]=2;
    basket.push_back(tree[0]);
    if(tree[0] != tree[1])
        basket.push_back(tree[1]);
    else
        tmp[1]++;

    for(int i=2;i<len;i++){
        if(tree[i] == tree[i-1])
            tmp[i] = tmp[i-1] + 1;
        if(judge(tree[i],basket))
            ans[i] = ans[i-1]+1;           //递推公式 = ans[i-1]+1
        else{
            basket[0] = tree[i-1];
            basket[1] = tree[i];
            ans[i] = tmp[i-1]+1;            //递推公式=pre连续个数+1
        }
        if(maxRes < ans[i]) maxRes=ans[i];
    }
    return maxRes;
 }

//遍历元素在basket中返回true
bool judge(int k,vector<int>& basket){
    if(basket.size() <= 1){
        basket.push_back(k);
        return true;
    }
    else if(k == basket[0] || k==basket[1])
        return true;
    else
        return false;
}
