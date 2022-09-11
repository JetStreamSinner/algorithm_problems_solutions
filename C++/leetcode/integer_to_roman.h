#pragma once

// https://leetcode.com/problems/integer-to-roman/
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.
//
//Example 1:
//Input: num = 3
//Output: "III"
//Explanation: 3 is represented as 3 ones.
//
//Example 2:
// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
//
// Example 3:
// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


#include <string>

enum class DigitRank {
    Unit = 0,
    Ten = 1,
    Hundred = 2,
    Thousand
};

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result;

        for (std::size_t index = 0; num != 0; num = num / 10, ++index) {
            int last_digit = num % 10;
            DigitRank rank = typeFromIndex(index);
            std::string target = digitToRoman(last_digit, rank);
            result += target;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    DigitRank typeFromIndex(std::size_t index) {
        switch (index) {
            case 0:
                return DigitRank::Unit;
            case 1:
                return DigitRank::Ten;
            case 2:
                return DigitRank::Hundred;
            case 3:
                return DigitRank::Thousand;
            default:
                throw std::runtime_error("Unsupported digit");
        }
    }

    std::string digitToRoman(int digit, DigitRank type) {
        switch (type) {
            case DigitRank::Unit:
                return mapUnit(digit);
            case DigitRank::Ten:
                return mapTen(digit);
            case DigitRank::Hundred:
                return mapHundred(digit);
            case DigitRank::Thousand:
                return mapThousand(digit);
        }
    }

    std::string mapUnit(int digit) {
        switch (digit) {
            case 1:
                return "I";
            case 2:
                return "II";
            case 3:
                return "III";
            case 4:
                return "VI";
            case 5:
                return "V";
            case 6:
                return "IV";
            case 7:
                return "IIV";
            case 8:
                return "IIIV";
            case 9:
                return "XI";
            case 0:
                return "";
        }
    }

    std::string mapTen(int digit) {
        switch (digit) {
            case 1:
                return "X";
            case 2:
                return "XX";
            case 3:
                return "XXX";
            case 4:
                return "LX";
            case 5:
                return "L";
            case 6:
                return "XL";
            case 7:
                return "XXL";
            case 8:
                return "XXXL";
            case 9:
                return "CX";
            case 0:
                return "";
        }
    }

    std::string mapHundred(int digit) {
        switch (digit) {
            case 1:
                return "C";
            case 2:
                return "CC";
            case 3:
                return "CCC";
            case 4:
                return "DC";
            case 5:
                return "D";
            case 6:
                return "CD";
            case 7:
                return "CCD";
            case 8:
                return "CCCD";
            case 9:
                return "MC";
            case 0:
                return "";
        }
    }

    std::string mapThousand(int digit) {
        switch (digit) {
            case 1:
                return "M";
            case 2:
                return "MM";
            case 3:
                return "MMM";
            case 4:
                return "MMMM";
            case 5:
                return "MMMMM";
            case 6:
                return "MMMMMM";
            case 7:
                return "MMMMMMM";
            case 8:
                return "MMMMMMMM";
            case 9:
                return "MMMMMMMMM";
            case 0:
                return "";
        }
    }
};