#include "func.h"

//95题的思想
////  超时    如果使用vector<int>保存root则超出内存限制
// int numTrees(int n){
//     int ans;
//     if(n==0) return 0;
//     ans = generateTree(1,n);
//     return ans;
// }
// int generateTree(int from,int to){
//     int ans=0;    
//     if(to - from <0) return 1;
//     if(to - from ==0) ans+=1;
//     if(to - from > 0){
//         for(int i=from;i<=to;i++){
//             //left right所有可能的子树  用vector<root>保存起来
//             int l = generateTree(from,i-1);
//             int r = generateTree(i+1,to);
//             ans += l*r;
//             }
//         }
//     //前面每次判断条件跳出后   都会执行此return
//     return ans;
// }

//动态规划解决问题
/*
https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
e.g. 
i属于[1,7]都计算一遍
G(7)= F(i,7)
    = G(i-1) * G(7-i)
G(0)=1  G(1)=1
*/

int numTrees(int n){
    vector<int> ans(n+1,0);
    ans[0]=ans[1]=1;
    //计算到G(n)
    for(int m=2;m<=n;++m){
        //遍历一遍G(m)元素  分别作为root节点
        for(int i=1;i<=m;++i){
            ans[m] += ans[i-1] + ans[m-i];
        }
    }
    return ans[n];
}
