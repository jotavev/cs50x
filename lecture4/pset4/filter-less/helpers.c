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
    {
        return 255;
    }
    else
    {
        return x;
    }
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
    for (int i = 0; i <= height; i++)
    {
        int count = 1;
        for (int j = 0; j <= width; j++)
        {
            image[i][j].rgbtRed = buffimage[i][width - count].rgbtRed;
            image[i][j].rgbtGreen = buffimage[i][width - count].rgbtGreen;
            image[i][j].rgbtBlue = buffimage[i][width - count].rgbtBlue;
            count++;
        }
    }
    return;
}

int average4(int n0, int n1, int n2, int n3)
{
    return round((n0 + n1 + n2 + n3) / 4.0);
}
int average6(int n0, int n1, int n2, int n3, int n4, int n5)
{
    return round((n0 + n1 + n2 + n3 + n4 + n5) / 6.0);
}
int average9(int n0, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8)
{
    return round((n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8) / 9.0);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buff[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buff[i][j].rgbtRed = image[i][j].rgbtRed;
            buff[i][j].rgbtGreen = image[i][j].rgbtGreen;
            buff[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            //canto superior esquerdo
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = average4(
                                          buff[i][j].rgbtRed, 
                                          buff[i][j + 1].rgbtRed, 
                                          buff[i + 1][j].rgbtRed, 
                                          buff[i + 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average4(
                                            buff[i][j].rgbtGreen, 
                                            buff[i][j + 1].rgbtGreen, 
                                            buff[i + 1][j].rgbtGreen, 
                                            buff[i + 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average4(
                                           buff[i][j].rgbtBlue, 
                                           buff[i][j + 1].rgbtBlue, 
                                           buff[i + 1][j].rgbtBlue, 
                                           buff[i + 1][j + 1].rgbtBlue);
            }
            //canto superior direito
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = average4(
                                          buff[i][j - 1].rgbtRed, 
                                          buff[i][j].rgbtRed, 
                                          buff[i + 1][j - 1].rgbtRed, 
                                          buff[i + 1][j].rgbtRed);

                image[i][j].rgbtGreen = average4(
                                            buff[i][j - 1].rgbtGreen, 
                                            buff[i][j].rgbtGreen, 
                                            buff[i + 1][j - 1].rgbtGreen, 
                                            buff[i + 1][j].rgbtGreen);

                image[i][j].rgbtBlue = average4(
                                           buff[i][j - 1].rgbtBlue, 
                                           buff[i][j].rgbtBlue, 
                                           buff[i + 1][j - 1].rgbtBlue, 
                                           buff[i + 1][j].rgbtBlue);
            }
            //canto inferior esquerdo
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = average4(
                                          buff[i][j].rgbtRed, 
                                          buff[i][j + 1].rgbtRed, 
                                          buff[i - 1][j].rgbtRed, 
                                          buff[i - 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average4(
                                            buff[i][j].rgbtGreen, 
                                            buff[i][j + 1].rgbtGreen, 
                                            buff[i - 1][j].rgbtGreen, 
                                            buff[i - 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average4(
                                           buff[i][j].rgbtBlue, 
                                           buff[i][j + 1].rgbtBlue, 
                                           buff[i - 1][j].rgbtBlue, 
                                           buff[i - 1][j + 1].rgbtBlue);
            }
            //canto inferior direito
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = average4(
                                          buff[i][j].rgbtRed, 
                                          buff[i][j - 1].rgbtRed, 
                                          buff[i - 1][j].rgbtRed, 
                                          buff[i - 1][j - 1].rgbtRed);

                image[i][j].rgbtBlue = average4(
                                           buff[i][j].rgbtBlue, 
                                           buff[i][j - 1].rgbtBlue, 
                                           buff[i - 1][j].rgbtBlue, 
                                           buff[i - 1][j - 1].rgbtBlue);

                image[i][j].rgbtGreen = average4(
                                            buff[i][j].rgbtGreen, 
                                            buff[i][j - 1].rgbtGreen, 
                                            buff[i - 1][j].rgbtGreen, 
                                            buff[i - 1][j - 1].rgbtGreen);

            }
            //borda superior
            else if (i == 0 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = average6(
                                          buff[i][j].rgbtRed,
                                          buff[i][j - 1].rgbtRed,
                                          buff[i][j + 1].rgbtRed,
                                          buff[i + 1][j - 1].rgbtRed,
                                          buff[i + 1][j].rgbtRed,
                                          buff[i + 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average6(
                                            buff[i][j].rgbtGreen,
                                            buff[i][j - 1].rgbtGreen,
                                            buff[i][j + 1].rgbtGreen,
                                            buff[i + 1][j - 1].rgbtGreen,
                                            buff[i + 1][j].rgbtGreen,
                                            buff[i + 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average6(
                                           buff[i][j].rgbtBlue,
                                           buff[i][j - 1].rgbtBlue,
                                           buff[i][j + 1].rgbtBlue,
                                           buff[i + 1][j - 1].rgbtBlue,
                                           buff[i + 1][j].rgbtBlue,
                                           buff[i + 1][j + 1].rgbtBlue);
            }
            //borda inferior
            else if (i == height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = average6(
                                          buff[i][j].rgbtRed,
                                          buff[i][j - 1].rgbtRed,
                                          buff[i][j + 1].rgbtRed,
                                          buff[i - 1][j - 1].rgbtRed,
                                          buff[i - 1][j].rgbtRed,
                                          buff[i - 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average6(
                                            buff[i][j].rgbtGreen,
                                            buff[i][j - 1].rgbtGreen,
                                            buff[i][j + 1].rgbtGreen,
                                            buff[i - 1][j - 1].rgbtGreen,
                                            buff[i - 1][j].rgbtGreen,
                                            buff[i - 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average6(
                                           buff[i][j].rgbtBlue,
                                           buff[i][j - 1].rgbtBlue,
                                           buff[i][j + 1].rgbtBlue,
                                           buff[i - 1][j - 1].rgbtBlue,
                                           buff[i - 1][j].rgbtBlue,
                                           buff[i - 1][j + 1].rgbtBlue);
            }
            //borda esquerda
            else if (j == 0 && i > 0 && i < height - 1)
            {
                image[i][j].rgbtRed = average6(
                                          buff[i][j].rgbtRed,
                                          buff[i][j + 1].rgbtRed,
                                          buff[i - 1][j].rgbtRed,
                                          buff[i - 1][j + 1].rgbtRed,
                                          buff[i + 1][j].rgbtRed,
                                          buff[i + 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average6(
                                            buff[i][j].rgbtGreen,
                                            buff[i][j + 1].rgbtGreen,
                                            buff[i - 1][j].rgbtGreen,
                                            buff[i - 1][j + 1].rgbtGreen,
                                            buff[i + 1][j].rgbtGreen,
                                            buff[i + 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average6(
                                           buff[i][j].rgbtBlue,
                                           buff[i][j + 1].rgbtBlue,
                                           buff[i - 1][j].rgbtBlue,
                                           buff[i - 1][j + 1].rgbtBlue,
                                           buff[i + 1][j].rgbtBlue,
                                           buff[i + 1][j + 1].rgbtBlue);
            }
            //borda direita
            else if (j == width - 1 && i > 0 && i < height - 1)
            {
                image[i][j].rgbtRed = average6(
                                          buff[i][j].rgbtRed,
                                          buff[i][j - 1].rgbtRed,
                                          buff[i - 1][j - 1].rgbtRed,
                                          buff[i - 1][j].rgbtRed,
                                          buff[i + 1][j - 1].rgbtRed,
                                          buff[i + 1][j].rgbtRed);

                image[i][j].rgbtGreen = average6(
                                            buff[i][j].rgbtGreen,
                                            buff[i][j - 1].rgbtGreen,
                                            buff[i - 1][j - 1].rgbtGreen,
                                            buff[i - 1][j].rgbtGreen,
                                            buff[i + 1][j - 1].rgbtGreen,
                                            buff[i + 1][j].rgbtGreen);

                image[i][j].rgbtBlue = average6(
                                           buff[i][j].rgbtBlue,
                                           buff[i][j - 1].rgbtBlue,
                                           buff[i - 1][j - 1].rgbtBlue,
                                           buff[i - 1][j].rgbtBlue,
                                           buff[i + 1][j - 1].rgbtBlue,
                                           buff[i + 1][j].rgbtBlue);
            }
            else if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
            {
                image[i][j].rgbtRed = average9(
                                          buff[i - 1][j - 1].rgbtRed,
                                          buff[i - 1][j].rgbtRed,
                                          buff[i - 1][j + 1].rgbtRed,
                                          buff[i][j - 1].rgbtRed,
                                          buff[i][j].rgbtRed,
                                          buff[i][j + 1].rgbtRed,
                                          buff[i + 1][j - 1].rgbtRed,
                                          buff[i + 1][j].rgbtRed,
                                          buff[i + 1][j + 1].rgbtRed);

                image[i][j].rgbtGreen = average9(
                                            buff[i - 1][j - 1].rgbtGreen,
                                            buff[i - 1][j].rgbtGreen,
                                            buff[i - 1][j + 1].rgbtGreen,
                                            buff[i][j - 1].rgbtGreen,
                                            buff[i][j].rgbtGreen,
                                            buff[i][j + 1].rgbtGreen,
                                            buff[i + 1][j - 1].rgbtGreen,
                                            buff[i + 1][j].rgbtGreen,
                                            buff[i + 1][j + 1].rgbtGreen);

                image[i][j].rgbtBlue = average9(
                                           buff[i - 1][j - 1].rgbtBlue,
                                           buff[i - 1][j].rgbtBlue,
                                           buff[i - 1][j + 1].rgbtBlue,
                                           buff[i][j - 1].rgbtBlue,
                                           buff[i][j].rgbtBlue,
                                           buff[i][j + 1].rgbtBlue,
                                           buff[i + 1][j - 1].rgbtBlue,
                                           buff[i + 1][j].rgbtBlue,
                                           buff[i + 1][j + 1].rgbtBlue);
            }
        }
    }
    return;
}
