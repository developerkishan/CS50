#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0;i <height;i++)
    {
        for(int j = 0; j<width;j++)

        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = red+green+blue;
            average = round(average/3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen= average;


        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
            for(int i =0;i <height;i++)
            {
                for(int j = 0; j<width;j++)

                {
                    int originalRed = image[i][j].rgbtRed;
                    int originalGreen = image[i][j].rgbtGreen;
                    int originalBlue = image[i][j].rgbtBlue;
                    int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
                    int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
                    int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

                    if (sepiaRed >255)
                        image[i][j].rgbtRed = 255;
                    else
                        image[i][j].rgbtRed = sepiaRed;

                    if (sepiaGreen >255)
                        image[i][j].rgbtGreen = 255;
                    else
                        image[i][j].rgbtGreen = sepiaGreen;

                    if (sepiaBlue >255)
                        image[i][j].rgbtBlue = 255;
                    else
                        image[i][j].rgbtBlue = sepiaBlue;

                }
            }

            return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Swap pixels
            if(j < width/2){
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][width-j-1].rgbtRed = red;
            image[i][width-j-1].rgbtGreen = green;
            image[i][width-j-1].rgbtBlue= blue;
            }


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
