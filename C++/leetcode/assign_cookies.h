#pragma once

// https://leetcode.com/problems/assign-cookies/
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
//
// Example 1:
// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.
//
// Example 2:
// Input: g = [1,2], s = [1,2,3]
// Output: 2
// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
// You have 3 cookies and their sizes are big enough to gratify all of the children,
// You need to output 2.

class Solution {
public:

    int32_t findContentChildren(vector<int>& child_greed, vector<int>& cookies_source) {

        std::sort(child_greed.begin(), child_greed.end());
        std::sort(cookies_source.begin(), cookies_source.end());

        auto cookies_forwarder = cookies_source.begin();
        auto child_forwarder = child_greed.begin();

        const auto cookies_end = cookies_source.end();
        const auto child_end = child_greed.end();

        int32_t result = 0;

        while (child_forwarder < child_end && cookies_forwarder < cookies_end) {
            const int32_t child_greed = *child_forwarder;
            const int32_t cookie_weight = *cookies_forwarder;

            if (cookie_weight < child_greed) {
                ++cookies_forwarder;
            } else {
                ++result;
                ++cookies_forwarder;
                ++child_forwarder;
            }

        }

        return result;
    }
};