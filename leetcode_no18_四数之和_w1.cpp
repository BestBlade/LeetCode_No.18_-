/*----------------------------------------------------------------------|
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c 	|
，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。			|
																		|
注意：答案中不可以包含重复的三元组。									|
																		|
																		|
示例：																	|
																		|
给定数组 nums = [-1, 0, 1, 2, -1, -4]，									|
																		|
满足要求的三元组集合为：												|
[																		|
  [-1, 0, 1],															|
  [-1, -1, 2]															|
]																		|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/3sum								|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	排序双指针法
*
*	执行用时：136 ms, 在所有 C++ 提交中击败了19.96%的用户
*	内存消耗：7.3 MB, 在所有 C++ 提交中击败了58.54%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	int length = nums.size();
	vector<vector<int>> result;

	if (nums.size() < 4)
	{
		return result;
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < length - 3; i++)
	{
		if (nums[i] + 3 * nums[i + 1] > target)
		{
			break;
		}
		if (nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target)
		{
			continue;
		}
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		for (int j = i + 1; j < length - 2; j++)
		{
			if (nums[i] + nums[j] + 2 * nums[j + 1] > target)
			{
				break;
			}
			if (nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target)
			{
				continue;
			}
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}

			for (int p = j + 1; p < length - 1; p++)
			{
				if (nums[i] + nums[j] + nums[p]+ nums[p + 1] > target)
				{
					break;
				}
				if (nums[i] + nums[j] + nums[p] + nums[length - 1] < target)
				{
					continue;
				}
				if (p > j + 1 && nums[p] == nums[p - 1])
				{
					continue;
				}

				int q = length - 1;


				while (p < q )															/*	这个while是运行速度的关键	*/
				{
					int sum = nums[i] + nums[j] + nums[p] + nums[q];
					if (sum < target)
					{
						p++;
					}
					else if (sum > target)
					{
						q--;
					}
					else
					{
						result.push_back({ nums[i] , nums[j] , nums[p] , nums[q] });
						int last_p = p;
						int last_q = q;
						while (p < q && nums[last_p] == nums[p])
						{
							p++;
						}
						while (p < q && nums[last_q] == nums[q])
						{
							q--;
						}
					}
				}

			}
		}
		
	}
	return result;
}


int main()
{

	vector<int> nums = { -3, -2, -1, 0, 0, 1, 2, 3 };
	int target = 0;
	
	vector<vector<int>> result;

	result = fourSum(nums, target);

}
