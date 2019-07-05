#include "func.h"
//二分查找 + quicksort
//˼·1 ���ֲ���+partition
//��λ�� n/2��Ȼ�����ڳ��ִ�������һ�������
int partitionArray(vector<int>& nums,int low,int high){
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
int majorityElement(vector<int>& nums){
    int length=nums.size();
    //���ֲ��� ÿ�η�ұ��λ���Ƿ����n/2
    int middle = length/2;
    int low=0;
    int high=length-1;
    int index = partitionArray(nums,low,high);      //��ұ����Ԫ������λ��
    while(index!=middle){               //middle����仯 ֱ�����break
        if(index>middle){
            high = index-1;
            index= partitionArray(nums,low,high);
        }
        else{
            low=index+1;
            index= partitionArray(nums,low,high);
        }
    }
    return nums[middle];                //��λ��middleλ��Ԫ���ѱ�ȷ��
}


//˼·2 ���ı�ԭ������˳��
//˼��:����ÿһ��Ԫ�أ������resultֵ��ͬ�����++.����--���������==0 ����result
int majorityElement_2(vector<int>& nums)
{
    int result=0;
    int counts=0;
    for(int i:nums){
        if(counts==0){           //result���ִ���������Ϊ0 ��A[i]��Ԫ����Ϊresult
            result=i;
            counts=1;
        }
        else if(i==result)
            counts++;           //��result���ִ���++
        else
            counts--;           //��ǰԪ�غ�result��ͬ
    }
    return result;
}