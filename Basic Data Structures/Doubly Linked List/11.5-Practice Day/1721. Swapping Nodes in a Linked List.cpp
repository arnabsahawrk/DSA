// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *ptr1 = head, *ptr2 = head, *kth = nullptr;

        while (--k)
        {
            ptr1 = ptr1->next;
        }

        kth = ptr1;
        ptr1 = ptr1->next;

        while (ptr1 != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        swap(ptr2->val, kth->val);
        return head;
    }
};