//给定数组 寻找到其中丢失的元素
//Input: [9,6,4,2,3,5,7,0,1]
//Output: 8
/*
思路1: 最直观的思路是对数据进行排序，然后依次扫描，便能找出漏掉的数字，但是基于比较的排序算法的时间复杂度至少是nlog(n)
思路2: 可行的具有线性时间复杂度的算法是求和。对0到n求和，然后对给出的数组求和，二者之差即为漏掉的数字
思路3: 首先将0到n这些数进行异或运算，然后对输入的数组进行异或运算，最后将两个结果进行异或运算，结果便是漏掉的数字，因为其他数字在两个数组中都是成对出现的，异或运算会得到0
*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int missingNumber(vector<int>& nums)
{
    int x = 0;
    for (int i = 0; i <= nums.size(); i++) x ^= i;
    for (auto n : nums) x ^= n;
    return x;
}

int main(int argc,char** argv){
    vector<int> test{9,6,4,2,3,5,7,0,1};
    cout << missingNumber(test)<<endl;
    return 0;
}
