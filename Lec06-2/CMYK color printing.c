#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};





void print_C(unsigned int mask[][MAX_SIZE])
{
	for(int i=0;i<H;i++){
    	for(int j=0;j<W;j++){
        	// printf("%d ", mask[i][j]);
            image[i][j] |= mask[i][j] ;
        }
        // printf("\n");
    }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
	for(int i=0;i<H;i++){
    	for(int j=0;j<W;j++){
        	// printf("%d ", mask[i][j]);
            image[i][j] |= (mask[i][j] << 8);
        }
        // printf("\n");
    }
}

void print_Y(unsigned int mask[][MAX_SIZE])
{
	for(int i=0;i<H;i++){
    	for(int j=0;j<W;j++){
        	// printf("%d ", mask[i][j]);
            image[i][j] |= (mask[i][j] << 16);
        }
        // printf("\n");
    }
}

void print_K(unsigned int mask[][MAX_SIZE])
{
	for(int i=0;i<H;i++){
    	for(int j=0;j<W;j++){
        	// printf("%d ", mask[i][j]);
            image[i][j] |= (mask[i][j] << 24);
        }
        // printf("\n");
    }
}

void CMYK_to_RGB()
{
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            // printf("img : %d\n" , image[i][j] );
            unsigned int C = image[i][j] & 0xFF;
            unsigned int M = (image[i][j]>>8) & 0xFF;
            unsigned int Y = (image[i][j]>>16) & 0xFF;
            unsigned int K = (image[i][j]>>24) & 0xFF;
            // double base = ((double)(100-K)/100.0);
            // int R = round( 255.0 * ((double)(100-C)/100.0) * base );
            // int G = round( 255.0 * ((double)(100-M)/100.0) * base );
            // int B = round( 255.0 * ((double)(100-Y)/100.0) * base );
            unsigned int R = round( (double)( 255*(100-C)*(100-K) )/10000.0);
            unsigned int G = round( (double)( 255*(100-M)*(100-K) )/10000.0);
            unsigned int B = round( (double)( 255*(100-Y)*(100-K) )/10000.0);

            image[i][j]=0;
            image[i][j] |= (R << 16);
            image[i][j] |= (G << 8);
            image[i][j] |= B ;

            // printf("R:%d G:%d B:%d\n",R,G,B);
            // printf("#%06x \n", image[i][j]);
        }
    }
}






int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
