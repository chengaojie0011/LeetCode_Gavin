// Source : https://leetcode-cn.com/problems/find-pivot-index/description/
// Author : Gaojie Chen
// Date   : 2018-10-23



#include <stdio.h>
#include <iostream>
#include<numeric>

using namespace std;


//第一遍解法（暴力解法）
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        for(int i=0;i<length;++i) {
            int left=0;
            int right=0;
            for(int j=0;j<i;++j){
                left+=nums[j];
            }
            for(int z=length-1;z>i;--z){
                right+=nums[z];
            }
            if(right==left){
                return i;
            } 
        }  
        return-1;
    }
};


//第二遍解法（总和减去当前值）
// Time Complexity: O(n)
// Space Complexity: O(1)
//注：不能用(sum - nums[i])/2，因为可能不能整除
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
		int cur_sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (2*cur_sum == sum - nums[i]) {
				return i;
			}
			cur_sum += nums[i];
		}
		return -1;
    }
};

