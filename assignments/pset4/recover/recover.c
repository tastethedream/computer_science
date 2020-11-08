#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // was program was executed with 1 cmd line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // can file be opened for reading
    FILE *cardptr = fopen(argv[1], "r");
    if (cardptr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //allocate memory 
    int blocksize = 512;
    BYTE *jpgdata = malloc(blocksize);
    if (jpgdata == NULL)
    {
        printf("Not enough memory.\n");
        return 1;
    }

    // name files
    int filenumber = 0;
    char *filename = malloc(8 * (sizeof(char)));
    FILE *outptr = NULL;

    // search for jpegs
    while (fread(jpgdata, sizeof(BYTE), blocksize, cardptr) == 512)
    {
        for (int i = 0; i < blocksize; i++)
        {
            // look for a jpeg file
            if (jpgdata[i] == 0xff && jpgdata[i + 1] == 0xd8 && jpgdata[i + 2] == 0xff && (jpgdata[i + 3] & 0xf0) == 0xe0)
            {
                // found the first jpeg 
                if (filenumber == 0)
                {
                    // Open new file to write the jpeg data to
                    sprintf(filename, "%03i.jpg", filenumber);
                    outptr = fopen(filename, "a");

                    
                    for (int j = i; j < blocksize; j++)
                    {
                        fwrite(&jpgdata[j], sizeof(BYTE), 1, outptr);
                    }

                    filenumber++;

                    break;
                }

                // found sunsequent jpeg
                else if (filenumber >= 1)
                {
                    // close the previous jpeg file and open a new one
                    fclose(outptr);
                    sprintf(filename, "%03i.jpg", filenumber);

                    outptr = fopen(filename, "a");
                    if (outptr == NULL)
                    {
                        free(jpgdata);
                        fclose(cardptr);
                        printf("Could not create %s.\n", filename);
                        return 1;
                    }

                    //write jpeg data to new file
                    for (int j = i; j < blocksize; j++)
                    {
                        fwrite(&jpgdata[j], sizeof(BYTE), 1, outptr);
                    }

                    filenumber++;
                    
                    break;
                }

            }

            // jpeg not found
            else
            {
                // file found write data to open file
                if (filenumber != 0)
                {

                    fwrite(&jpgdata[i], sizeof(BYTE), 1, outptr);

                }

                // keep searching
                else if (filenumber == 0)
                {
                    continue;
                }
            }
        }
    }
    
    // free memory and close files
    free(jpgdata);
    free(filename);
    fclose(cardptr);
    fclose(outptr);

}
