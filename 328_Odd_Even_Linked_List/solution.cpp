#include "header.h"

ListNode* oddEvenList(ListNode* head)
{
    if (head && head->next)
    {
        ListNode* node1 = head;
        ListNode* node2 = node1->next;
        ListNode* node3 = node2->next;

        while (node3)
        {
            node2->next = node3->next;
            node3->next = node1->next;
            node1->next = node3;

            node1 = node1->next;
            node2 = node2->next;
            node3 = node2 ? node2->next : NULL;
        }
    }
    return head;
}