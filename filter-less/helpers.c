#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
        //take average of red, green and blue
        float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
        int rounded = round(average);
        //Update pixel values
        image[i][j].rgbtRed = rounded;
        image[i][j].rgbtGreen = rounded;
        image[i][j].rgbtBlue = rounded;
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
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 *  image[i][j].rgbtBlue;
            float sepiaBlue = .272 *image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

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
            image[i][j].rgbtRed = SR;
            image[i][j].rgbtGreen = SG;
            image[i][j].rgbtBlue = SB;
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
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
            //corner, 4 values
            int sumcornerltred = copy[0][0].rgbtRed + copy[0][1].rgbtRed + copy[1][0].rgbtRed + copy[1][1].rgbtRed;
            image[0][0].rgbtRed = (sumcornerltred) / 4;
            int sumcornerltgreen = copy[0][0].rgbtGreen + copy[0][1].rgbtGreen + copy[1][0].rgbtGreen + copy[1][1].rgbtGreen;
            image[0][0].rgbtGreen = (sumcornerltgreen) / 4;
            int sumcornerltblue = copy[0][0].rgbtBlue + copy[0][1].rgbtBlue + copy[1][0].rgbtBlue + copy[1][1].rgbtBlue;
            image[0][0].rgbtBlue = (sumcornerltblue) / 4;

            int sumcornerlbred = copy[height - 1][0].rgbtRed + copy[height - 2][0].rgbtRed + copy[height - 1][1].rgbtRed + copy[height - 2][1].rgbtRed;
            image[height - 1][0].rgbtRed = (sumcornerlbred) / 4;
            int sumcornerlbgreen = copy[height - 1][0].rgbtGreen + copy[height - 2][0].rgbtGreen + copy[height - 1][1].rgbtGreen + copy[height - 2][1].rgbtGreen;
            image[height - 1][0].rgbtGreen = (sumcornerlbgreen) / 4;
            int sumcornerlbblue = copy[height - 1][0].rgbtBlue + copy[height - 2][0].rgbtBlue + copy[height - 1][1].rgbtBlue + copy[height - 2][1].rgbtBlue;
            image[height - 1][0].rgbtBlue = (sumcornerlbblue) / 4;

            int sumcornerrtred = copy[0][width - 1].rgbtRed + copy[0][width - 2].rgbtRed + copy[1][width - 2].rgbtRed + copy[1][width - 1].rgbtRed;
            image[0][width - 1].rgbtRed = (sumcornerrtred) / 4;
            int sumcornerrtgreen = copy[0][width - 1].rgbtGreen + copy[0][width - 2].rgbtGreen + copy[1][width - 2].rgbtGreen + copy[1][width - 1].rgbtGreen;
            image[0][width - 1].rgbtGreen = (sumcornerrtgreen) / 4;
            int sumcornerrtblue = copy[0][width - 1].rgbtBlue + copy[0][width - 2].rgbtBlue + copy[1][width - 2].rgbtBlue + copy[1][width - 1].rgbtBlue;
            image[0][width - 1].rgbtBlue = (sumcornerrtblue) / 4;

            int sumcornerrbred = copy[height - 1][width - 1].rgbtRed + copy[height - 1][width - 2].rgbtRed + copy[height - 2][width - 2].rgbtRed + copy[height - 2][width - 1].rgbtRed;
            image[height - 1][width - 1].rgbtRed = (sumcornerrbred) / 4;
            int sumcornerrbgreen = copy[height - 1][width - 1].rgbtGreen + copy[height - 1][width - 2].rgbtGreen + copy[height - 2][width - 2].rgbtGreen + copy[height - 2][width - 1].rgbtGreen;
            image[height - 1][width - 1].rgbtGreen = (sumcornerrbgreen) /4;
            int sumcornerrbblue = copy[height - 1][width - 1].rgbtBlue + copy[height - 1][width - 2].rgbtBlue + copy[height - 2][width - 2].rgbtBlue + copy[height - 2][width - 1].rgbtBlue;
            image[height - 1][width - 1].rgbtBlue = (sumcornerrbblue) /4;
        }
    }

            //edge, 6 values

            //first row
            for(int j = 1; j < width - 1; j++)
            {
                int sumr = 0;
                int sumg = 0;
                int sumb = 0;
                for(int i = 0; i <= 1; i++)
                {
                    for(int x = j - 1; x <= j + 1; x++)
                    {
                        sumr += copy[i][x].rgbtRed;
                        sumg += copy[i][x].rgbtGreen;
                        sumb += copy[i][x].rgbtBlue;
                    }
                }
                image[0][j].rgbtRed = sumr / 6;
                image[0][j].rgbtGreen = sumg / 6;
                image[0][j].rgbtBlue = sumb / 6;
            }

            //last row
            for(int j = 1; j < width - 1; j++)
            {
                int sumr = 0;
                int sumg = 0;
                int sumb = 0;
                for(int i = height - 2; i <= height - 1; i++)
                {
                    for(int x = j - 1; x <= j + 1; x++)
                    {
                        sumr += copy[i][x].rgbtRed;
                        sumg += copy[i][x].rgbtGreen;
                        sumb += copy[i][x].rgbtBlue;
                    }
                }
                image[height - 1][j].rgbtRed = sumr / 6;
                image[height - 1][j].rgbtGreen = sumg / 6;
                image[height - 1][j].rgbtBlue = sumb / 6;
            }

            //first column
            for(int i = 1; i <= height - 2; i++)
            {
                int sumr = 0;
                int sumg = 0;
                int sumb = 0;
                for(int j = 0; j <= 1; j++)
                {
                    for(int x = i - 1; x <= i + 1; x++)
                    {
                        sumr += copy[x][j].rgbtRed;
                        sumg += copy[x][j].rgbtGreen;
                        sumb += copy[x][j].rgbtBlue;
                    }
                }
                image[i][0].rgbtRed = sumr / 6;
                image[i][0].rgbtGreen = sumg / 6;
                image[i][0].rgbtBlue = sumb / 6;
            }

            //last column
            for(int i = 1; i <= height - 2; i++)
            {
                int sumr = 0;
                int sumg = 0;
                int sumb = 0;
                for(int j = width - 2; j <= width - 1; j++)
                {
                    for(int x = i - 1; x <= i + 1; x++)
                    {
                        sumr += copy[x][j].rgbtRed;
                        sumg += copy[x][j].rgbtGreen;
                        sumb += copy[x][j].rgbtBlue;
                    }
                }
                image[i][width - 1].rgbtRed = sumr / 6;
                image[i][width - 1].rgbtGreen = sumg / 6;
                image[i][width - 1].rgbtBlue = sumb / 6;
            }









            //middle, 9 values
}
return;


