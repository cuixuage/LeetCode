/*��¥�� ���͵Ķ�̬�滮*/

#include"func.h"

//��ʱ
int climbStairs(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else return climbStairs(n-1)+climbStairs(n-2);
}

//�ռ任ʱ�䣿 ʹ��ѭ������ݹ�
int climbStairs2(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    //�� n>=3ʱ
    int dp[n+1];
    memset(dp,0,sizeof(int)*(n+1));
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];

}

int main()
{
    cout<<climbStairs2(2)<<endl;
    return 0;
}
