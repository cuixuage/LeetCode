/*
��������[a,b,c,d] �������ŵ����ȼ�ʹ��Ԫ����� ��ֵ���
math: ����󼴳�����С b/c/d < b/(c/d)
*/

//**********int ��������ת��Ϊstring ʹ��stringstream

#include"func.h"
string optimalDivision(vector<int>& nums) {
    stringstream ss;
    string temp;
    if(nums.size()==1){
        ss<<nums[0];
        temp = ss.str();
        return temp;
    }
    if(nums.size()==2){
        ss<<nums[0];
        temp = ss.str();
        ss.str("");      //*************stringstream clear���� ss.clear()ֻ�������־λ
        ss<<nums[1];
        temp += "/"+ss.str();
        return temp;
    }
    ss<<nums[0];
    temp = ss.str() + "/"+"(";
    for(int i=1;i<nums.size()-1;i++){
        ss.str("");
        ss<<nums[i];
        temp += ss.str() +"/";
    }
    ss.str("");
    ss<<nums[nums.size()-1];
    temp += ss.str() + ")";
    return temp;
}

//************
int main(){
    vector<int> nums;
    nums.reserve(32);
    nums.push_back(1000);
    nums.push_back(100);
    nums.push_back(10);
    nums.push_back(2);
    cout<<optimalDivision(nums)<<endl;
    return 0;
}

//**********int ��������ת��Ϊstring ʹ��stringstream
