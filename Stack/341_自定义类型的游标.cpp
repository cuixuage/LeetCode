/*

stack实现自定义类型的iterator效果 将list按照int形式输出

对于某个类 使用游标指向其vector的元素;其中元素的类型是int/list 使用iterator方式输出
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();

Example 1:
Given the list [[1,1],2,[1,1]]   （传递的vector是——[1,1] 2 [1,1]）
output:[1,1,2,1,1]
Example 2:
Given the list [1,[4,[6]]],
output:[1,4,6].

解决方法:
将vector内容倒序保存到stack中;
在hasNext()函数中，取stack.top()如果它是一个整数，我们将返回true并弹出元素。
否则作为一个list需要将其再次分解_getlist()_倒序加入stack中
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
    //初始化
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

    bool hasNext()   //注意判断next是Int / list
    {
        while(!resultStack.empty()) //********************这里必须是while循环  否则list分解后继续向下执行导致stack中仍有数据却return false
        {
            if(resultStack.top().isInteger())        //top元素是int
            {
                //resultStack.pop();         //这里不能执行pop()
                return true;
            }
            else    //top元素是list
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

//  for(int i=listInt.size()-1; i>=0; i--)   这里i不能是auto类型 vector[auto]是错误的
