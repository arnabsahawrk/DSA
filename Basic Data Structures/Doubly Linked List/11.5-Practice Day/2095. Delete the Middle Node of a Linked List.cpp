// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=problem-list-v2&envId=linked-list
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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        int sizeOfLL = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            sizeOfLL++;
            temp = temp->next;
        }

        int mid = sizeOfLL / 2;
        temp = head;
        while (--mid)
        {
            temp = temp->next;
        }
        ListNode *deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;

        return head;
    }
};