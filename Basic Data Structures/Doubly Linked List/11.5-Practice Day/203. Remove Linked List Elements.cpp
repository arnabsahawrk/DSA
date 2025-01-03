// https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }

        while (head != nullptr && head->val == val)
        {
            ListNode *deleteNode = head;
            head = head->next;
            delete deleteNode;
        }

        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp != nullptr)
        {
            if (temp->val == val)
            {
                ListNode *deleteNode = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete deleteNode;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};