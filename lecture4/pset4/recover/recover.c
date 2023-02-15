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

    int count = 0;

    char filename[10];


    while (fread(&buffer, 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", count);
            FILE *img = fopen(filename, "w");
            fwrite(&buffer, 1, BLOCK_SIZE, img);
            fclose(img);
            count++;
        }

    }

    fclose(f);
    

//     fread(headbytes, sizeof(BYTE), 3, f);

 
    //TODO 
    //Abrir o cartão de memoria
    //Olhar para o inicio e procurar um jpeg
    //quando achar o jpeg, abrir um novo arquivo jpeg
    //escrever em blocos de 512 bytes até encontrar um novo jpeg 
    //quando achar o jpeg, fecha o antigo e abre um novo arquivo // recursão aqui
    
}
