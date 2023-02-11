#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int res = round(average);
            image[i][j].rgbtRed = res;
            image[i][j].rgbtGreen = res;
            image[i][j].rgbtBlue = res;
        }
    }
    return;
}

int nMax(int x)
{
    if (x > 255)
        return 255;
    else
        return x;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRED = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            int red = nMax(round(sepiaRED));
            int green = nMax(round(sepiaGreen));
            int blue = nMax(round(sepiaBlue));

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffimage[i][j].rgbtRed = image[i][j].rgbtRed;
            buffimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            buffimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        int last = width;
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffimage[i][last].rgbtRed;
            image[i][j].rgbtGreen = buffimage[i][last].rgbtGreen;
            image[i][j].rgbtBlue = buffimage[i][last].rgbtBlue;
            last--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
