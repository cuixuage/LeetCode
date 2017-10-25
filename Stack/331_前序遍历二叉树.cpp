/*
����һ���ַ��� ����ǰ�������֤���Ƿ��ܹ���������   ��->ǰ->��
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;
using std::stringstream;

//�и��ַ��� stringstream+getline
vector<string> splitElement(string preorder){
    stringstream ss(preorder);
    string temp;
    vector<string> res;
    while(getline(ss,temp,',')){
        res.push_back(temp);
    }
    return res;
}
//�ж� ǰ�������ܷ񹹽�������
//ǰ�� stringǰ���������е�Ҷ�ӽڵ㶼�ǰ��� # ռ��  ����������ʼ��������
/*
��������Ԥ�������ַ���ʱ������ÿ���ַ���

���1���㿴��һ������c����ζ���㿪ʼ��չһ����cΪ����������������Ƶ���ջ

���2.1���㿴��һ�������������Ķ�ջ��һ�����֣���֪������һ����յĺ��ӣ�������Ϊ��һ�����Ľڵ�k�ı�ǣ�֪��������ȷ�ĺ��ӡ�

���2.2���㿴�������������Ķ�ջ�ǣ�����֪������Ϊ�������Ϊһ���յ�С����������ȡ��������������������磬����t�������ȴ���ȡ�������������ջ�Ƿ񣣻�һ�����֣�

----���һ�����֣�˵�㣬��֪����ո�ȡ����һ����u�ĺ��ӵĽڵ�t������Ҫ�ڶ�ջ�������£���ǡ�������һ���ڵ�֪������һ����ȷ�ĺ��ӡ�

----���һ��������֪����ո�ȡ����һ���������ĸ�t������ұߺ��ӡ����������ȡ�������������������Ǽ����ġ�
*/
bool isValidSerialization(string preorder){
    if(preorder == "") return false;
    stack<string> tree;
    vector<string> element = splitElement(preorder);
    for(unsigned i=0;i<element.size();i++){
        string curr = element.at(i);
        while(curr=="#" && !tree.empty() && tree.top()=="#"){
            tree.pop();
            if(tree.empty()) return false;
            tree.pop();
        }
        tree.push(curr);
    }
    return tree.size()==1 && tree.top()=="#" ? true:false;
}

//����2: ����  postorder(����������֤�������string��ת)
/*
����һ���ڵ㵽��ʱ������Ȼ�����diff1����Ϊ�ڵ��ṩ��һ��������
����ڵ㲻��null���������Ӳ���2����Ϊ���ṩ����������������л�����ȷ�ģ�diff��Ӧ���Ǹ��ģ����������ʱdiff��Ϊ��
*/
bool isValidSerialization_2(string preorder){
    vector<string> nodes = splitElement(preorder);
    int diff = 1;
    for (auto node : nodes) {
        if (--diff < 0) return false;
        if (node != "#") diff += 2;
    }
    return diff == 0? true:false;
}


//*****************************����
int main(int argc,char** argv){
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool res = isValidSerialization_2(preorder);
    cout<<res<<endl;

    return 0;
}
