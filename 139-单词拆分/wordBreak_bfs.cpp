#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// 广度优先搜索
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        set<int> wordLengthSet; // 用于储存wordDict中单词的长度
		int strSize = s.size();
		// 首先扫描一遍，获取wordDict长度的种类
		for (auto word : wordDict) {
			wordLengthSet.insert(word.size());
		}
		queue<int> myQueue;
		myQueue.push(0);
		int tempQueueSize, tempBegin;
		while (!myQueue.empty()) {
			tempQueueSize = myQueue.size();
			for (int i = 0; i < tempQueueSize; ++i) {
				tempBegin = myQueue.front();
				myQueue.pop();
				for (auto it = wordLengthSet.rbegin(); it != wordLengthSet.rend(); ++it) { // set默认从大到小排序，先从短子串开始搜索
					string subS = s.substr(tempBegin, *it);
					if (find(wordDict.begin(), wordDict.end(), subS) != wordDict.end()) {
						if (tempBegin + *it >= strSize) {
							return true;
						}
						myQueue.push(tempBegin + *it);
					}
				}
			}
		}

		return false;
    }
};