# 912-排序数组

## 题目

leetcode：[912-排序数组](https://leetcode-cn.com/problems/sort-an-array/)

## 选择排序

从数组中选择最小元素，将它与数组的第一个元素交换位置。再从数组剩下的元素中选择出最小的元素，将它与数组的第二个元素交换位置。不断进行这样的操作，直到将整个数组排序。

时间复杂度：**O(n^2)**。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int minIndex = i;
            // 选择最小的元素
            for (int j = i + 1; j < length; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            if (nums[minIndex] < nums[i]) {
                swap(nums[minIndex], nums[i]);
            }
        }

        return nums;
    }
};
```

## 冒泡排序

从左到右不断交换相邻逆序的元素，在一轮的循环之后，可以让未排序的最大元素上浮到右侧。

在一轮循环中，如果没有发生交换，那么说明数组已经是有序的，此时可以直接退出。

时间复杂度：**O(n^2)**。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int flag = true; // 假设剩下的元素有序。
            for (int j = 0; j < length - 1 - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    flag = false; // 无序
                }
            }
            if (flag) {
                break;
            }
        }

        return nums;
    }
};
```

## 插入排序

每次都将当前元素插入到左侧已经排序的数组中，使得插入之后左侧数组依然有序。

时间复杂度：**O(n^2)**。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 1; i < length; ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }

        return nums;
    }
};
```

## 希尔排序

对于大规模的数组，插入排序很慢，因为它只能交换相邻的元素，每次只能将逆序数量减少 1。希尔排序的出现就是为了解决插入排序的这种局限性，它通过交换不相邻的元素，每次可以将逆序数量减少大于 1。

希尔排序使用插入排序对间隔 h 的序列进行排序。通过不断减小 h，最后令 h=1，就可以使得整个数组是有序的。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int gap = length / 2; gap > 0; gap /= 2) { // 间隔
            for (int i = gap; i < length; ++i) {
                for (int j = i; j >= gap && nums[j] < nums[j - gap]; j -= gap) {
                    swap(nums[j], nums[j - gap]);
                }
            }
        }

        return nums;
    }
};
```

## 归并排序

归并排序的思想是将数组分成两部分，分别进行排序，然后归并起来。

时间复杂度：**O(nlogn)**。

### 递归实现（自顶向下）

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        aux.reserve(nums.size());
        mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    vector<int> aux;
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;
        mergeSort(nums, low ,mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int k = low; k <= high; ++k) {
            aux[k] = nums[k];
        }

        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; ++k) {
            if (i > mid) {
                nums[k] = aux[j++];
            } else if (j > high) {
                nums[k] = aux[i++];
            } else if (aux[i] < aux[j]) {
                nums[k] = aux[i++];
            } else {
                nums[k] = aux[j++];
            }
        }
    }
};
```

## 迭代实现（自底向上）

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        aux.reserve(length);
        for (int i = 1; i < length; i *= 2) { // 分组大小
            for (int low = 0; low < length - i; low += 2 * i) {
                // 归并的第一个子数组：[low, low + i - 1]
                // 归并的第二个子数组：[low + i, min(low + 2 * i - 1, length - 1)]
                merge(nums, low, low + i - 1, min(low + 2 * i - 1, length - 1));
            }
        }
        return nums;
    }
private:
    vector<int> aux;

    void merge(vector<int>& nums, int low, int mid, int high) {
        for (int k = low; k <= high; ++k) {
            aux[k] = nums[k];
        }

        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; ++k) {
            if (i > mid) {
                nums[k] = aux[j++];
            } else if (j > high) {
                nums[k] = aux[i++];
            } else if (aux[i] < aux[j]) {
                nums[k] = aux[i++];
            } else {
                nums[k] = aux[j++];
            }
        }
    }
};
```

## 快速排序

时间复杂度：**O(nlogn)**。

### 基本实现

快速排序通过一个切分元素将数组分为两个子数组，左子数组小于等于切分元素，右子数组大于等于切分元素，将这两个子数组排序也就将整个数组排序了。

#### 递归

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int i = left;
        int j = right;
        int pivot = nums[i];
        while (i < j) {
            // 因为 i 空出来了，所以先从后面开始。
            // 找到小于等于 pivot 的元素
            while (i < j && nums[j] > pivot) {
                --j;
            }
            if (i == j) {
                break;
            }
            nums[i] = nums[j];
            ++i;

            // 找到大于 pivot 的元素
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            if (i == j) {
                break;
            }
            nums[j] = nums[i];
            --j;
        }
        nums[i] = pivot;

        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};
