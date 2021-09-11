//
// Created by sakura on 11/09/2021.
//

#ifndef ALGORITHM_INTERSECTIONNODE_HARD_H
#define ALGORITHM_INTERSECTIONNODE_HARD_H

//给定两个链表(不确定是否有环)。请判断如果两个链表相交，则返回第一个节点；如果不相交，则返回Null
class Solution{
public:

private:
    ListNode *getLoopNode(ListNode* head){
        if(nullptr == head || nullptr == head->next) return nullptr;
        ListNode * slow = head->next, *fast = head->next->next;//判断是否为相等，所以初始值不能设置相等
        while(slow != fast){
            if(nullptr == fast->next || nullptr == fast->next->next) return nullptr;//fast指针到终点了，没有环
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

#endif //ALGORITHM_INTERSECTIONNODE_HARD_H
