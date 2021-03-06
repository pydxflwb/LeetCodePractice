struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* a, ListNode* b){
    ListNode* pre = nullptr;
    ListNode* cur = a;
    ListNode* next = a;
    while (cur != b){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}


ListNode* reverseKGroup(ListNode* head, int k){
    if (head==nullptr) return nullptr;

    ListNode* a = head;
    ListNode* b = head;
    // 不足k个时
    for (int i=0; i<k; i++){
        if (b==nullptr) return head;
        b=b->next;
    }

    // k个翻转
    ListNode* newHead = reverse(a, b);
    a->next = reverseKGroup(b, k);
    return newHead;
}