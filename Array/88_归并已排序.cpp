//两个已排序 升序数组的归并
//我们倒找最大即可  最终结果自然即为升序
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int k = m+n-1;
    m = m-1;
    n = n-1;
    while(m>=0 && n>=0){
        if(nums1[m] > nums2[n])
            nums1[k--] = nums1[m--];
        //包含 nums1[]==nums2[]元素情况
        else
            nums1[k--] = nums2[n--];
    }
    //如果m!=0 因为已经在有序nums1上  所以不用操作;
    //如果n!=0 需要移动到nums1上面
    //注意不能写成  n!=0  因为n代表序号
    while(n>=0)
        nums1[k--]  = nums2[n--];       //此时n==k
}


//使用辅助数组  memory limit exceed
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans(m+n,0);
    while(m!=0 || n!=0){
        if(m==0 && n==0) break;
        else if(m==0 && n!=0) for(int i=n-1;i>=0;i--) {ans.push_back(nums2[n]); break;}
        else if(m!=0 && n==0) for(int i=m-1;i>=0;i--) {ans.push_back(nums1[m]); break;}
        else{
            if(nums1[m]>nums2[n]){
                ans.push_back(nums1[m]);
                m--;
            }    
            else if(nums1[m] < nums2[n]){
                ans.push_back(nums2[n]);
                n--;
            }    
            else{
                ans.push_back(nums1[m]);
                ans.push_back(nums2[n]);
                m--;n--;            
            } 
        }
    }
    for(int i=0;i<ans.size();i++)
        nums1[i] = ans[i];
    
}
