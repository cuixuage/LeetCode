#include "func.h"

/*
sqrt(8)=2.8...=2   只保留整数
思路:
二分查找  mid^2 <= x < (mid+1)^2 return mid
*/

int sqrt(int x){
    if(x==0) return 0;
    int left=1,right=x/2+1;
    //循环
    while(true){
        int mid = left+(right-left)/2;
        //这里不能使用 mid*mid > x来判断。可能由于int溢出导致死循环
        if(mid > x/mid){
            right = mid-1;
        }else{
            if((mid+1) > x/(mid+1)) return mid;         //break 循环
            left = mid + 1;
        }
    }
}
