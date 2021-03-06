struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

// 递归全翻转
ListNode* reverseRecurrence(ListNode* head){
    // 边界处理
    if (head==nullptr) return nullptr;

    // base case
    if (head->next == nullptr) return head;
    // head -- (list)
    // null -- reverse(list) -- head
    // last ==> reverse(list) -- head
    ListNode* last = reverseRecurrence(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}



// 前N翻转：就是要记录好后继
ListNode* successor = nullptr; // 后继节点存储

// 翻转前N个
ListNode* reverseN(ListNode* head, int n){
    if (n==1){
        successor = head->next;
        return head;
    }

    // 翻转前n-1个节点
    ListNode* last = reverseN(head->next, n-1);
    // 注意边界检测
    if (head->next){
        head->next->next = head;
    }
    // 把后继节点连到翻转尾部
    head->next = successor;
    return last;
}


// 翻转链表的一部分
ListNode* reverseBetween(ListNode* head, int left, int right){
    // left=1时就翻转前N
    if (head==nullptr) return nullptr;
    if (left==1){
        return reverseN(head, right);
    }
    // 继续到翻转下一个节点，直到翻转点开始
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}



// 迭代法
// 双指针
ListNode* reverseList(ListNode* head){
    ListNode* cur = nullptr, *pre = head;
    while( pre != nullptr){
        ListNode* t = pre->next;
        pre->next = cur;
        cur = pre;
        pre = t;
    }
    return cur;
}



