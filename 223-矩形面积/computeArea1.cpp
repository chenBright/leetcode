#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        if (F >= D || E >= C || H <= B || G <= A) {
            return area1 + area2;
        }

        return area1 + area2 - (min(C, G) - max(E, A)) * (min(D, H) - max(B, F));
    }
};