// Problem Statement -> https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/

// Idea -> Linked List Manipulation

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int n = 1;
        ListNode *evenHead = NULL, *oddHead = NULL, *p = NULL, *q = NULL;
        
        while(head){
            if(n%2){
                if(oddHead == NULL){
                    oddHead = head;
                    p = head;
                }
                else{
                    p->next = head;
                    p = head;
                }
            }
            else{
                if(evenHead == NULL){
                    evenHead = head;
                    q = head;
                }
                else{
                    q->next = head;
                    q = head;
                }
            }
            
            head = head->next;
            n++;
        }
        if(q)
            q->next = NULL;
        if(p)
            p->next = evenHead;
        return oddHead;
    }
};
