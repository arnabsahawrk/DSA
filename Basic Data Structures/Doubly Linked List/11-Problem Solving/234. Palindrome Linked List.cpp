// https://leetcode.com/problems/palindrome-linked-list/

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
    void insert_at_tail(ListNode *&head, ListNode *&tail, int value)
    {
        ListNode *newNode = new ListNode(value);

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void recursiveReverse(ListNode *&head, ListNode *&tail, ListNode *temp)
    {
        if (temp->next == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }

        recursiveReverse(head, tail, temp->next);
        temp->next->next = temp;
        temp->next = nullptr;
        tail = temp;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        ListNode *temp = head;
        ListNode *newHead = nullptr, *newTail = nullptr;
        while (temp != nullptr)
        {
            insert_at_tail(newHead, newTail, temp->val);
            temp = temp->next;
        }

        recursiveReverse(newHead, newTail, newHead);

        temp = head;
        ListNode *temp2 = newHead;

        while (temp != nullptr && temp2 != nullptr)
        {
            if (temp->val != temp2->val)
            {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return true;
    }
};