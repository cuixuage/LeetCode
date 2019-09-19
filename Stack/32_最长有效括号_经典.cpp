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

//思路3: O(N)space   O(N)time
//For example "( ) ( ( ) "would become "11011"  
public int longestValidParentheses(String s) {
    int res=0;
    int tep=0;
    Stack<Integer> s1=new Stack<>();
    int data[]=new int[s.length()];
    for(int i=0;i<s.length();i++){
        char c=s.charAt(i);
        if(c=='(') s1.push(i);
        else{
            if(!s1.empty()){        //将)和其对应的(位置标记为1
                data[i]=1;
                data[s1.pop()]=1;   
            }
        }
    }
    for(int i:data){
        if(i==1) tep++;
        else {res=Math.max(tep,res);tep=0;}
    }
    return Math.max(tep,res);
}


//思路2:   所有element都存储到stack中   只有匹配到的移出stack
int longestValidParentheses(string s){
    int n=s.size(),longest=0;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else{
            if(!st.empty()){
                if(s[st.top()]=='(') st.pop();
                else st.push(i);
            }
            else st.push(i);
        }
    }
    
    if(st.empty()) longest = n;
    else{
        int a=n,b=0;            //初始化a=n
        while(!st.empty()){
            b=st.top();
            st.pop();
            longest = std::max(longest,a-b-1);
            a = b;
        }
        //最前面一段的  比较
        longest = max(longest,a);
    }
    return longest;
}
