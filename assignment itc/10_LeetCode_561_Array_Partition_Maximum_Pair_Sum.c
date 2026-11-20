/*
 * Problem Name          : Array Partition
 * LeetCode Problem No.  : 561
 * Topic                 : ARRAYS
 * Problem Link          : https://leetcode.com/problems/array-partition/
 *
 * Problem Description:
 * Given an integer array nums containing 2n elements,
 * divide the array into n pairs such that the sum of
 * the minimum values from each pair is maximized.
 *
 * Each element must belong to exactly one pair, and
 * every pair must contain two distinct array elements.
 *
 * The solution sorts the array in ascending order and
 * groups adjacent elements into pairs.
 *
 * By selecting the elements at even indices after sorting,
 * the maximum possible sum of pair minimums is obtained.
 *
 * Return the maximum sum achievable through this pairing.
 */

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int sum = 0;

    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}
