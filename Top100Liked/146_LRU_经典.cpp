/*
实现LRU cache  
思路:  hashtable+Bi-ListNode
1. 私有变量
cache = hastable<int,ListNode*>
head_node pointer                     //用于Bi-ListNode
tail_node pointer
count_num
capacity

2. 私有API
关于双向链表的接口
addNode(ListNode*)
removeNode(ListNode*)
moveNode2Head(ListNode*)
popTailNode(ListNode*)

3.公有接口
构造函数(init)
get(key)
put(key,val)
