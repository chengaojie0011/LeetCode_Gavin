// Source : https://leetcode-cn.com/problems/two-sum/description/
// Author : Gaojie Chen
// Date   : 2018-10-22



#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;


//第一遍解法（暴力解法）
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		for (int i = 0; i<nums.size(); i++) {
			for (int j = i + 1; j<nums.size(); j++) {
				int sum = nums[i] + nums[j];
				if (sum == target) {
					res.push_back(i);
					res.push_back(j);
					break;
				}
			}
		}
		return res;
	}
};


//第二遍解法（哈希表）
// Time Complexity: O(n)
// Space Complexity: O(n)...
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			hash[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int j = target - nums[i];
			if (hash.count(j) && hash[j] != i) {
				res.push_back(i);
				res.push_back(hash[j]);
				break;
			}
		}
		return res;
	}
};

