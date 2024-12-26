// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *fast = head, *slow = head;

        while (n--)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
        {
            ListNode *deleteNode = head;
            head = head->next;
            delete deleteNode;

            return head;
        }

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return head;
    }
};