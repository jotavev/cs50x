#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        return 1;
    }
    
    const int BLOCK_SIZE = 512 * sizeof(BYTE);

    BYTE buffer[BLOCK_SIZE];

    int count = -1;

    char filename[10];

    int firstbytefound = 0;


    while (fread(&buffer, 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            count++;
            sprintf(filename, "%03i.jpg", count);
            FILE *img = fopen(filename, "w");
            fwrite(&buffer, 1, BLOCK_SIZE, img);
            fclose(img);
            firstbytefound = 1;
        }
        else if (firstbytefound == 1)
        {
            sprintf(filename, "%03i.jpg", count);
            FILE *img = fopen(filename, "a");
            fwrite(&buffer, 1, BLOCK_SIZE, img);
            fclose(img);
        }


    }

    fclose(f);
}
