// https://leetcode.com/problems/odd-even-linked-list/

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

/*
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        vector<int> v;

        ListNode *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            v.push_back(temp->val);

        temp = head->next;
        while (temp != nullptr && temp->next != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            v.push_back(temp->val);

        temp = head;
        for (auto data : v)
        {
            temp->val = data;
            temp = temp->next;
        }

        return head;
    }
};
*/

// Optimized Way
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *odd = head, *even = head->next, *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
