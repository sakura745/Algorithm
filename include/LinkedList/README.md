```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
```


**快慢指针确认起始点**

对于给定的输出长度不确定时候。用数学归纳法来判断自己选择的方法是否正确。如Linkedlist长度分别为0，1，2，3，4开始找规律
基本上可以确定是否适用了，因为再长的都同理。

---
因为链表的本质是指针，根据题意有的需要修改链表，有个需要建立辅助链表。
