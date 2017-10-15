#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<string.h>
#include <cstdlib>      //不加这个头文件  stoi atoi都无法使用  震惊~！！  此4.8版本GCC在Codeblocks bug在于stoi无法使用
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;

int calPoints(vector<string>& ops) {
    stack<int> score;
    for(auto op:ops){
        if(!score.empty() && op == "+"){
            int f_top=score.top();
            score.pop();
            int s_top=score.top();
            score.push(f_top);
            score.push(f_top+s_top);
        }
        else if(op=="C"){
            score.pop();
        }
        else if(op=="D"){
            score.push(2*score.top());
        }
        else{
            int int_num = std::atoi(op.c_str());//string转化为int数据
            score.push(int_num);
        }
    }
    int result=0;
    while(!score.empty()){
        result+=score.top();
        score.pop();
    }
    return result;
}


int main(int argc,char** argv){
    vector<string> ops(64);  //开辟64大小空间  或者善用预留reserve函数
    ops.push_back("10");
    ops.push_back("D");
    ops.push_back("C");
    cout<<calPoints(ops)<<endl;
    return 0;
}
/*/*****************Vector
每次重新分配，比如 4 -> 8的这个过程中（在此不考虑内存池优化的影响）：
先申请一个8的空间
将大小为4的这段内存复制到8的空间
将大小为4的这段空间释放掉

值得一提的是，在今天的CppJieba结巴分词性能优化中，在性能瓶颈的地方，简单的加了一行 reserve 语句，性能测试结果就提高了10%
*/
