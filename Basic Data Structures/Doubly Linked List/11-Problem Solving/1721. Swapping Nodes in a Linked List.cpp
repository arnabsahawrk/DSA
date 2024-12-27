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

        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }
        ListNode *saveA = temp;

        count -= k;
        temp = head;
        for (int i = 1; i <= count; i++)
        {
            temp = temp->next;
        }
        ListNode *saveB = temp;

        swap(saveA->val, saveB->val);

        return head;
    }
};