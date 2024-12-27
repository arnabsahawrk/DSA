// https://leetcode.com/problems/reverse-linked-list/
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
    void recursiveReverse(ListNode *&head, ListNode *temp)
    {
        if (temp->next == nullptr)
        {
            head = temp;
            return;
        }

        recursiveReverse(head, temp->next);
        temp->next->next = temp;
        temp->next = nullptr;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        recursiveReverse(head, head);

        return head;
    }
};