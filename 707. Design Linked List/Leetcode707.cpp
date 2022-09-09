//
// Created by 24191 on 2022/9/9.
//

/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val和next。val是当前节点的值，next是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性prev以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第index个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为val的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第index个节点之前添加值为val 的节点。如果index等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引index 有效，则删除链表中的第ndex 个节点。

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3

 */


class MyLinkedList
{
public :
    struct LinkedNode
    {
        int val;
        LinkedNode *next;

        LinkedNode(int val) : val(val), next(nullptr)
        {}
    };

private:
    int size;
    LinkedNode *dummyHead;
public:


    MyLinkedList()
    {
        dummyHead = new LinkedNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index > (size - 1) || index < 0)
        {
            return -1;
        }
        LinkedNode *cur = dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *cur = dummyHead->next;
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = cur;
        dummyHead->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *cur = dummyHead;
        LinkedNode *newNode = new LinkedNode(val);
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        LinkedNode *cur = dummyHead;
        LinkedNode *newNode = new LinkedNode(val);
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }
        LinkedNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *delNode = cur->next;
        cur->next = cur->next->next;
        delete delNode;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */