//一遍AC
//假设没有重复元素

int search(vector<int>& nums, int target){
    //empty更快？ 而非使用len 
    if(nums.empty()) return -1;
    
    int start = nums.front();
    int end = nums.back();
    if(target < start && target > end)
        return -1;
    if(target <= end){
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == target)
                return i;
        }
    }else{
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target)
                return i;
        }
    }
    return -1;
}

//FIXME 旋转数组的二分查找=》最小元素的序号
//核心思想:  找到最小的元素的序号  然后再通过[0,root-1]和[root,n-1]两个区间去查找
int search(int A[], int n, int target) {
    int lo=0,hi=n-1;
    // find the index of the smallest value using binary search.
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(A[mid]>A[hi]) lo=mid+1;
        else hi=mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    int rot=lo;
    lo=0;hi=n-1;
    // The usual binary search and accounting for rotation.
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int realmid=(mid+rot)%n;
        if(A[realmid]==target)return realmid;
        if(A[realmid]<target)lo=mid+1;
        else hi=mid-1;
    }
    return -1;
