#include <vector>
using namespace std;

// Runtime: 22 ms, faster than 73.16% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 24 MB, less than 80.41% of C++ online submissions for Product of Array Except Self.
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> new_array(n, 1);
        int from_aft_prod = 1;
        int from_fwd_prod = 1;
        for (int i = 0; i < n; ++i)
        {
            new_array[i] *= from_fwd_prod;
            from_fwd_prod *= nums[i];
            new_array[n - i - 1] *= from_aft_prod;
            from_aft_prod *= nums[n - i - 1];
        }
        return new_array;
    }
};