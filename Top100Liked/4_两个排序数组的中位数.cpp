#include "func.h"
/*
寻找两个已排序的数组的中位数
插入排序？
*/
//重新进行思考 
int getKth(vector<int> s,int m,vector<int> l,int n,int k){
    if(m > n)   return getKth(l,n,s,m,k);
    if(m == 0) return l[k-1];
    if(k == 1) return std::min(s[0],l[0]);
    int i = std::min(m,k/2);
    int j = std::min(n,k/2);
    if(s[i-1] > l[j-1])
        return getKth(s,m,vector<int>(l.begin()+j,l.end()),n-j,k-j);
    else
        return getKth(vector<int>(s.begin()+i,s.end()),m-i,l,n,k-i);
    return 0;

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int l = (m+n+1)/2;  //i.e. m+n是奇数时
    int r = (m+n+2)/2;
    return (getKth(nums1,m,nums2,n,l) + getKth(nums1,m,nums2,n,r))/2.0;
}