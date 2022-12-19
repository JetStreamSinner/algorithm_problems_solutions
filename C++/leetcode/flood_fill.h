#pragma once

// https://leetcode.com/problems/flood-fill
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from
// the pixel image[sr][sc]. To perform a flood fill, consider the starting pixel, plus any pixels connected
// 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected
// 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the
// aforementioned pixels with color.
// Return the modified image after performing the flood fill.

class Solution {
public:

    struct Pixel {
        int32_t ri;
        int32_t ci;
        int32_t previous_color;

        explicit Pixel(int32_t r, int32_t c, int32_t clr) : ri(r), ci(c), previous_color(clr) {

        }
    };

    std::vector<std::vector<int32_t>> floodFill(std::vector<std::vector<int32_t>>& image, int32_t sr, int32_t sc, int32_t color) {
        std::stack<Pixel> pixels;
        Pixel start_pixel(sr, sc, image.at(sr).at(sc));

        if (start_pixel.previous_color == color) {
            return image;
        }

        pixels.push(start_pixel);

        while (!pixels.empty()) {
            Pixel pixel = pixels.top();
            pixels.pop();

            if (pixel.ri < 0 || pixel.ri >= image.size() || pixel.ci < 0 || pixel.ci >= image.at(0).size()) {
                continue;
            }

            if (image.at(pixel.ri).at(pixel.ci) != pixel.previous_color) {
                continue;
            }

            Pixel top_pixel(pixel.ri - 1, pixel.ci, image.at(pixel.ri).at(pixel.ci));
            Pixel bottom_pixel(pixel.ri + 1, pixel.ci, image.at(pixel.ri).at(pixel.ci));
            Pixel right_pixel(pixel.ri, pixel.ci + 1, image.at(pixel.ri).at(pixel.ci));
            Pixel left_pixel(pixel.ri, pixel.ci - 1, image.at(pixel.ri).at(pixel.ci));

            image.at(pixel.ri).at(pixel.ci) = color;

            pixels.push(top_pixel);
            pixels.push(bottom_pixel);
            pixels.push(right_pixel);
            pixels.push(left_pixel);
        }
        return image;
    }
};
