/*
寻找给定字符串中 最长的连续的 有效括号
*/

//动态规划的递推公式  http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
//ERROR "()(()" 无法通过  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
int longestValidParentheses(string s){
    std::stack<char> myStack;
    vector<int> ans(s.length(),0);
    if(s[0] == '(') myStack.push('(');
    int maxCount = 0;
    
    for(int i=1;i<s.size();++i){
        if(s[i] == '('){
            myStack.push('(');
        }else{
            if(!myStack.empty()){
                myStack.pop();
                ans[i] = ans[i-1] + 2;
            }else{ ans[i] = 0; }
        }
    }
    for(auto i : ans){
        if(i > maxCount) maxCount=i;
    }
    return maxCount;
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
