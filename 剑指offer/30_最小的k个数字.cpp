#include"func.h"
//二分查找 + quicksort
//kλ�õ���඼��С���������� ����༴Ϊ��ȷ�� O(n)
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
void getLeastNumbers(int* input,int n,int* output,int k){//ԭ����input,�𰸱�����output
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
    }//k-1���λ������������ݼ���Сk��������(��һ���������)
    for(int i=0;i<k;i++)
        output[i]=input[i];
}

//˼·2 �������ݡ���������
//��С��k�����֣�ֻ����k��Ԫ�ص����ѡ���ֻ�е�ǰԪ��С�ڶѶ�Ԫ��ʱ:�滻top���ع���
//���յõ�����Ԫ������Сk��  O(n*logk)
//����ʵ��: priority_queue<int> ���� multiset<int,greater<int>>  set\map�������keyֵ��������

void getLeastNumbers_2(const vector<int>& input,multiset<int,std::greater<int>>& output,int k){
    output.clear();
    for(int tmp:input){
        if(output.size()<k)
            output.insert(tmp);

        else if(tmp < *(output.begin()) ){        //��ǰԪ��С��multiset�Ķ�Ԫ��
            output.erase(output.begin());
            output.insert(tmp);
        }
    }
}
