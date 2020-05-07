#include <unordered_map>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        unordered_map<int, int> m;
        m[0] = 1;
        return numTrees(n, m);
    }
private:
    int numTrees(int n, unordered_map<int, int>& m) {
        if (m.count(n)) {
            return m[n];
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            m[i - 1] = numTrees(i - 1, m);
            m[n - i] = numTrees(n - i, m);

            result += m[i - 1] * m[n - i];
        }

        m[n] = result;

        return result;
    }
};