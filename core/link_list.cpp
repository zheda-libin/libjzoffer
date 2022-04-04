//
// Created by libin on 2022/4/4.
//
#include <cstdio>
#include <cstdlib>
#include <stack>
#include "link_list.h"


namespace link_list{
    //****************************** CORE ******************************
    ListNode* CreateListNode(int value)
    {
        ListNode* pNode = new ListNode();
        pNode->m_nValue = value;
        pNode->m_pNext = nullptr;

        return pNode;
    }

    void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
    {
        if(!pCurrent)
        {
            printf("Error to connect two nodes.\n");
            exit(1);
        }

        pCurrent->m_pNext = pNext;
    }

    void PrintListNode(ListNode* pNode)
    {
        if(!pNode)
        {
            printf("The node is nullptr\n");
        }
        else
        {
            printf("The key in node is %d.\n", pNode->m_nValue);
        }
    }

    void PrintList(ListNode* pHead)
    {
        printf("PrintList starts.\n");

        ListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            printf("%d\t", pNode->m_nValue);
            pNode = pNode->m_pNext;
        }

        printf("\nPrintList ends.\n");
    }

    void DestroyList(ListNode* pHead)
    {
        ListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            pHead = pHead->m_pNext;
            delete pNode;
            pNode = pHead;
        }
    }












    //****************************** ALGO ******************************
    void PrintListReversingly_Iteratively(ListNode * pHead)
    {
        std::stack<ListNode *> nodes;
        ListNode * pNode = pHead;
        while (pNode != nullptr)
        {
            nodes.push(pNode);
            pNode = pNode->m_pNext;
        }

        while(!nodes.empty())
        {
            pNode = nodes.top();
            // 此处如果先pop，那么pNode作为原来的top就会失效了。故必须先打印，
            // 然后再行pop。此外注意pop是没有返回值的
            printf("%d\t", pNode->m_nValue);
            nodes.pop();
        }
    }


    void PrintListReversingly_Recursively(ListNode * pHead)
    {
        if (pHead != nullptr)
        {
            if (pHead->m_pNext != nullptr)
            {
                PrintListReversingly_Recursively(pHead->m_pNext);
            }
            printf("%d\t", pHead->m_nValue);
        }
    }


    void DeleteNode(ListNode ** pListHead, ListNode* pToBeDeleted)
    {
        // 普通情况，是不是尾结点，若不是
        if (pToBeDeleted->m_pNext != nullptr)
        {
            ListNode* pNext = pToBeDeleted->m_pNext;
            pToBeDeleted->m_nValue = pNext->m_nValue;
            pToBeDeleted->m_pNext = pNext->m_pNext;
            delete pNext;
            pNext = nullptr;        // 空悬指针
        }
        // 单节点
        else if (*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        }
        // 删除节点是尾结点，且不为单节点
        else
        {
            ListNode * pNode = *pListHead;
            while(pNode->m_pNext != pToBeDeleted)
            {
                pNode = pNode->m_pNext;
            }
            pNode->m_pNext = nullptr;
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
}



















