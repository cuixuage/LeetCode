/*
使用给定数字的digit  找到所有大于当前整数的最小那一个  不存在则输出-1
例如: 534976 => 536 479
*/
//思考: 只有当数字中所有digit降序排列时返回-1
/*
I）从最右边的数字遍历给定的数字，继续遍历，直到找到一个小于先前遍历的数字的数字。例如，如果输入号码是“534976”，我们停在4，因为4小于下一个数字9.如果我们没有找到这样一个数字，那么输出是“不可能的”。

II）现在在上面找到的数字'd'的右侧搜索大于'd'的最小数字。对于“53 4 976”，4的右边包含“976”。大于4的最小数字是6。

III）交换上面找到的两位数字，我们在上面的例子中得到53 6 97 4。

四）现在排序从“d”旁边的位置到数字的结尾的所有数字。我们在排序后得到的数字就是输出。对于上面的例子，我们用粗体536 974对数字进行排序。我们得到“536 479 ”，这是输入534976的下一个更大的数字
*/

//有贪心的思想  从右到左寻找第一个降序的元素即为被交换的元素(与其后面所有元素中最小的那一个)
#include"func.h"

int nextGreatElement(int n){
    stringstream ss;
    ss<<n;
    string str = ss.str();
    int i,j;
    //i记录从右到左第一个递减元素的需要被交换的元素 j记录i位置后面最小元素的位置
    //思考: 倒序寻找第一个降序的数字  而不是正序寻找第一个递增(无法保证结果是最小)
    for(i=str.length()-1;i>0;i--)
        if(str[i-1] < str[i]) break;
    //从右到左递增序列 i==1不存在 i=0 break
    if(i==0) return -1;

    int x=str[i-1];   //[i-1] < [i]
    int smallest=i;
    for(j=i+1;j<str.length();j++)
    //*********两个条件必不可少  后面元素大于x 且是当中最小最右侧的那一个
        if(str[j] > x && str[j] <= str[smallest])
            smallest = j;
    //**III swap
    std::swap(str[i-1],str[smallest]);

    //**IV  sort after(i-1)
    std::sort(str.begin()+i,str.end());
    long val = std::atol(str.c_str());

    return (val <= INT_MAX) ? (int) val : -1;;
}
//*************************
int main(){
    int a = 534976;
    cout<<nextGreatElement(a)<<endl;
    return 0;
}

/*
1.int 2 string (use stringstream)
    stringstream ss;
    ss<<n;
    string str ;  //str=ss.str();
    ss>>str;

2.sort + compare
    // sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {
            return a < b;
        }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    for (auto a : s) {
        std::cout << a << " ";
    }
*/
