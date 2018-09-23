#include "func.h"

//一次AC
//我的greedy思想
//1.排序数组 计算首元素的上界
//2. 目的相邻元素差值最小。  pre元素总是固定的  current元素add[-x,x],从集合中选择和pre元素差值最小的值
//3. tmp也是有序的
/*
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]
*/

int smallestRangeI(vector<int>& A,int k){
    vector<int> tmp = A;
    int ans = 0;
    if(A.size()==0 || A.size()==1) return 0;
    else if(A.size()==2) return (A[1]-A[0]>2*k) ? A[1]-A[0]-2*k : 0;
    else{
        std::sort(A.begin(),A.end());
        tmp[0] = A[0]+k;
        for(int i=1;i<A.size();i++){
            //current下界小于等于pre上界
            if(A[i]-k <= tmp[i-1])
                tmp[i] = tmp[i-1];
            //current下界大于pre上界
            else{
                ans += A[i]-k-tmp[i-1];
                tmp[i] = A[i]-k;
            }
        }
    }
    //返回tmp中的最大值  最小值差值
    return tmp[tmp.size()-1]-tmp[0];
//    return ans;
}
