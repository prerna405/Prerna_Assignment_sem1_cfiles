/*
 * Problem Name          : Container With Most Water
 * LeetCode Problem No.  : 11
 * Topic                 : ARRAYS
 * Problem Link          : https://leetcode.com/problems/container-with-most-water/
 *
 * Problem Description:
 * Given an integer array height of length n, where each
 * element represents the height of a vertical line positioned
 * at its corresponding index, determine the maximum amount
 * of water that can be stored between any two vertical lines.
 *
 * The container is formed by selecting two lines, with its
 * capacity determined by the shorter line and the horizontal
 * distance between them.
 *
 * The solution must find the maximum possible water capacity
 * without tilting the container.
 */

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int minHeight;

        if (height[left] < height[right])
            minHeight = height[left];
        else
            minHeight = height[right];

        int width = right - left;
        int area = minHeight * width;

        if (area > maxWater) {
            maxWater = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}
