/*
给定数组array,滑动窗口的长度K值 寻找滑动窗口中最大值的数组
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
思路1:
窗口每次向右滑动时,遍历窗口内元素,选最大值  时间O(K*N)
思路2:
deque 保存[i-k+1,i]之间的"最有希望"的元素index

queue.front保存区间内最大值的index; 每次移动都会将cur_index放在deque恰当的位置
(即deque保存index的val是降序的)
*/
#include "func.h"
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        //1.
        if(!dq.empty() && dq.front()==i-k) 
            dq.pop_front();
        //2.
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        //3.
        dq.push_back(i);       
        //窗口向右滑动过程中,滑动窗口内的最大值(到当前元素为止的最大值)即为deque的头部元素
        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

/*
|||||||||||
front       back

dequeue的front   back区分好
元素都是在back位置加入

1.删除dequeue front元素(超出滑动窗口)
2.从back开始 删除小于cur-val的index
3.cur-val 加入dequeue.back
4.front 即为当前max-val
*/