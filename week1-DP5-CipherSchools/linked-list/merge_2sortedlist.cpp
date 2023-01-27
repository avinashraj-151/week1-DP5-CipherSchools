#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeTwoLists(ListNode *a, ListNode *b){
    if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;
    }else{
        ListNode * result = NULL;
        if(a->val<=b->val){
            result = a;
            result->next = mergeTwoLists(a->next,b);
        }else{
            result = b;
            result->next = mergeTwoLists(a,b->next);
        }
        return result;
    }
}
ListNode *mergeKSorted(vector<ListNode*> lists){
    if(lists.size() == 0){
        return NULL;
    }else if(lists.size()== 1){
        return lists[0];
    }else{
        int last = lists.size()-1;
        while(last>0){
            int i =0,j=last;
            while(i<j){
                lists[i] = mergeTwoLists(lists[i],lists[j]);
                i++; j--;
                if(i>=j){
                    last = j;
                }
            }
        }
        return lists[0];
    }
}
ListNode * reverse(ListNode *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode * prev = NULL, *curr =head, *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
ListNode * reverseIngroup(ListNode *head,int K){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode * prev = NULL, *curr =head, *next = NULL;
    int k= 0;
    while(curr!=NULL && k<K){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(next!=NULL){
    head->next = reverseIngroup(next,K);
    }
    return head;
}
int main(){
    return 0;
}