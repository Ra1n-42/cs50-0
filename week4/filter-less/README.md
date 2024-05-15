# Problem to Solve: Image Filtering
![Yard Grayscale](https://cs50.harvard.edu/x/2024/psets/4/filter/less/yard-grayscale.bmp)

## Introduction

Images can be represented as grids of pixels, each pixel containing information about its color. For black-and-white images, a single bit suffices per pixel, with 0 representing black and 1 representing white. More colorful images require more bits per pixel, such as the commonly used 24-bit color format, which uses 8 bits each for red, green, and blue (RGB) components.

In this problem, you'll be working with 24-bit BMP (Bitmap) images. These images consist of sequences of bits, with each group of 24 bits representing the color of a pixel. The color of each pixel is determined by the amount of red, green, and blue present, commonly known as RGB color.

## Technical Background

A 24-bit BMP file contains metadata in the form of headers, followed by the bitmap data representing the image. The metadata includes information like the image's height and width. The bitmap data consists of bytes, with each triplet of bytes representing a pixel's color. Notably, BMP files store colors as BGR (blue, green, red) instead of RGB.

## Image Filtering

Filtering an image involves modifying each pixel to create a specific effect in the resulting image. This modification can include adjustments to color, brightness, contrast, or applying various visual effects.

## Task

Your task is to write a program in a file named `helpers.c` in a folder called `filter-less` to apply filters to BMP images. These filters will manipulate the RGB values of individual pixels, allowing you to create custom image effects.

## Conclusion

Understanding image representation and manipulation is crucial for various applications, including digital image processing, computer graphics, and multimedia systems. By completing this task, you'll gain practical experience in working with image data and applying filters to achieve desired visual effects.

Good luck with implementing your image filters!
