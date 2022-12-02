#pragma once

// https://leetcode.com/problems/guess-number-higher-or-lower/
// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
//
// You call a pre-defined API int guess(int num), which returns three possible results:
// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.
//
// Example 1:
// Input: n = 10, pick = 6
// Output: 6
//
// Example 2:
// Input: n = 1, pick = 1
// Output: 1
//
// Example 3:
// Input: n = 2, pick = 1
// Output: 1

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;

        const int correct_guess = 0;
        const int greater_than_guess = -1;
        const int lesser_than_guess = 1;

        int result = 0;

        while (left <= right) {
            long long middle = (left + right) / 2;
            const int guess_result = guess(middle);

            if (guess_result == correct_guess) {
                result = middle;
                break;
            } else if (guess_result == lesser_than_guess) {
                left = middle;
                left++;
            } else if (guess_result == greater_than_guess) {
                right = middle;
                right--;
            }
        }
        return result;
    }
};
