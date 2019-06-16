//一次AC  如果是零 重复两遍

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int length = arr.size();
        if(length <= 1) return;
        
        vector<int> tmp(length,0);
        int j = 0;
        for(int i=0;i<length;){
            if(arr[j] == 0){
                i += 2;
                j += 1;
            } 
            else{
                tmp[i] = arr[j];
                i += 1;
                j += 1;
            }
        }
        arr = tmp;
    }
};