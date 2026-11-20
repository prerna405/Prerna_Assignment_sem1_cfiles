/*
 * Problem Name          : Monotonic Array
 * LeetCode Problem No.  : 896
 * Topic                 : ARRAYS
 * Problem Link          : https://leetcode.com/problems/monotonic-array/
 *
 * Problem Description:
 * Given an integer array nums, determine whether the array
 * is monotonic by checking if its elements are arranged in
 * either non-decreasing or non-increasing order.
 *
 * An array is monotone increasing if every element is
 * greater than or equal to the element before it.
 *
 * An array is monotone decreasing if every element is
 * less than or equal to the element before it.
 *
 * Return true if the array satisfies either condition;
 * otherwise, return false.
 */

#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    int increasing = 1;
    int decreasing = 1;

    for (int i = 0; i < numsSize - 1; i++) {

        if (nums[i] > nums[i + 1]) {
            increasing = 0;
        }

        if (nums[i] < nums[i + 1]) {
            decreasing = 0;
        }
    }

    return increasing || decreasing;
}
