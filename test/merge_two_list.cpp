// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

// 示例 1：


// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
// 示例 2：

// 输入：l1 = [], l2 = []
// 输出：[]

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(int argc, char const *argv[])
{
    // l1 = [1,2,4], l2 = [1,3,4]
    ListNode *l1,*l2,*h1,*h2;
    h1=l1=(ListNode *)malloc(sizeof(ListNode));
    h2=l2=(ListNode *)malloc(sizeof(ListNode));
    vector<int> a1={1,2,4},a2={1,3,4};
    for (int i = 0; i < a1.size()-1; i++)
    {
        l1->val=a1[i];
        l1->next=(ListNode *)malloc(sizeof(ListNode));
        l1=l1->next;
    }
    l1->val=a1[a1.size()-1];
    l1->next=nullptr;

    for (int i = 0; i < a2.size()-1; i++)
    {
        l2->val=a2[i];
        l2->next=(ListNode *)malloc(sizeof(ListNode));
        l2=l2->next;
    }
    l2->val=a2[a2.size()-1];
    l2->next=nullptr;

    ListNode *l3=(ListNode *)malloc(sizeof(ListNode));
    ListNode *h3=l3;
    while (h1&&h2)
    {
        if (h1->val<h2->val)
        {
            l3->next=h1;
            h1=h1->next;
        }
        else{
            l3->next=h2;
            h2=h2->next;
        }
        l3=l3->next;
    }
    if (h1)
    {
        l3->next=h1;
    }
    if (h2)
    {
        l3->next=h2;
    }
    h3=h3->next;
    while (h3)
    {
        cout<<h3->val;
        h3=h3->next;
    }
    
    return 0;
}
