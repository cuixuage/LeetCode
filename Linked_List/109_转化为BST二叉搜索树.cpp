/*�������������ת��ΪBST binary search tree ����������
    �ݹ鴦����������
*/

#include <stdio.h>
#include <iostream>
using std::endl;
using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
    TreeNode *sortedListToBST(ListNode *head){
        if(head==NULL) return NULL;
        return sortedListToBST(head,NULL);   //��������
    }
private:
    TreeNode *sortedListToBST(ListNode *head,ListNode *tail){
        if(head==tail) return NULL;
        if(head->next==tail){
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *slow = head,*fast=head;
        //Ѱ���м�λ�ý�� tail��β��ָ��
        while(fast!=tail && fast->next!= tail){   //ż��Ԫ��ʱslowָ����ε�һ��Ԫ��
        //while(fast->next!=tail && fast->next->next!= tail) Accepted ��˹���BSTҲ������
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head,slow);
        root->right = sortedListToBST(slow->next,tail);
        return root;
    }
};

int main(int argc,char** argv){

}