```

## 迭代

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        queue<pair<int, int> > q; // 保存需要排序的区域，<left, right>
        q.push(make_pair(left, right));
        while (!q.empty()) {
            auto region = q.front();
            q.pop();

            int index = paritition(nums, region.first, region.second);
            // 分区长度大于 1，则将入队列中继续排序。
            if (region.first < index - 1) {
                q.push(make_pair(region.first, index - 1));
            }
            if (index + 1 < region.second) {
                q.push(make_pair(index + 1, region.second));
            }
        }
    }

    int paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return left;
        }

        int i = left;
        int j = right;
        int pivot = nums[left];
        while (i < j) {
            // 因为 i 空出来了，所以先从后面开始。
            // 找到小于等于 pivot 的元素
            while (i < j && nums[j] > pivot) {
                --j;
            }
            if (i == j) {
                break;
            }
            nums[i++] = nums[j];

            // 找到大于 pivot 的元素
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            if (i == j) {
                break;
            }
            nums[j--] = nums[i];
        }
        nums[i] = pivot;

        return i;
    }
};
```

### 优化--三向切分

对于有大量重复元素的数组，可以将数组切分为三部分，分别对应小于、等于和大于切分元素。

三向切分快速排序对于有大量重复元素的随机数组可以在线性时间内完成排序。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        auto indexs = paritition(nums, left, right);

        quickSort(nums, left, indexs.first);
        quickSort(nums, indexs.second, right);
    }

    pair<int, int> paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return make_pair(left, left);
        }

        int i = left;
        int j = right;
        int k = i + 1;
        while (k <= j) {
            // 小于 pivot 的范围：[low, i - 1]
            // 等于 pivot 的范围：[i, k]
            // 大于 pivot 的范围：[j + 1, high]
            if (nums[k] < nums[i]) {
                swap(nums[k++], nums[i++]);
            } else if (nums[k] > nums[i]) {
                // 因为 nums[j] 未比较，所以 k 不变。下一循环时，再比较。
                swap(nums[k], nums[j--]);
            } else {
                ++k;
            }
        }

        return make_pair(i - 1, j + 1);
    }
};
```

#### 迭代

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, static_cast<int>(nums.size()) - 1);

        return nums;
    }
private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        queue<pair<int, int> > q;
        q.push(make_pair(low, high));
        while (!q.empty()) {
            auto region = q.front();
            q.pop();

            auto indexs = paritition(nums, region.first, region.second);
            // 分区长度大于 1，则将入队列中继续排序。
            if (region.first < indexs.first) {
                q.push(make_pair(region.first, indexs.first));
            }
            if (indexs.second < region.second) {
                q.push(make_pair(indexs.second, region.second));
            }
        }
    }

    pair<int, int> paritition(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return make_pair(left, left);
        }

        int i = left;
        int j = right;
        int k = i + 1;
        while (k <= j) {
            // 小于 pivot 的范围：[low, i - 1]
            // 等于 pivot 的范围：[i, k]
            // 大于 pivot 的范围：[j + 1, high]
            if (nums[k] < nums[i]) {
                swap(nums[k++], nums[i++]);
            } else if (nums[k] > nums[i]) {
                // 因为 nums[j] 未比较，所以 k 不变。下一循环时，再比较。
                swap(nums[k], nums[j--]);
            } else {
                ++k;
            }
        }

        return make_pair(i - 1, j + 1);
    }
};
```

## 堆排序

### 堆

堆中某个节点的值总是大于等于其子节点的值，并且堆是一颗完全二叉树。

堆可以用数组来表示，这是因为堆是完全二叉树，而完全二叉树很容易就存储在数组中。位置 k 的节点的父节点位置为`k`，而它的两个子节点的位置分别为`2k + 1`和`2k + 2`。

### 上浮和下沉

在堆中，当一个节点比父节点大，那么需要交换这个两个节点。交换后还可能比它新的父节点大，因此需要不断地进行比较和交换操作，把这种操作称为上浮。

```c++
void swim(vector<int>& nums, int k) {
		while (k > 0 && nums[(k - 1) / 2] < nums[k]) {
      	swap(nums[(k - 1) / 2], nums[k]);
      	k = (k - 1) / 2;
    }
}
```

