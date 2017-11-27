#include "func.h"
/*read write两个pointer
只有当read==chars.length()-1  || read！=read+1 时
ans++
再把 amount转化为string 最终加上其长度
*/
//***************思路一定要清楚
int compress(vector<char>& chars){
    int start=0;
    for(int end=0,count=0;end<chars.size();end++){
        count++;
        if(end==chars.size()-1 || chars[end]!=chars[end+1]){
            chars[start]=chars[end];
            start++;
            if(count!=1){
                stringstream ss;
                ss<<count;
                string temp = ss.str();
                for(auto i : temp){
                    chars[start] = i;
                    start++;
                }
            }
            count =0;
        }
    }
    return start;
}

//error  错误 思路不清
//int compress(vector<char>& chars) {
//    char temp = chars[0];
//    int ans=0;
//    int amount=0;
//    for(auto c : chars){
//        if(c==temp)
//            amount ++;
//        else if(amount>1){
//            while(amount!=0){
//                ans += 1;
//                amount /=10;
//            }
//            ans +=1;
//        }
//        else
//            ans +=1;
//        temp = c;
//    }
//    while(amount!=0){
//        ans += 1;
//        amount /=10;
//    }
//    return ans;
//}

int main(){
    vector<char> chars;
    chars.reserve(32);
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    int res = compress(chars);
    cout<<res<<endl;
    for(int i=0;i<res;i++)
        cout<<chars.at(i);
    return 0;
}
