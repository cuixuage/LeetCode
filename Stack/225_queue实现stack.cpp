class MyStack {
public:
 MyStack(){
   }
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){   //执行 size-2次 将最新加入元素前面的element全部拍向当前元素的后面
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	int pop() {
		int res=que.front();
		que.pop();
		return res;
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};

