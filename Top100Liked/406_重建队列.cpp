 /*
 pair<h,k> 其中h代表身高,k代表在最终队列里站在此人前面,身高大于此人的数目
 思路:
 选择身高最大的组,按照其second升序排列。再排序下一组并插入。
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]
思考:
插入时候如何得到其插入位置？
 */

 /*
 一般重载operator()作为compare的重载函数
 1.默认
 传入参数顺序a,b. return true代表顺序不变 否则交换
 2.priority
 里面建立堆还需要交换,所以true的含义相反
 */

 #include "func.h"
class solution{
private:
    struct Cmp{
        bool operator()(pair<int,int> const &a, pair<int,int> const &b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        }
        //priority_queue first大的值在前面
    };  //note 分号

public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
        for(auto p : people)
            pq.push(p);
        
        vector<pair<int,int>> ans;
        while(!pq.empty()){
            ans.insert(ans.begin()+pq.top().second, pq.top());
            pq.pop();
        }
        return ans;
    }
}

