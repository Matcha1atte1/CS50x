#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
        //take average of red, green and blue
        float average = (image[i][j].rgbtred + image[i][j].rgbtgreen + image[i][j].rgbtblue) / 3.0;
        int rounded = round(average);
        //Update pixel values
        image[i][j].rgbtred = rounded;
        image[i][j].rgbtgreen = rounded;
        image[i][j].rgbtblue = rounded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop over all pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //Compute sepia values
            float sepiaRed = .393 * image[i][j].rbgtred + .769 * image[i][j].rgbtgreen + .189 * image[i][j].rgbtblue;
            float sepiaGreen = .349 * image[i][j].rbgtred + .686 * image[i][j].rgbtgreen + .168 *  image[i][j].rgbtblue;
            float sepiaBlue = .272 *image[i][j].rbgtred + .534 * image[i][j].rgbtgreen + .131 * image[i][j].rgbtblue;

            int SR = round(sepiaRed);
            int SG = round(sepiaGreen);
            int SB = round(sepiaBlue);
            if(SR > 255)
            {
                SR = 255;
            }
            if(SG > 255)
            {
                SG = 255;
            }
            if(SB > 255)
            {
                SB = 255;
            }

            //Update pixel with sepia values
            image[i][j].rgbtred = SR;
            image[i][j].rgbtgreen = SG;
            image[i][j].rgbtblue = SB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //swap pixels
            RGBTRIPLE temp = *image[i][j]
            

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
