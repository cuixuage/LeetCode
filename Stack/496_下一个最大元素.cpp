/*
����sum1������sum2���Ӽ������������о�û���ظ���Ԫ�ء�
����sum1��ÿһ��Ԫ����˵��sum2��Ӧsum1��ֵͬ��λ�õ� [��������е�Ԫ��] �Ƿ�ȵ�ǰֵ��val:-1

����������һ�����ٵ����к��һ�����������
����[5, 4, 3, 2, 1, 6]�����������6��������������ǰ�����ֵ���һ�������Ԫ��

����ʹ�ö�ջ������һ���ݼ��������У�ÿ�����ǿ���һ������x����stack.peek()���ǵ������е�Ԫ��С��x�����е�����Ԫ�أ����ǵ���һ�������Ԫ����x
����[9, 8, 7, 3, 2, 1, 6]
��ջ�����Ȱ���[9, 8, 7, 3, 2, 1]��Ȼ�����ǿ���6�ĸ��Ǵ���1���ǵ���1 2 3����һ�������Ԫ��Ӧ����6
*/
#include<iostream>
#include<stack>
#include<map>
#include<unordered_map>
#include<vector>
using std::cout;
using std::endl;
using std::stack;
using std::map;
using std::vector;
using std::unordered_map;    //map�ᰴ��key�Զ�����
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    unordered_map<int,int> maptable;    //������ڸ���ֵ��Ԫ��  ��������
    stack<int> numsVal;    //����(û�и���ֵԪ��)�ݼ�����

    for(auto val:nums){
        while(!numsVal.empty() && numsVal.top()<val){
            maptable[numsVal.top()]=val;      //��ЩԪ�صĺ����Ǵ��ڸ����VAL
            numsVal.pop();
        }
        numsVal.push(val);   //***********�ݼ�����
    }
    vector<int> answer;
    for(auto val:findNums){
                                    //count���ڷ���1 ����0
        if(maptable.count(val))     //find ����map������ maptable.find(val)!=maptable.end()
            answer.push_back(maptable[val]);

        else answer.push_back(-1);
    }
    return answer;
}

//**************************����
int main(int argc,char** argv){
    vector<int> findNums,Nums;
    Nums.push_back(1);
    Nums.push_back(3);
    Nums.push_back(4);
    Nums.push_back(2);
    findNums.push_back(4);
    findNums.push_back(1);
    findNums.push_back(2);

    vector<int> ans;
    ans.reserve(64);
    ans = nextGreaterElement(findNums,Nums);
    for(auto val:ans){
        cout<<val<<endl;
    }
    return 0;
}
