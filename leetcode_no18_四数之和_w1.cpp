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

	for (int fir = 0; fir < length; fir++)
	{
		if (fir > 0 && nums[fir] == nums[fir - 1])									/*	确保第一个数和上次取的数不相同	*/
		{
			continue;
		}


		for (int sec = fir + 1; sec < length; sec++)
		{
			if (sec > fir + 1 && nums[sec] == nums[sec - 1])						/*	当sec==fir+1的时候就不用判断nums[sec]和nums[sec-1]是否相同了，只有sec>fir+1的时候才要判断	*/
			{
				continue;
			}


			for (int thi = sec + 1; thi < length; thi++)
			{
				if (thi > sec + 1 && nums[thi] == nums[thi - 1])
				{
					continue;
				}


				int fou = length - 1;
				int goal = target - nums[fir] - nums[sec];

				while (thi < fou && nums[thi] + nums[fou] > goal)						/*	当sec==thi或者nums[sec]+nums[thi]<=-nums[fir]的时候退出循环	*/
				{																		/*	将thi倒着递减来不断缩小和减少程序运算步骤	*/
					fou--;
				}

				if (thi == fou)
				{
					break;
				}
				if (nums[thi] + nums[fou] == goal)
				{
					result.push_back({ nums[fir],nums[sec],nums[thi],nums[fou] });
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