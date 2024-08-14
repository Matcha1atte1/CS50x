#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        //take average of red, green and blue
        float average = (image[i][j].rgbtred + image[i][j].rgbtgreen + image[i][j].rgbtblue) / 3.0

    }



    //Update pixel values
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
