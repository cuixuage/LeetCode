/*
升序的数组,按照某一个点进行旋转。寻找旋转点
时间复杂度: O(LogN)
[1,2,3,4,5] => [3,4,5,1,2] 旋转点3
[0,1,1,1,1] => [1,0,1,1,1](原数组index=3旋转) or [1,1,1,0,1] (原数组index=1旋转) 其旋转点为1


思路: 
旋转后的数组mid > start, 则旋转点在右侧
           mid < end, 则旋转点在左侧
            start == mid == end, 那么只能顺序遍历确定旋转点
while(a[start] >= a[end]){
    if(end - start == 1) return a[end];
    mid = (end+start)/2;
    if(a[start] == a[end] && a[start] == a[mid])  func(顺序遍历start,end之间元素)
    if(a[mid] >= a[start]) start = mid
    else if(a[mid] <= a[end]) end = mid
}


边界:
1. 第一个数字小于最后一个数字 = 没有旋转点
