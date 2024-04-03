/*

1512. Number of Good Pairs


Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.



Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.


Solution:
This problem can be solved with the help of a hashmap

A hashmap can store the frequency of times each number is present within the array


A pair is only valid if the first coordinate is less than the second,
meaning each set is unique

if we come across the number 5 two times, {5,5}

then the total amount of pairs that can be made is 1, {0,1}

so for 2 occurences of 5 we have 1 pair

at 3 occurences, {5,5,5}

We already know that 2 5's gives us 1 pair, adding another 5 which 
gives us a total of 3 occurences(frequency)

so we add the 1 pair we have, plus the number of occurences, minus 1 because
for every occurence we can have o-1 pairs 

in our case, 1 pair (from 5,5) and 3 occurences - 1 (2) gives us 3 pairs possible

we can use this logic for all elements within the array and add the sum to get our answer



*/


#include <iostream>
#include <unordered_map>


class Solution {
public:
	int numIdenticalPairs(std::vector<int>& nums);
};



int Solution::numIdenticalPairs(std::vector<int>& nums) {
//We need to create an empty hash map that will store the frequency of each element visted within the array
//A hash map holds a key:value pair. Our "key" will be the element visted within the nums array
//the value will be the frequency that number is present within the array
	std::unordered_map<int, int> number_frequency;

//Next we need to store a counter for the good pairs that we find within the hash map
//We will initialize this value to 0 since we start off with no good pairs
	int goodPairs = 0;

//To add the sum of good pairs its: goodpairs(total amount) + frequency of element - 1 (minus 1 because if 5 has a frequency of 3, it can only have 2 pairs i.e, 3-1 = 2pairs)
//This is done to every element within the array to get the total number of good pairs
//We can create a for loop to iterate through the size of nums

	for (int i = 0; i < nums.size(); i++) {

		//At each iteration we want to increment the frequency by 1
		number_frequency[nums[i]]++;

		//After incrementing we then want to add the total amount of good pairs + the frequency of the elemnent - 1 
		//to represent the total amount of pairs possible
		goodPairs = goodPairs + number_frequency[nums[i]] - 1;
	}

	//After iterating through the for loop we should be left with the total amount of good pairs
	//within nums, so we can return good pairs


	return goodPairs;
}




int main() {

	Solution solution;

	std::vector<int> nums = { 1,2,3,1,1,3 };
	std::vector<int> nums2 = { 1,1,1,1 };
	std::vector<int> nums3 = { 1,2,3 };

	std::cout << solution.numIdenticalPairs(nums);


	//Time complexity: We are using one for loop so O(n)
	//Space complexity: O(n) the hashmap stores the frequency of each number in the array
	//Total time spent 1:15h
	

	return 0;
}