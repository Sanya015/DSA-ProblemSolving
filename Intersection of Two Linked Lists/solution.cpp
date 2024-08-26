/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Brute Force: T.C.=O(MN) S.C.=O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempb=headB;
        while(headA!=nullptr){
            headB=tempb;
            while(headB!=nullptr){
                if(headA==headB) return headA;
                headB=headB->next;
            }
            headA=headA->next;
        }
        return nullptr;
    }
};

// Better Approach: T.C.=O(M+N) S.C.=O(M)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> m;
        while(headA!=nullptr){
            m[headA]=headA->val;
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(m.find(headB)!=m.end()) return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};

// Optimal sol1: T.C.=O(M)+O(M-N)+O(N)=O(2M) S.C.=O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        int a=0;
        int b=0;
        while(headA!=nullptr || headB!=nullptr){
            if(headA!=nullptr){
                a++;
                headA=headA->next;
            }
            if(headB!=nullptr){
                b++;
                headB=headB->next;
            }
        }
        headA=tempa;
        headB=tempb;
        if(a>b){
            int diff=a-b;
            for(int i=0; i<diff; i++){
                headA=headA->next;
            }
        }
        else{
            int diff=b-a;
            for(int i=0; i<diff; i++){
                headB=headB->next;
            }
        }
        while(headA!=nullptr && headB!=nullptr && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

// Optimal sol2: T.C.=O(2M) S.C.=0(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        while(headA!=headB){
            if(headA==nullptr) headA=tempb;
            else headA=headA->next;
            if(headB==nullptr) headB=tempa;
            else headB=headB->next;
        }
        return headA;
    }
};
