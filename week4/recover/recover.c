#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open forensic image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Variables to track JPEG file
    FILE *jpeg = NULL;
    char filename[8];
    uint8_t buffer[BLOCK_SIZE];
    int jpeg_count = 0;
    int jpeg_open = 0;

    // Iterate over image blocks
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if open
            if (jpeg_open)
            {
                fclose(jpeg);
                jpeg_open = 0;
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", jpeg_count);
            jpeg = fopen(filename, "w");
            if (jpeg == NULL)
            {
                fclose(file);
                printf("Could not create %s.\n", filename);
                return 1;
            }
            jpeg_open = 1;
            jpeg_count++;
        }

        // Write block to JPEG file if open
        if (jpeg_open)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpeg);
        }
    }

    // Close files
    fclose(jpeg);
    fclose(file);

    return 0;
}
