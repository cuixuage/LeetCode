#include "func.h"
/*
寻找两个已排序的数组的中位数
插入排序？

归并排序,寻找第K位置  = KlogN ?
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




//https://blog.csdn.net/hk2291976/article/details/51107778
//放弃了???
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)   //保证数组1一定最短
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
        while(lo <= hi)   //二分
        {
            c1 = (lo+hi)/2;  //c1是二分的结果
            c2 = m+n- c1;
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)
                hi = c1-1;
            else if(L2 > R1)
                lo = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }