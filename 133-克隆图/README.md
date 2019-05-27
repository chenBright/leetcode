# 133-克隆图

## 题目

leetcode：[133-克隆图](https://leetcode-cn.com/problems/clone-graph/)

## DFS

使用`HashMap`记录原图中的结点和新生成的克隆图中的结点。

- 如果结点为空，则返回`NULL`。
- 如果当前结点在`HashMap`中，即当前结点已经被克隆过，则直接返回其映射结点。
- 否则，克隆当前结点，并在`HashMap`中建立映射，然后遍历当前结点的所有`neighbor`结点，调用递归函数并且加到克隆结点的`neighbors`数组中。

```c++
class Solution {
public:
    Node* cloneGraph(Node *node) {
        return dfs(node);
    }

private:
    unordered_map<Node*, Node*> nodeMap; // 新旧结点 Map

    Node* dfs(Node *node) {
        if (node == NULL) {
            return NULL;
        }

        // 当前结点在 HashMap 中，即当前结点已经被克隆过
        if (nodeMap.count(node)) {
            return nodeMap[node];
        }

        Node *newNode = new Node(node->val, vector<Node*>());
        nodeMap[node] = newNode;
        for (const auto &neighbor : node->neighbors) {
            // 克隆 neighbor 结点
            newNode->neighbors.push_back(dfs(neighbor));
        }

        return newNode;
    }
};
```

## BFS

除了使用`HashMap`记录原图中的结点和新生成的克隆图中的结点，还需要队列`queue`来辅助图的遍历。

1. 先克隆当前结点，然后建立映射，并加入`queue`中，进行循环。
2. 在循环中，取出队首结点，遍历其所有`neighbor`结点，若不在`HashMap`中，我们根据`neighbor`结点值克隆一个新`neighbor`结点，建立映射，并且放入`queue`中。然后将`neighbor`结点在`HashMap`中的映射结点加入到克隆结点的`neighbors`数组中。
3. 循环直到队列为空为止。

```c++
class Solution {
public:
    Node* cloneGraph(Node *node) {
        unordered_map<Node*, Node*> nodeMap;
        queue<Node*> nodeQueue;

        Node *newNode = new Node(node->val, vector<Node*>());
        nodeMap[node] = newNode;
        nodeQueue.push(node);
        while (!nodeQueue.empty()) {
            node = nodeQueue.front();
            nodeQueue.pop();

            for (const auto &neighbor : node->neighbors) {
                // 没有访问过，放入队列中，并且建立映射
                if (!nodeMap.count(neighbor)) {
                    nodeQueue.push(neighbor);
                    nodeMap[neighbor] = new Node(neighbor->val, vector<Node*>());
                }
                nodeMap[node]->neighbors.push_back(nodeMap[neighbor]);
            }
        }

        return newNode;
    }
};
```

