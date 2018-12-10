//升序排列的数组  转换为平衡二叉树

//思路:   找mid作为每次遍历的root

//方法2   注意范围  我更喜欢这样
private:
TreeNode* sortedArrayToBST2(vector<int>& nums,int start, int end){
    //小于等于
    if(end < start) return NULL;
    //避免超出int范围
    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    //注意left right 的范围
    root->left = sortedArrayToBST2(nums,start,mid-1);
    root->right = sortedArrayToBST2(nums,mid+1,end);
    return root;
}
public:
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty()) return NULL;
    //注意末尾的序号
    return sortedArrayToBST2(nums,0,nums.size()-1);
}





class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        return sortedArrayToBST(nums,0,nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums,int start, int end){
        //小于等于 
        if(end <= start) return NULL;
        //避免超出int范围
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        //注意left right 的范围
        //left不能是mid-1  因为可能变成负数
        root->left = sortedArrayToBST(nums,start,mid);
        root->right = sortedArrayToBST(nums,mid+1,end);
        return root;
    }
};
