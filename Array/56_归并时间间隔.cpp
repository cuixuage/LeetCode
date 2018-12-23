/*
collection of intervals to merge
思路:
1.按照start时间排序
2.不断将interval和vector<int>.back 作比较
如果新的intervel.start 小于 back.end ,则归并。
否则vector.push_back(intervel)
*/
private:
    //类的内部定义 compare函数需要static
    static bool cmp(const Interval& a, const Interval& b){return a.start < b.start;}
public:
    vector<Interval> merge(vector<Interval>& ins){
        if(ins.empty()) return vector<Interval>();
        vector<Interval> res;
        std::sort(ins.begin(),ins.end(),cmp);
        res.push_back(ins[0]);
        
        for(Interval i:ins){
            if(res.back().end < i.start)
                res.push_back(i);
            else
                res.back().end = std::max(res.back().end, i.end);
        }
        return res;
    }
