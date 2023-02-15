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
    
    BYTE headbytes[3];

    int count = 1;

    //aqui tem que ser um laço de repetição que corre pelo arquivo
    while (fread(&headbytes, 3 * sizeof(BYTE), 1, f))
    {
        if (headbytes[0] == 0xff && headbytes[1] == 0xd8 && headbytes[2] == 0xff)
        {
            //fopen e blá blá
            printf("achei %i jpeg", count);
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
