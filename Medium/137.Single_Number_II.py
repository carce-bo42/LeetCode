# https://leetcode.com/problems/single-number-ii/description/

from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return int((3 * sum(set(nums)) - sum(nums))/2)