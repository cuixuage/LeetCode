#include "func.h"

//95题的思想
////  超时    如果使用vector<int>保存root则超出内存限制
int numTrees(int n){
    int ans;
    if(n==0) return 0;
    ans = generateTree(1,n);
    return ans;
}
int generateTree(int from,int to){
    int ans=0;    
    if(to - from <0) return 1;
    if(to - from ==0) ans+=1;
    if(to - from > 0){
        for(int i=from;i<=to;i++){
            //left right所有可能的子树  用vector<root>保存起来
            int l = generateTree(from,i-1);
            int r = generateTree(i+1,to);
            ans += l*r;
            }
        }
    //前面每次判断条件跳出后   都会执行此return
    return ans;
}

//动态规划解决问题
/*
https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
e.g. 
1~N的数字组成的unique BST数量G:
G(n) = F(1, n) + F(2, n) + ... + F(n, n)
以i作为root的unique BST的数量  =  左子树的可能数量  *  右子树的可能数量
F[i,N] = G(i-1) * G(N-i)  

==> 
*/

public int numTrees(int n) {
    //0.init
    int [] G = new int[n+1];
    G[0] = G[1] = 1;
    //1.G(N)从2开始计算
    for(int i=2; i<=n; ++i) {
    //2. 1~N 中间元素j作为root的笛卡尔积
    	for(int j=1; j<=i; ++j) {
    		G[i] += G[j-1] * G[i-j];
    	}
    }

    return G[n];
}
