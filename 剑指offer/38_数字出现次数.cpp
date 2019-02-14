/*
已排序的数组中 某个数字的出现次数
思路2:
核心idea: 二分查找分别确定第一个和最后一个的出现位置,再相减
时间O(logN)
1.寻找k值第一次出现的位置
2.K值最后一次出现的位置
*/

#include "func.h"

class solution{
public:
    int GetNumberOfK(vector<int>& data, int k){
        if(data.size()==0) return 0;
        int first = getFirst(data,k);
        int last = getLast(data,k);
        //K值出现0次
        if(first==-1 && last==-1) 
            return 0;
        else 
         return  last-first+1;    
    }
private:
    //不存在K值 返回-1
    int getFirst(vector<int>& data,int k){
        int low = 0;
        int high = data.size()-1;
        while(low<high){
            int mid = (high-low)/2+low;
            if(data[mid] > k)
                high = mid-1;
            else if(data[mid] < k)
                low = mid+1;
            else{
                //1.  寻找到K值元素 再判断是否为第一个
                if((mid>0 && data[mid-1]!=k) || mid==0) return mid;
                else high = mid-1;
            }
        }
        if(data[low]==k) return low;
        return -1;
    }

    //不存在K值 返回-1
    int getLast(vector<int>& data,int k){
        int low = 0;
        int high = data.size()-1;
        while(low<high){
            int mid = (high-low)/2+low;
            if(data[mid] > k)
                high = mid-1;
            else if(data[mid] < k)
                low = mid+1;
            else{
                //1.  寻找到K值元素 再判断是否为最后一个
                if((mid<(int)data.size()-1 && data[mid+1]!=k) || mid==(int)data.size()-1) return mid;
                else low = mid+1;
            }
        }
        if(data[low]==k) return low;
        return -1;
    }
}