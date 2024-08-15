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
            int sumcornerltred = copy[0][0].rgbtred + copy[0][1].rgbtred + copy[1][0].rgbtred + copy[1][1].rgbtred;
            image[0][0].rgbtred = (sumcornerltred) / 4;
            int sumcornerltgreen = copy[0][0].rgbtgreen + copy[0][1].rgbtgreen + copy[1][0].rgbtgreen + copy[1][1].rgbtgreen;
            image[0][0].rgbtgreen = (sumcornerltgreen) / 4;
            int sumcornerltblue = copy[0][0].rgbtblue + copy[0][1].rgbtblue + copy[1][0].rgbtblue + copy[1][1].rgbtblue;
            image[0][0].rgbtblue = (sumcornerltblue) / 4;

            int sumcornerlbred = copy[height - 1][0].rgbtred + copy[height - 2][0].rgbtred + copy[height - 1][1].rgbtred + copy[height - 2][1].rgbtred;
            image[height - 1][0].rgbtred = (sumcornerlbred) / 4;
            int sumcornerlbgreen = copy[height - 1][0].rgbtgreen + copy[height - 2][0].rgbtgreen + copy[height - 1][1].rgbtgreen + copy[height - 2][1].rgbtgreen;
            image[height - 1][0].rgbtgreen = (sumcornerlbgreen) / 4;
            int sumcornerlbblue = copy[height - 1][0].rgbtblue + copy[height - 2][0].rgbtblue + copy[height - 1][1].rgbtblue + copy[height - 2][1].rgbtblue;
            image[height - 1][0].rgbtblue = (sumcornerlbblue) / 4;

            int sumcornerrtred = copy[0][width - 1].rgbtred + copy[0][width - 2].rgbtred + copy[1][width - 2].rgbtred + copy[1][width - 1].rgbtred;
            image[0][width - 1].rgbtred = (sumcornerrtred) / 4;
            int sumcornerrtgreen = 

            //edge, 6 values



            //middle, 9 values
        }
    }
    return;
}
