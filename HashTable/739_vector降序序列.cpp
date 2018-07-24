/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

对于vector中每个元素  后续大于它的元素的距离

思路:
1. O(n^2)
2.hash O(N)
*/

//思想:相反的顺序寻找
vector<int> dailyTem(vector<int>& temperatures){
    vector<int> ans(temperatures.size(),0);
    stack<int> mystack;
    //stack保存 序号i(包含)之前的最长连续降序序列
    for(int i=0;i<temperatures.size();i++){
        //直到stack中没有比i更小的元素
        while(!mystack.empty() && temperatures[i] > temperatures[mystack.top()]){
                int idx = mystack.top();
                mystack.pop();
                ans[idx] = i - idx;
              }
        mystack.push(i);
    }
    return ans;
}
