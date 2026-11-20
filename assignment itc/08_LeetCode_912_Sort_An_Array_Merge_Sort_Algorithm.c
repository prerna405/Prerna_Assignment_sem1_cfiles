/*
 * Problem Name          : Sort an Array
 * LeetCode Problem No.  : 912
 * Topic                 : ALGORITHMS
 * Problem Link          : https://leetcode.com/problems/sort-an-array/
 *
 * Problem Description:
 * Given an integer array nums, arrange all its elements
 * in ascending order and return the sorted array.
 *
 * The sorting process must correctly handle positive
 * integers, negative integers, and duplicate values.
 *
 * The solution uses the Merge Sort algorithm, which follows
 * the divide-and-conquer approach by recursively dividing
 * the array into smaller subarrays.
 *
 * These subarrays are then merged in sorted order to
 * produce the final ascending sequence.
 */

void merge(int* nums, int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        nums[i] = temp[k];
    }
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    mergeSort(nums, 0, numsSize - 1);

    return nums;
}
