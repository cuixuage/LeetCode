/*
寻找给定字符串中 最长的连续的 有效括号
*/

//动态规划的递推公式  http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
//ERROR "()(()" 无法通过  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
// dp[i] = 0
// dp[i] = dp[i-1]+2  +  dp[i-dp[i]] (遇到")",当stack不为空时,以当前元素为止的有效括号长度=)

//思路1: stack存储"("的index

int longestValidParentheses(string s) {
    vector<int> stack;
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            stack.push_back(i);
        else {
            if (!stack.empty() && s[stack.back()] == '(') {
                stack.pop_back();
                int lastPos = -1;
                if (!stack.empty())
                    lastPos = stack.back();
                int curLen = i - lastPos;
                maxLen = (maxLen < curLen) ? curLen : maxLen;
            } else
                stack.push_back(i);     //stack为空时, ")"也是无效的index
        }
    }
    return maxLen;
}

//stack 存放括号的index  最终stack中保留的即为无效的括号