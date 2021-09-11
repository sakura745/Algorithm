//
// Created by bas on 9/10/21.
//

#ifndef ALGRITHOM_INTERSECTIONNODE_H
#define ALGRITHOM_INTERSECTIONNODE_H

//法一： 用双指针循环无限循环，但是时间较长
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(NULL == headA || NULL == headB) return NULL;
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1 != NULL ? cur1->next : headA;
            cur2 = cur2 != NULL ? cur2->next : headB;
        }
        return cur1;
    }
};


//法二:分别遍历链表，通过末尾node判断是否有相交，若相等，则有相交

#endif //ALGRITHOM_INTERSECTIONNODE_H