类似地，当一个节点比子节点来得小，也需要不断地向下进行比较和交换操作，把这种操作称为下沉。一个节点如果有两个子节点，应当与两个子节点中最大那个节点进行交换。

```c++
void sink(vector<int>& nums, int k, int length) {
    while (2 * k + 1 < length) {
			int c1 = 2 * k + 1; // 左结点
			int c2 = 2 * k + 2; // 右结点
			int c = (c2 < length && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点

      if (nums[k] >= nums[c]) {
          break;
      }

      swap(nums[k], nums[c]);
	      k = c;
      }
}
```

### 排序

把最大元素和当前堆中数组的最后一个元素交换位置，并且不删除它，那么就可以得到一个从尾到头的递减序列，从正向来看就是一个递增序列，这就是堆排序。

- 构建堆

  无序数组建立堆最直接的方法是从左到右遍历数组进行上浮操作。一个**更高效的方法**是从右至左进行下沉操作，如果一个节点的两个节点都已经是堆有序，那么进行下沉操作可以使得这个节点为根节点的堆有序。叶子节点不需要进行下沉操作，可以忽略叶子节点的元素，因此只需要遍历一半的元素即可。

- 交换堆顶元素与最后一个元素

  交换之后需要进行下沉操作维持堆的有序状态。

时间复杂度：**O(nlogn)**。

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        // 构建堆
        for (int i = (length - 1) / 2; i >= 0; --i) {
            sink(nums, i, length);
        }

        // 排序
        for (int i = length - 1; i > 0; --i) {
            // 将当前最大的结点放到最后面。
            swap(nums[i], nums[0]);
            // 重新构建堆
            sink(nums, 0, i);
        }

        return nums;
    }

private:
    // 下沉，下沉到较大的结点中。
    void sink(vector<int>& nums, int k, int length) {
        while (2 * k + 1 < length) {
            int c1 = 2 * k + 1; // 左结点
            int c2 = 2 * k + 2; // 右结点
            int c = (c2 < length && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点

            if (nums[k] >= nums[c]) {
                break;
            }

            swap(nums[k], nums[c]);
            k = c;
        }
    }
};
```

## 计数排序

- 找出待排序的数组中最大元素和最小元素；
- 统计数组中每个值为`i`的元素出现的次数，存入数组`buckets` 的第`i`项；
- 对所有的计数累加（从`counts` 中的第一个元素开始，每一项和前一项相加）；
- 反向填充目标数组：将每个元素`i`放在新数组的第`counts[i]`项，每放一个元素就将`counts[i]`减去 1。

参考[计数排序(Counting sort)](https://juejin.im/post/5cac107ee51d456e7079f1d5)和[维基百科]([https://zh.wikipedia.org/wiki/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F](https://zh.wikipedia.org/wiki/计数排序))。

上述实现需要两个辅助数组，下面的代码优化为只需要一个桶数组。

- 找出待排序的数组中最大元素`high`和最小元素`low`；
- 统计数组中每个值为`i`的元素出现的次数，存入数组`buckets` （容量为`high - low + 1`）的第`i - low`项；
- 填充目标数组：遍历数组`buckets`，向目标数组后面加入`buckets[i]`个等于`i`的元素。

时间复杂度：**O(max(n, high - low))**。

时间复杂度：**O(high - low)**。其中`n`为原数组的大小，`high`、`low`分别为数组中最大元素和最小元素；

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int bucketsNum = high - low + 1;
        vector<int> buckets(bucketsNum, 0);
        for (const auto& num : nums) {
            ++buckets[num - low];
        }

        int j = 0;
        for (int i = 0; i < bucketsNum; ++i) {
            while (buckets[i]-- > 0) {
                nums[j++] = i + low;
            }
        }

        return nums;
    }
};
```

## 参考

- [[c++\] 8种排序方法[详解]](https://leetcode-cn.com/problems/sort-an-array/solution/c-8chong-pai-xu-fang-fa-xiang-jie-by-zsq/)
- [CyC2018]([https://github.com/CyC2018/CS-Notes/blob/master/notes/%E7%AE%97%E6%B3%95%20-%20%E6%8E%92%E5%BA%8F.md](https://github.com/CyC2018/CS-Notes/blob/master/notes/算法 - 排序.md))

