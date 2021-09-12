//
// Created by sakura on 11/09/2021.
//

#ifndef ALGORITHM_INTERSECTIONNODE_HARD_H
#define ALGORITHM_INTERSECTIONNODE_HARD_H

//给定两个链表(不确定是否有环)。请判断如果两个链表相交，则返回第一个节点；如果不相交，则返回Null。

//当都没有环，见IntersectionNode_NoLoop
//当一个链表有环，一个没有环，则不可能相交
//当都有环，分三种：
//一是都不相交，二是先相交再公用一个环，三是分别相交与不同点在同一个环上

class Solution{
public:
    ListNode *getIntersectionNode(ListNode* head1, ListNode* head2){
        if(nullptr == head1 || nullptr == head2 || nullptr == head1->next || nullptr == head2->next)
            return nullptr;
        ListNode* loop1 = getLoopNode(head1);
        ListNode* loop2 = getLoopNode(head2);
        if(nullptr == loop1 && nullptr == loop2){
            return getIntersectionNode_NoLoop(head1, head2);
        }
        return getIntersectionNode_DoubleLoop(head1, head2);
    }

private:
    ListNode *getLoopNode(ListNode* head){
//        if(nullptr == head || nullptr == head->next || nullptr == head->next->next) return nullptr;
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

    ListNode *getIntersectionNode_NoLoop(ListNode *headA, ListNode *headB) {
//        if(nullptr == headA || nullptr == headB) return nullptr;
        ListNode* cur1 = headA, *cur2 = headB;
        int n = 0;//用来计算两个列表的长度差值
        while(cur1->next != nullptr){
            n++;
            cur1 = cur1->next;
        }
        while(cur2->next != nullptr){
            n--;
            cur2 = cur2->next;
        }
        if(cur1 != cur2) return nullptr;//判断是否相交
        cur1 = n > 0 ? headA : headB;//通过用差值来确认长的链表为cur1
        cur2 = cur1 == headA ? headB : headA;//根据上一行来判断另一个较短的为cur2
        n = abs(n);
        //使长的链表先运动差值，保证两个链表同步长度
        while(n != 0){
            n--;
            cur1 = cur1->next;
        }
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur2;
    }

    ListNode *getIntersectionNode_DoubleLoop(ListNode * headA, ListNode *headB){
        ListNode * loop1 = getLoopNode(headA);
        ListNode * loop2 = getLoopNode(headB);
        if(loop1 == loop2){
            ListNode *cur1 = headA, *cur2 = headB;
            int n = 0;;
            while(cur1->next != nullptr){
                n++;
                cur1 = cur1->next;
            }
            while(cur2->next != nullptr){
                n--;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? headA : headB;
            cur2 = cur1 == headA ? headB : headA;
            n = abs(n);
            while(n != 0){
                n--;
                cur1 = cur1->next;
            }
            while(cur1 != cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        } else {
            ListNode * cur = loop1->next;
            while(cur != loop1){
                if(cur != loop2)
                    return nullptr;
                cur = cur->next;
            }
            return loop2;
        }
    }

};

#endif //ALGORITHM_INTERSECTIONNODE_HARD_H
