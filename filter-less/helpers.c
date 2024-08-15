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
        for(int j = 0; j < width / 2; j++)
        {
            //swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
            //corner, 4 values
            int sumcornerltred = copy[i][j].rgbtred + copy[i][j + 1].rgbtred + copy[i + 1][j].rgbtred + copy[i + 1][j + 1].rgbtred;
            image[i][j].rgbtred = (sumcornerltred) / 4;
            int sumcornerltgreen = copy[i][j].rgbtgreen + copy[i][j + 1].rgbtgreen + copy[i + 1][j].rgbtgreen + copy[i + 1][j + 1].rgbtgreen;
            image[i][j].rgbtgreen = (sumcornerltgreen) / 4;
            int sumcornerltblue = copy[i][j].rgbtblue + copy[i][j + 1].rgbtblue + copy[i + 1][j].rgbtblue + copy[i + 1][j + 1].rgbtblue;
            image[i][j].rgbtblue = (sumcornerltblue) / 4;

            int sumcornerlbred = copy[width - i][j].rgbtred + copy[width - i - 1][j].rgbtred + copy[width - i][j + 1].rgbtred + copy[width - i - 1][j + 1];

            //edge, 6 values
            int sumedgered = copy[i][j + 1].rgbtred +


            //middle, 9 values
        }
    }
    return;
}
