#include <iostream>
#include <assert.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *);

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2);

private:
    ListNode *getLoopNode(ListNode *head);

    ListNode *getIntersectionNode_NoLoop(ListNode *headA, ListNode *headB);

    ListNode *getIntersectionNode_DoubleLoop(ListNode *headA, ListNode *headB);
};

ListNode *testLoopData1();
ListNode *testData1();
ListNode *testLoopData2();
ListNode *testData2();

int main() {

    ListNode *test1 = testLoopData1();
    ListNode *test2 = testLoopData2();

    ListNode *test3 = testData1();
    ListNode *test4 = testData2();
    test3->next->next->next = test4->next->next->next->next;

//    cout << "Test1 : ";
//    printLinkedList(test1);
//    cout << "Test2 : ";
//    printLinkedList(test2);
    cout << "Test3 : ";
    printLinkedList(test3);
    cout << "Test4 : ";
    printLinkedList(test4);

    Solution A;
    assert(A.getIntersectionNode(test3, test4));
    cout << "That has intersection and position is at " << A.getIntersectionNode(test3, test4)->val;

}

void printLinkedList(ListNode *head) {
    ListNode *cur = head;
    int n = 0;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
        n++;
        if (n > 20) break;//如果有环，则跳出环
    }
    cout << endl;
}

ListNode *testLoopData1() {
    ListNode *test;
    test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next = new ListNode(6);
    test->next->next->next->next->next->next = new ListNode(7);
    test->next->next->next->next->next->next->next = new ListNode(8);
    test->next->next->next->next->next->next->next->next = test->next->next->next->next;
    return test;
}
ListNode *testData1() {
    ListNode *test;
    test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next = new ListNode(6);
    test->next->next->next->next->next->next = new ListNode(7);
    test->next->next->next->next->next->next->next = new ListNode(8);

    return test;
}
ListNode *testLoopData2() {
    ListNode *test;
    test = new ListNode(9);
    test->next = new ListNode(10);
    test->next->next = new ListNode(11);
    test->next->next->next = new ListNode(12);
    test->next->next->next->next = new ListNode(13);
    test->next->next->next->next->next = new ListNode(14);
    test->next->next->next->next->next->next = new ListNode(15);
    test->next->next->next->next->next->next->next = new ListNode(16);
    test->next->next->next->next->next->next->next->next = new ListNode(17);
    test->next->next->next->next->next->next->next->next->next = new ListNode(18);
    test->next->next->next->next->next->next->next->next->next->next = new ListNode(19);
    test->next->next->next->next->next->next->next->next->next->next->next = test->next->next->next->next->next->next;
    return test;
}
ListNode *testData2() {
    ListNode *test;
    test = new ListNode(9);
    test->next = new ListNode(10);
    test->next->next = new ListNode(11);
    test->next->next->next = new ListNode(12);
    test->next->next->next->next = new ListNode(13);
    test->next->next->next->next->next = new ListNode(14);
    test->next->next->next->next->next->next = new ListNode(15);
    test->next->next->next->next->next->next->next = new ListNode(16);
    test->next->next->next->next->next->next->next->next = new ListNode(17);
    test->next->next->next->next->next->next->next->next->next = new ListNode(18);
    test->next->next->next->next->next->next->next->next->next->next = new ListNode(19);
    return test;
}


ListNode *Solution::getIntersectionNode(ListNode *head1, ListNode *head2) {
    if (nullptr == head1 || nullptr == head2 || nullptr == head1->next || nullptr == head2->next)
        return nullptr;
    ListNode *loop1 = getLoopNode(head1);
    ListNode *loop2 = getLoopNode(head2);
    if (nullptr == loop1 && nullptr == loop2) {
        return getIntersectionNode_NoLoop(head1, head2);
    }
    return getIntersectionNode_DoubleLoop(head1, head2);
}

ListNode *Solution::getLoopNode(ListNode *head) {
//        if(nullptr == head || nullptr == head->next) return nullptr;
    ListNode *slow = head->next, *fast = head->next->next;//判断是否为相等，所以初始值不能设置相等
    while (slow != fast) {
        if (nullptr == fast->next || nullptr == fast->next->next) return nullptr;//fast指针到终点了，没有环
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

ListNode *Solution::getIntersectionNode_NoLoop(ListNode *headA, ListNode *headB) {
//        if(nullptr == headA || nullptr == headB) return nullptr;
    ListNode *cur1 = headA, *cur2 = headB;
    int n = 0;//用来计算两个列表的长度差值
    while (cur1->next != nullptr) {
        n++;
        cur1 = cur1->next;
    }
    while (cur2->next != nullptr) {
        n--;
        cur2 = cur2->next;
    }
    if (cur1 != cur2) return nullptr;//判断是否相交
    cur1 = n > 0 ? headA : headB;//通过用差值来确认长的链表为cur1
    cur2 = cur1 == headA ? headB : headA;//根据上一行来判断另一个较短的为cur2
    n = abs(n);
    //使长的链表先运动差值，保证两个链表同步长度
    while (n != 0) {
        n--;
        cur1 = cur1->next;
    }
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur2;
}

ListNode *Solution::getIntersectionNode_DoubleLoop(ListNode *headA, ListNode *headB) {
    ListNode *loop1 = getLoopNode(headA);
    ListNode *loop2 = getLoopNode(headB);
    if (loop1 == loop2) {
        ListNode *cur1 = headA, *cur2 = headB;
        int n = 0;;
        while (cur1->next != nullptr) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2->next != nullptr) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? headA : headB;
        cur2 = cur1 == headA ? headB : headA;
        n = abs(n);
        while (n != 0) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    } else {
        ListNode *cur = loop1->next;
        while (cur != loop1) {
            if (cur != loop2)
                return nullptr;
            cur = cur->next;
        }
        return loop2;
    }
}

