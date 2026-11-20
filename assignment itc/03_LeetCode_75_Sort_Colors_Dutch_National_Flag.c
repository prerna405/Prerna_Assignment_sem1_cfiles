/*
 * Problem Name          : Sort Colors
 * LeetCode Problem No.  : 75
 * Topic                 : ARRAYS
 * Problem Link          : https://leetcode.com/problems/sort-colors/
 *
 * Problem Description:
 * Given an array containing n elements representing three
 * different colors (red, white, and blue), sort the array
 * in-place so that elements of the same color are grouped
 * together.
 *
 * The colors are represented by integers 0, 1, and 2,
 * corresponding to red, white, and blue respectively.
 *
 * The final arrangement must follow the order red, white,
 * and blue without using an additional sorting array.
 */

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;
    int temp;

    while (mid <= high) {

        if (nums[mid] == 0) {
            temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            low++;
            mid++;
        }

        else if (nums[mid] == 1) {
            mid++;
        }

        else {
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }
}
