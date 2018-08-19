#include "func.h"
//Accept
//O(N*N)
vector<int> fairCandySwap(vector<int>& A, vector<int>& B){
    vector<int> res;
    long sumA =0;
    long sumB = 0;
    for(auto i:A){
        sumA += i;
    }
    for(auto i:B){
        sumB +=i;
    }
    //cout<<sumA<<" "<<sumB<<endl;
    if(sumA==sumB) return res;
    int mid = (int)(sumA+sumB)/2;
    int diff = std::abs(mid-sumA);
    //cout<<mid<<" "<<diff<<endl;
    if(sumA>sumB){
        for(auto i:A){
            for(auto j:B){
                if(i-j==diff){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }else{
       for(auto i:B){
            for(auto j:A){
                if(i-j==diff){
                    //◊¢“‚A,BŒª÷√
                    res.push_back(j);
                    res.push_back(i);
                    return res;
                }
            }
        }
    }
    return res;
}
/*
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    vector<int> B;
    B.push_back(2);
    B.push_back(2);
    vector<int> res = fairCandySwap(A,B);
    for (auto i:res)
        cout<<i<<" "<<endl;
}
*/
