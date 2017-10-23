/*

stackʵ���Զ������͵�iteratorЧ�� ��list����int��ʽ���

����ĳ���� ʹ���α�ָ����vector��Ԫ��;����Ԫ�ص�������int/list ʹ��iterator��ʽ���
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();

Example 1:
Given the list [[1,1],2,[1,1]]   �����ݵ�vector�ǡ���[1,1] 2 [1,1]��
output:[1,1,2,1,1]
Example 2:
Given the list [1,[4,[6]]],
output:[1,4,6].

�������:
��vector���ݵ��򱣴浽stack��;
��hasNext()�����У�ȡstack.top()�������һ�����������ǽ�����true������Ԫ�ء�
������Ϊһ��list��Ҫ�����ٴηֽ�_getlist()_�������stack��
*/
#include<iostream>
#include<vector>
#include<stack>
using std::cout;
using std::endl;
using std::vector;
using std::stack;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator
{
public:
    stack<NestedInteger> resultStack;
    //��ʼ��
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for(auto i=nestedList.rbegin(); i!=nestedList.rend(); i++)
        {
            resultStack.push(*i);
        }
    }

    int next()
    {
        int k = resultStack.top().getInteger();
        resultStack.pop();
        return k;

    }

    bool hasNext()   //ע���ж�next��Int / list
    {
        while(!resultStack.empty()) //********************���������whileѭ��  ����list�ֽ���������ִ�е���stack����������ȴreturn false
        {
            if(resultStack.top().isInteger())        //topԪ����int
            {
                //resultStack.pop();         //���ﲻ��ִ��pop()
                return true;
            }
            else    //topԪ����list
            {
                vector<NestedInteger> listInt = resultStack.top().getList();
                resultStack.pop();
                for(int i=listInt.size()-1; i>=0; i--)
                {
                    resultStack.push(listInt[i]);
                }
            }
        }
        return false;
    }
};

//  for(int i=listInt.size()-1; i>=0; i--)   ����i������auto���� vector[auto]�Ǵ����
