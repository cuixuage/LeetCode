#include"func.h"
//思路1 二分查找+partition(修改了原数组)
//k位置的左侧都是小于它的数字 其左侧即为正确答案 O(n)
int partitionArray(int* nums,int low,int high){
//int partitionArray(vector<int>& nums,int low,int high){
    int tmp=low;
    int pivot=nums[low];
    while(low<high){
        while(low<high&&nums[high]>=pivot) --high;
        while(low<high&&nums[low]<=pivot)  ++low;
        std::swap(nums[low],nums[high]);
    }
    std::swap(nums[low],nums[tmp]);
    return low;
}
void getLeastNumbers(int* input,int n,int* output,int k){//原数组input,答案保存在output
    if(output==NULL || input==NULL) return;
    int low=0;
    int high=n-1;
    int index=partitionArray(input,low,high);
    while(index!=k-1){
        if(index>k-1){
            high=index-1;
            index=partitionArray(input,low,high);
        }else{
            low=index+1;
            index=partitionArray(input,low,high);
        }
    }//k-1序号位置左侧所有数据即最小k个数字了(不一定是排序的)
    for(int i=0;i<k;i++)
        output[i]=input[i];
}

//思路2 海量数据——堆排序
//最小的k个数字：只保存k个元素的最大堆——只有当前元素小于堆顶元素时:替换top并重构堆
//最终得到所有元素中最小k个  O(n*logk)
//最大堆实现: priority_queue<int> 或者 multiset<int,greater<int>>  set\map本身会把key值升序排列

void getLeastNumbers_2(const vector<int>& input,multiset<int,std::greater<int>>& output,int k){
    output.clear();
    for(int tmp:input){
        if(output.size()<k)
            output.insert(tmp);

        else if(tmp < *(output.begin()) ){        //当前元素小于multiset的顶元素
            output.erase(output.begin());
            output.insert(tmp);
        }
    }
}
