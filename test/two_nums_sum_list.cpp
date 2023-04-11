// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.

#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=nullptr,*tail=nullptr;
        int n1,n2;
        int carry=0,sum=0;
        while (l1||l2)
        {
            n1=l1?l1->val:0;
            n2=l2?l2->val:0;
            sum = (n1+n2+carry)%10;
            carry = (n1+n2+carry)/10;
            if(!head){
                head=tail=(ListNode*)malloc(sizeof(ListNode));
                tail->val=sum;
                tail->next=nullptr;
            }else
            {
                tail->next=(ListNode*)malloc(sizeof(ListNode));
                tail=tail->next;
                tail->val=sum;
                tail->next=nullptr;
            }
            if (l1)
            {
                l1=l1->next;
            }
            if (l2)
            {
                l2=l2->next;
            }
            
        }

        if (carry>0)
        {
           tail->next=(ListNode*)malloc(sizeof(ListNode));
           tail=tail->next;
           tail->val=carry;
           tail->next=nullptr;
        }
        
        return head;
        // ListNode *res = (ListNode*)malloc(sizeof(ListNode));
        // // res->next=nullptr;
        // ListNode *cur =res;
        

        // while (l1!=nullptr)
        // {
        //     ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        //     p->val=l1->val+l2->val;
        //     p->next=nullptr;
        //     cur->next=p;
        //     l1=l1->next;
        //     l2=l2->next;
        //     cur=cur->next;
        // }
        
        // return res->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *l1=new ListNode(2);
    // ListNode *cur = (ListNode*) malloc(sizeof(ListNode));
    l1->next=new ListNode(4);
    // cur->next=l1->next;
    l1->next->next=new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    ListNode *res = s.addTwoNumbers(l1,l2);
    while (res!=nullptr)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    
    return 0;
}
