/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// MY SOLUTION (if we are allowed to alter te values of nodes)
// T.C.=O(N) S.C.=O(1)
    bool hasCycle(ListNode *head) {
        while(head!=nullptr){
            if(head->val>100000) return true;
            head->val=100001;
            head=head->next;
        }
        return false;
    }
};

// If we wre not allowed to alter values of nodes
// BRUTE: T.C.=O(N * 2 * log(N)) S.C.=O(N)
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode*, int> m;
        while(temp!=nullptr){
            if(m.find(temp)!=m.end()){
                return true;
            }
            m[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};

// OPTIMAL: T.C.=O(N) S.C.=O(1)
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

