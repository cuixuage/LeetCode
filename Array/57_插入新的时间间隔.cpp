/*类似于56题 归并时间间隔
本题是归并间隔  要求: 插入一个新的间隔,合并原来的间隔(可能会合并多个)
思路:
1.跳过 origin.end<new.start 和 origin.start > new.end的orign中元素
2.在这之间( new,start>=end && new.end>=origin.start)的internel全是可以被合并的
3.合并时 只需找出最小的start 和 最大的end即可
*/

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    vector<Interval> res;
    int index=0;
    //跳过前一部分
    while(index<intervals.size()&&intervals[index].end < newInterval.start){
        res.push_back(intervals[index]);
        index++;
    }
    //合并若干个interval 到一个new interval中
    while(index<intervals.size()&&intervals[index].start <= newInterval.end){
        newInterval.start = min(newInterval.start,intervals[index].start);
        newInterval.end = max(newInterval.end,intervals[index].end);
        index++;
    }
    res.push_back(newInterval);
    //跳过后一部分
    while(index < intervals.size())
        res.push_back(intervals[index++]);
    return res;
}
