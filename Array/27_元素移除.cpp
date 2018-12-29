/*
给定的元素集合将target值移到末尾
*/

//一次AC
int removeElement(vector<int>& nums, int val) {
    //额外的指针 p
    int p=0;
    for(int i=0;i<(int)nums.size();i++){
        nums[p] = nums[i];
        if(nums[i]!=val){
            p++;
        }
    }
    //前p个元素就删除了val值的数组
    return p;
}

//思路2
//快排的变型  等于val移动到末尾
int removeElement(vector<int>& nums, int val) {
    int p = 0;
    int q = nums.size() - 1;
    while( p <= q )
    {
        while(nums[p]!=val&&(p<=q)) p++;
        while(nums[q]==val&&(p<=q)) q--;
        if(p<q) swap(nums[p],nums[q]);
    }
    return p; 
}
