#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol33;
using namespace std;

/*takeaways
  - how do you know an array is sorted quickly? nums[0] < nums[n-1]
      [0,1,2,3,4,5,6,7]
      - rotate to the right you got [7,0,1,2,3,4,5,6], the biggest
        number will be in nums[0] so nums[0] > nums[n-1]
      - rotate to the left you got [1,2,3,4,5,6,7,0], the smallest
        number will be in nums[n-1] so nums[0] > nums[n-1]

  - in this question, we just keep breaking down the array into
    two subarrays. One of them must be sorted - we just check if the
    target is in that sorted array, which can be done quickly. If
    the target is not in the sorted array, it might be in the
    other subarray. Either way, we just keep breaking down the
    array until we either find the target or exit without finding
    it.

  - [4,5,6,7,0,1,2]
    - break it down into two subarrays (right in the middle)
      - [4,5,6] and [7,0,1,2] - [4,5,6] is sorted
      - if target is not in [4,5,6], we just assume it might
        be in [7,0,1,2]
      - we break it into two subarrays
        [7,0,1,2] -> [7,0] and [1,2]
        - [1,2] is sorted
      - check if target is in [1,2]
      - ...

*/

int Solution::search(vector<int> &nums, int target)
{
  int n = nums.size();
  auto l = 0, r = n - 1;

  while (l <= r)
  {
    auto mid = l + (r - l) / 2;

    if (nums[mid] == target)
      return mid;
    /* left subarray is sorted
       - check question 153 for more detailed
         explanation
    */
    if (nums[l] < nums[mid])
    {
      /* take the advantage that the subarray is sorted */
      if (nums[l] <= target && target < nums[mid])
        r = mid - 1;
      /* target might be in the right subarray  */
      else
        l = mid + 1;
    }
    /* right subarray is sorted */
    else
    {
      if (nums[mid] < target && target <= nums[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
  }

  return -1;
}
