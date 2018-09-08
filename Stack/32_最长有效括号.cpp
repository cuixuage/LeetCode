/*
寻找给定字符串中 最长的连续的 有效括号
*/


//ERROR "()(()" 无法通过
int longestValidParentheses(string s){
    std::stack<char> mystack;
    int count = 0;
    int max = 0;
    for(auto c:s){
        if(c=='(')
            mystack.push('(');
        else if(!mystack.empty() && c==')'){
            mystack.pop();
            count += 2;
            if(count > max) max = count;
        }else{    
            //mystack==0 && c==')'时  clear——count
            count = 0;
        }
    }
    return max;
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
            if(!s1.empty()){
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
