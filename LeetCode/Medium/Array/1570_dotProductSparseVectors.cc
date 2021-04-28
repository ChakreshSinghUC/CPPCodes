// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

#include <iostream>
#include <vector>
using namespace std;

class SparseVector
{
    vector<int> v;

public:
    SparseVector(vector<int> &nums)
    {
        v = nums;
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        if (v.size() == 0)
            return 0;

        int dot_prod = 0;
        
        for (int i = 0; i < v.size(); i++)
        {
            dot_prod += v[i] * vec.v[i];
        }
        return dot_prod;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
int main()
{
    vector<int> nums1{1, 0, 0, 2, 3};
    vector<int> nums2{0, 3, 0, 4, 0};

    SparseVector s(nums1);
    SparseVector s1(nums2);
    cout << s.dotProduct(s1);
}
