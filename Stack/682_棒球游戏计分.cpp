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

/*  //����Ʒ���Ϸ
Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation:
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
*/
