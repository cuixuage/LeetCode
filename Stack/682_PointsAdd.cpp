#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<string.h>
#include <cstdlib>      //�������ͷ�ļ�  stoi atoi���޷�ʹ��  ��~����  ��4.8�汾GCC��Codeblocks bug����stoi�޷�ʹ��
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
            int int_num = std::atoi(op.c_str());//stringת��Ϊint����
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
    vector<string> ops(64);  //����64��С�ռ�  ��������Ԥ��reserve����
    ops.push_back("10");
    ops.push_back("D");
    ops.push_back("C");
    cout<<calPoints(ops)<<endl;
    return 0;
}
/*/*****************Vector
ÿ�����·��䣬���� 4 -> 8����������У��ڴ˲������ڴ���Ż���Ӱ�죩��
������һ��8�Ŀռ�
����СΪ4������ڴ渴�Ƶ�8�Ŀռ�
����СΪ4����οռ��ͷŵ�

ֵ��һ����ǣ��ڽ����CppJieba��ͷִ������Ż��У�������ƿ���ĵط����򵥵ļ���һ�� reserve ��䣬���ܲ��Խ���������10%
*/
