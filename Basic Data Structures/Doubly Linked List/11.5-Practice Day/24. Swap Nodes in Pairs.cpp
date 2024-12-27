// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *point = dummyNode;

        while (point->next != nullptr && point->next->next != nullptr)
        {
            ListNode *swap1 = point->next;
            ListNode *swap2 = point->next->next;

            swap1->next = swap2->next;
            swap2->next = swap1;

            point->next = swap2;
            point = swap1;
        }

        return dummyNode->next;
    }
};