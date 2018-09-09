#include "func.h"

//实现迭代器
//为了避免空间太大  不能创建新的vector
//我选择一个标志记录next的位置

//一次Accept
class RLEIterator{
public:
    RLEIterator(vector<int> A) {
        tmp = A;
    }

    int next(int n) {
       int i=0;
        itera +=n;
        long long tmp_itera = itera;
       // cout<<"itera="<<itera<<endl;
        for(i=0;i<tmp.size();i+=2){
            tmp_itera -= tmp[i];
            if(tmp_itera <= 0)
                return tmp[i+1];
        }
        if(i==tmp.size())
            return -1;
    }
    long long get(){
        return itera;
    }
private:
long long itera=0;      //相当于用来记录上一次遍历到的位置
vector<int> tmp;
};

/*
int main(){
    vector<int> A = {3,8,0,9,2,5};
    RLEIterator* obj = new RLEIterator(A);
    int param1 = obj->next(2);
    cout<<param1<<endl;
    cout<<obj->get()<<endl;

    int param2 = obj->next(1);
    cout<<param2<<endl;
    cout<<obj->get()<<endl;

    int param3 = obj->next(1);
    cout<<param3<<endl;
    cout<<obj->get()<<endl;

    int param4 = obj->next(2);
    cout<<param4<<endl;
    cout<<obj->get()<<endl;
}
*/
