/*
爬楼梯 典型的动态规划
思路:
第i层的方式情况总数 = i-1层情况(一步上楼梯) + i-2层情况(两步上楼梯)
*/

#include"func.h"

//直接递归 超时
int climbStairs(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else return climbStairs(n-1)+climbStairs(n-2);
}

//空间换时间--使用循环替代递归
//2th submit
int climbStairs3(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    int dp[n+1]={0};
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[n] = dp[i-1]+dp[i-2];        
    return dp[n];
}

int main()
{
    cout<<climbStairs2(2)<<endl;
    return 0;
}
