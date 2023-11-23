#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width; column++)
        {
            int gray_scale = round(0.299 * image[row][column].rgbtRed + 
                             0.587 * image[row][column].rgbtGreen + 
                             0.114 * image[row][column].rgbtBlue);

            image[row][column].rgbtRed = gray_scale;
            image[row][column].rgbtGreen = gray_scale;
            image[row][column].rgbtBlue = gray_scale;

        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width / 2; column++)
        {
            RGBTRIPLE temp = image[row][column];
            image[row][column] = image[row][width - 1 - column];
            image[row][width - 1 - column] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
{
    for (int column = 0; column < width; column++)
    {

        float sumRed = 0.0;
        float sumGreen = 0.0;
        float sumBlue = 0.0;
        
        int validNeighbors = 0;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int neighborRow = row + i;
                int neighborColumn = column + j;

                if (neighborRow >= 0 && neighborRow < height && neighborColumn >= 0 && neighborColumn < width)
                {
                    sumRed += image[neighborRow][neighborColumn].rgbtRed;
                    sumGreen += image[neighborRow][neighborColumn].rgbtGreen;
                    sumBlue += image[neighborRow][neighborColumn].rgbtBlue;
                    validNeighbors++;
                }
            }
        }


        if (validNeighbors > 0)
        {

            image[row][column].rgbtRed = round(sumRed / validNeighbors);
            image[row][column].rgbtGreen = round(sumGreen / validNeighbors);
            image[row][column].rgbtBlue = round(sumBlue / validNeighbors);
        }
        else
        {

            image[row][column].rgbtRed = image[row][column].rgbtRed;
            image[row][column].rgbtGreen = image[row][column].rgbtGreen;
            image[row][column].rgbtBlue = image[row][column].rgbtBlue;
        }
    }
}

    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int GxRed = -temp[i - 1][j - 1].rgbtRed - 2 * temp[i - 1][j].rgbtRed - temp[i - 1][j + 1].rgbtRed +
                         temp[i + 1][j - 1].rgbtRed + 2 * temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed;

            int GyRed = -temp[i - 1][j - 1].rgbtRed - 2 * temp[i][j - 1].rgbtRed - temp[i + 1][j - 1].rgbtRed +
                         temp[i - 1][j + 1].rgbtRed + 2 * temp[i][j + 1].rgbtRed + temp[i + 1][j + 1].rgbtRed;

            int magnitudeRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));

            image[i][j].rgbtRed = fmin(255, fmax(0, magnitudeRed));

            int GxGreen = -temp[i - 1][j - 1].rgbtGreen - 2 * temp[i - 1][j].rgbtGreen - temp[i - 1][j + 1].rgbtGreen +
                           temp[i + 1][j - 1].rgbtGreen + 2 * temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen;

            int GyGreen = -temp[i - 1][j - 1].rgbtGreen - 2 * temp[i][j - 1].rgbtGreen - temp[i + 1][j - 1].rgbtGreen +
                           temp[i - 1][j + 1].rgbtGreen + 2 * temp[i][j + 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen;

            int magnitudeGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            image[i][j].rgbtGreen = fmin(255, fmax(0, magnitudeGreen));

            int GxBlue = -temp[i - 1][j - 1].rgbtBlue - 2 * temp[i - 1][j].rgbtBlue - temp[i - 1][j + 1].rgbtBlue +
                          temp[i + 1][j - 1].rgbtBlue + 2 * temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue;

            int GyBlue = -temp[i - 1][j - 1].rgbtBlue - 2 * temp[i][j - 1].rgbtBlue - temp[i + 1][j - 1].rgbtBlue +
                          temp[i - 1][j + 1].rgbtBlue + 2 * temp[i][j + 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue;

            int magnitudeBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));
            image[i][j].rgbtBlue = fmin(255, fmax(0, magnitudeBlue));
        }
    }

    return;
}
