#pragma optimize level = 0;

#include <stdio.h>   /* required for file operations */
#include <stdlib.h>  /* required for malloc */
#include <string.h>


//Variables
char* filename = "fourcolor.bmp";
FILE *fp;
unsigned char * bitmapImage;
unsigned char * pixelData;
int num_pix = 0;
int width = 0;
int height = 0;

//Structs
#pragma pack(push, 1)
typedef struct {
	unsigned short type;             /* Magic identifier            */
	unsigned int size;               /* File size in bytes          */
	unsigned int reserved;
	unsigned int offset;             /* Offset to image data, bytes */
} HEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	unsigned int size;               /* Header size in bytes      */
	int width,height;                /* Width and height of image */
	unsigned short planes;           /* Number of colour planes   */
	unsigned short bits;             /* Bits per pixel            */
	unsigned int compression;        /* Compression type          */
	unsigned int imagesize;          /* Image size in bytes       */
	int xresolution,yresolution;     /* Pixels per meter          */
	unsigned int ncolours;           /* Number of colours         */
	unsigned int importantcolours;   /* Important colours         */
} INFOHEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	unsigned char r,g,b,a;
} COLORINDEX;
#pragma pack(pop)




//int main() {
//	BMPtoCharArray();
//
//	printToVGA();
//}

void printToVGA(alt_up_pixel_buffer_dma_dev * pixel_buf_dev){
	int i, j;
	int xoffset = 100;
	int yoffset = 100;
	float scalefactor = 1023/255;

	for(i = 0; i < (num_pix*3); i += 3){

		int R = (int)(pixelData[i]*scalefactor);
		int G = (int)(pixelData[i+1]*scalefactor);
		int B = (int)(pixelData[i+2]*scalefactor);
		//printf("R %d G %d B %d\n", R, G, B);

		int rbits = R << 20;
		int gbits = G << 10;
		int bbits = B;

		int color = rbits | gbits | bbits;

		int xpos = (i/3) % width;
		int ypos = (int) (i/3) / height;

		printf("Placing pixel of color %d at (%d,%d)\n", color, xpos, ypos);

		alt_up_pixel_buffer_dma_draw(pixel_buf_dev, color, xpos+xoffset, ypos+yoffset);
	}

}

int BMPtoCharArray() {
	fp = fopen (filename, "rt");  //open the file for reading text
	if(!fp){return 0;}

	int s = BMPReadImage(fp);
	if(s == 1) printf("Image was read successfully\n");

	return 1;
}

int BMPReadImage(FILE* fptr) {
	HEADER header;
	INFOHEADER infoheader;
	unsigned char *bitmapImage;  //store image data
	int x, y, rd;
	int lineLength;
	//char *stderr = "VGAerr";


	/* Read and check BMP header */
	if(fread(&header.type, 2, 1, fptr) != 1){
		fprintf(stderr, "Failed to read BMP header\n");
		return 0;
	}
	if(header.type != 'M'*256+'B' && header.type != 0x4D42){
		fprintf(stderr, "File is not bmp type\n");
		return 0;
	}
	do{
		if((rd = fread(&header.size, 4, 1, fptr)) != 1) break;
		printf("File size: %d bytes\n", header.size);
		if((rd = fread(&header.reserved, 4, 1, fptr)) != 1) break;
		if((rd = fread(&header.offset, 4, 1, fptr)) != 1) break;
		printf("Offset to image data is %d bytes\n", header.offset);
	}while(0);
	if(rd != 1){
		fprintf(stderr, "Error reading file\n");
		return 0;
	}

	/* Read and check the information header */
	if (fread(&infoheader, sizeof(INFOHEADER), 1, fptr) != 1) {
		fprintf(stderr,"Failed to read BMP info header\n");
		return 0;
	}
	width = infoheader.width;
	height = infoheader.height;
	printf("Image size = %d x %d\n", infoheader.width, infoheader.height);
	printf("Number of color planes is %d\n", infoheader.planes);
	printf("Bits per pixel is %d\n", infoheader.bits);
	printf("Compression type is %d\n", infoheader.compression);
	//printf("Number of colors is %d\n", infoheader.ncolours);
	//printf("Number of required colors is %d\n", infoheader.importantcolours);

	//move file point to the beginning of bitmap data
	fseek(fptr, header.offset, SEEK_SET);

	//allocate enough memory for the bitmap image data
	bitmapImage = (unsigned char*)malloc(infoheader.imagesize);
	pixelData = (unsigned char*)malloc(infoheader.imagesize);

	//verify memory allocation
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(fptr);
		return 0;
	}

	//read in the bitmap image data
	size_t byte_size = 8;//sizeof(Byte);
	size_t num_bytes = header.size-header.offset;
	num_pix = infoheader.width * infoheader.height;
	fread(bitmapImage, byte_size, num_bytes, fptr);

	//make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(fptr);
		return 0;
	}

	int imageIdx;
	/*printf("\nBitmapImage data:\n");
	for (imageIdx = 0; imageIdx < num_bytes; imageIdx++)
	{
		//printf("%d,%d,%d,%d\n",bitmapImage[imageIdx],bitmapImage[imageIdx+1],bitmapImage[imageIdx+2],bitmapImage[imageIdx+3]);
		printf("%d,",bitmapImage[imageIdx]);
	}*/



	//Assign relevant image data to the global pixelData structure
	//swap the r and b values to get RGB (bitmap is BGR)
	//ignore the 8-mult padding
	//change from bottom-up to top-down???
	printf("\n\nPixelData data:\n");
	int endOfData = num_pix*4; //ignore 2-byte end, start at last row
	int pixIdx = 0;
	for (imageIdx = endOfData-8; imageIdx >= 0; imageIdx -= 8) //BRG BRG padding padding
	{
		pixelData[pixIdx+0] = bitmapImage[imageIdx+2];
		pixelData[pixIdx+1] = bitmapImage[imageIdx+1];
		pixelData[pixIdx+2] = bitmapImage[imageIdx+0];

		pixelData[pixIdx+3] = bitmapImage[imageIdx+5];
		pixelData[pixIdx+4] = bitmapImage[imageIdx+4];
		pixelData[pixIdx+5] = bitmapImage[imageIdx+3];

		printf("%d\t%d\t%d\n",pixelData[pixIdx],pixelData[pixIdx+1],pixelData[pixIdx+2]);
		printf("%d\t%d\t%d\n",pixelData[pixIdx+3],pixelData[pixIdx+4],pixelData[pixIdx+5]);

		pixIdx+=6;
	}


	/*int i;
	for(i = 0; i < (num_pix*3); i++){
		printf("%d,", pixelData[i]);
	}*/
	printf("\n");

	//close file and return
	fclose(fptr);
	//return bitmapImage;
	return 1;

}
