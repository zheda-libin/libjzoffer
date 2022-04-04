//
// Created by libin on 2022/4/4.
//

#ifndef LIBJZOFFER_LINK_LIST_H
#define LIBJZOFFER_LINK_LIST_H


namespace link_list{

    struct ListNode
    {
        int       m_nValue;
        ListNode* m_pNext;
    };

    typedef struct ListNode* PtrToLNode;
    typedef PtrToLNode List;

    //****************************** CORE ******************************
    ListNode* CreateListNode(int value);
    void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
    void PrintListNode(ListNode* pNode);
    void PrintList(ListNode* pHead);
    void DestroyList(ListNode* pHead);






    //****************************** ALGO ******************************
    void PrintListReversingly_Iteratively(ListNode * pHead);
    void PrintListReversingly_Recursively(ListNode * pHead);
}

#endif //LIBJZOFFER_LINK_LIST_H
