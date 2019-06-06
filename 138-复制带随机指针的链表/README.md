# 138-复制带随机指针的链表

## 题目

leetcode：[138-复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

## 使用HashMap记录源结点和拷贝结点的映射关系

### 迭代

1. 先遍历一次源链表，生成一个新的拷贝链表，并使用HashMap记录源结点和拷贝结点的映射关系。此时不处理`random`指针，都为`NULL`。
2. 再遍历一次源链表，在HashMap中找到对应的拷贝结点。因为源结点`random`指针指向的结和拷贝结点的`random`指针指向的结点的映射关系也可以在HashMap中找到，所以借助HashMap可以设置好拷贝链表上所有结点的`random`指针。

```c++
class Solution {
public:
    Node* copyRandomList(Node *head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> nodeMap;
        Node *dummy = new Node();
        Node *newNode = dummy;
        Node *node = head;
        // 遍历拷贝结点，并生成源节点与拷贝结点的映射
        while (node != NULL) {
            newNode->next = new Node(node->val, NULL, NULL);
            newNode = newNode->next;
            nodeMap.insert(make_pair(node, newNode));
            node = node->next;
        }

        node = head;
        // 设置 random 指针
        while (node != NULL) {
            Node *randomNode = node->random;
            nodeMap[node]->random = nodeMap[randomNode];
            node = node->next;
        }

        return dummy->next;
    }
};
```

### 递归

递归实现同样需要使用HashMap记录源结点和拷贝结点的映射关系。

在递归函数中：

1. 首先判空，若为空，则返回空指针。
2. 然后在HashMap中查找是否已经在拷贝链表中存在了该结点。如果存在的话，则直接返回。否则，新建一个拷贝结点`newNode`，建立源结点和该拷贝结点之间的映射，然后给拷贝结点的`next` 指针和`random`指针指针赋值了，即分别调用递归函数。

```c++
class Solution {
public:
    Node* copyRandomList(Node *head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> nodeMap;
        return copyNode(head, nodeMap);
    }

private:
    Node *copyNode(Node *node, unordered_map<Node*, Node*> &nodeMap) {
        if (node == NULL) {
            return NULL;
        }

        if (nodeMap.count(node)) { // 已经拷贝过了，则直接返回
            return nodeMap[node];
        }

        Node *newNode = new Node(node->val, NULL, NULL);
        nodeMap[node] = newNode; // 标记为拷贝过
        newNode->next = copyNode(node->next, nodeMap);
        newNode->random = copyNode(node->random, nodeMap);

        return newNode;
    }
};
```

## 原地处理

将克隆结点插入在原结点后面，在原链表上处理克隆结点的random指针，最后分离两个链表。

```c++
class Solution {
public:
    Node* copyRandomList(Node *head) {
        if (head == NULL) {
            return NULL;
        }

        Node *node = head;
        Node *newNode = NULL;
        // 将拷贝结点插入到源结点后面，例如 1->2->3  ==>  1->1'->2->2'->3->3'
        while (node != NULL) {
            newNode = new Node(node->val, node->next, NULL);
            node->next = newNode;
            node = node->next->next;
        }

        node = head;
        // 连接 random 指针
        while (node != NULL) {
            if (node->random != NULL) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        Node *newHead = head->next;
        node = head;
        newNode = newHead;
        // 拆开两个链表
        while (node != NULL) {
            node->next = newNode->next;
            node = node->next;
            if (node != NULL) {
                newNode->next = node->next;
                newNode = newNode->next;
            }
        }

        return newHead;
    }
};
```

