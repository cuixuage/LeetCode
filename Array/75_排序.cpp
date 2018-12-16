/*
0,1,2分别代表三种颜色 使得颜色相同的相邻
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/*
思路1:  quicksort
思路2: 统计0,1,2分别出现的次数 重新覆盖掉原数组
思路3: 三路快排的变型？？
*/
void sortColors(vector<int>& nums) {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    for(int tmp:nums){
        if(tmp==0) num1++;
        else if(tmp==1) num2++;
        else num3++;
    }
    for(int i=0;i<nums.size();i++){
        if(i<num1) nums[i]=0;
        else if(i<num1+num2) nums[i]=1;
        else nums[i]=2;
    }
}
