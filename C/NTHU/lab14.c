/*************************************************************************
	> File Name: lib14.c
    > EE231002 Lab16. Image Processing
	> Author: 
	> Mail: 
	> Created Time: 西元2016年01月02日 (週六) 16時12分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef long long int LL;
typedef struct sPIXEL {     // a single pixel
    unsigned char r,g,b;    // three color components
} PIXEL;
typedef struct sIMG {       // an image of PPM style
    char header[3];         // header, either P3 or P6
    int W,H;                // width and height of the image
    int level;              // intensity level of each color component
    PIXEL **PX;             // two-dimensional array for all the pixels
} IMG;

IMG pic;

IMG *PPMin(char *inFile);
void *PPMout(IMG *p1, char *outFile);
IMG *PPMcvt(IMG *p1, char *outFile);

int main(int argc, char*argv[])
{
    while(--argc)
    {
        PPMin(argv[argc]);
    }
}

IMG *PPMin(char *inFile)
{
    FILE* fin = fopen(inFile, "r");
    fscanf(fin, "%s%d%d%d", pic.header, pic.W, pic.H, pic.level);

    fclose(fin);
}

void *PPMout(IMG *p1, char *outFile)
{}

IMG *PPMcvt(IMG *p1, char *outFile)
{}

