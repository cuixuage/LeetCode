#include "func.h"

/*偶数排列在奇数的前面
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/
//快速排序的变型
//Accept 一次过
vector<int> sortArrayByParity(vector<int>& A) {
    if(A.size()==0 || A.size()==1) return A;

    int low=0,high=A.size()-1;
    while(low < high){
        while(low<high && A[low]%2==0) low++;
        while(low<high && A[high]%2==1) high--;
        std::swap(A[low],A[high]);
    }
    return A;
}
