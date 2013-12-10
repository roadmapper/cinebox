#pragma optimize level = 0;

#include <stdio.h>   /* required for file operations */
#include <stdlib.h>  /* required for malloc */
#include <string.h>

//Variables
char* filename;
int commentsOn = 0;
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

void printToVGA();
int BMPReadImage(FILE* fptr);
int BMPtoCharArray();





unsigned char* formattedPix;

void printToVGA(){
	int i, j;
	int xoffset = 100;
	int yoffset = 100;
	float scalefactor = 1023/255;
	int iter = 0;

	formattedPix =  (unsigned char*)malloc((2+num_pix*5)*sizeof(int));

	printf("{");
	for(i = 0; i < (num_pix*3); i += 3){

		int R = (int)(pixelData[i]*scalefactor);
		int G = (int)(pixelData[i+1]*scalefactor);
		int B = (int)(pixelData[i+2]*scalefactor);

		int rbits = R << 20;
		int gbits = G << 10;
		int bbits = B;

		int color = rbits | gbits | bbits;

		int xpos = (i/3) % width;
		int ypos = (i/3-xpos)/width;

		if(commentsOn){
			printf("\nPlacing pixel of color %d at (%d,%d).\n", color, xpos, ypos);
			printf("Passed: ");
		}

		//Print out the unsigned int COLOR for each pixel
		if(xpos == 0) printf("{");
		printf("%u", color);
		if(xpos == width-1) {
			printf("}");
			if(ypos != (height-1)) printf(",");
		}
		else printf(",");
		iter++;


		//alt_up_pixel_buffer_dma_draw(pixel_buf_dev, color, xpos+xoffset, ypos+yoffset);
	}
	printf("}\n");
	if(commentsOn){
		printf("Pix count now is %d\n", iter);
	}

	//Build the output array
	/*int iter = 0;
	int tag = 0;
	height = abs(height);
	width = abs(width);
	printf("%d,%d,", width,height);
	for(i=0; i< height; i++){
		printf("{");
		for(j=0; j< (width*3); j+=3){
			printf("%d,%d,%d",pixelData[(width*i*3)+j], pixelData[(width*i*3)+j+1], pixelData[(width*i*3)+j+2]);
			if(pixelData[(width*i*3)+j] == 0 && pixelData[(width*i*3)+j+1] == 0 && pixelData[(width*i*3)+j+2] == 0)
				tag++;
			if((j+3)<(width*3)) printf(",");
			iter++;
		}
		printf("}");
		if((i+1)<height) printf(",");
	}
	printf("\n");

	if(commentsOn){
		printf("Pix count now is %d\n", iter);
		printf("Tags are %d\n", tag);
	}*/

}

int BMPtoCharArray() {
	fp = fopen (filename, "rt");  //open the file for reading text
	if(!fp){return 0;}

	int s = BMPReadImage(fp);

	if(commentsOn){
		if(s == 1) printf("Image was read successfully\n");
		else printf("Image read failed!");
	}

	return 1;
}

int BMPReadImage(FILE* fptr) {
	HEADER header;
	INFOHEADER infoheader;
	unsigned char *bitmapImage;  //store image data
	int x, y, rd;
	int lineLength;


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
		if(commentsOn){
			printf("File size: %d bytes\n", header.size);
		}
		if((rd = fread(&header.reserved, 4, 1, fptr)) != 1) break;
		if((rd = fread(&header.offset, 4, 1, fptr)) != 1) break;
		if(commentsOn){
			printf("Offset to image data is %d bytes\n", header.offset);
		}
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
	width = abs(infoheader.width);
	height = abs(infoheader.height);

	if(commentsOn){
		printf("Image size = %d x %d\n", infoheader.width, infoheader.height);
		printf("Number of color planes is %d\n", infoheader.planes);
		printf("Bits per pixel is %d\n", infoheader.bits);
		printf("Compression type is %d\n", infoheader.compression);
		//printf("Number of colors is %d\n", infoheader.ncolours);
		//printf("Number of required colors is %d\n", infoheader.importantcolours);
	}

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
	num_pix = abs(infoheader.width * infoheader.height);
	if(commentsOn){
		printf("Num pixels: %d\n", num_pix);
	}
	fread(bitmapImage, byte_size, num_bytes, fptr);

	//make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(fptr);
		return 0;
	}

	int imageIdx;
	if(commentsOn){
		printf("\nBitmapImage data:\n");
		for (imageIdx = 0; imageIdx < num_bytes; imageIdx++)
		{
			printf("%d,",bitmapImage[imageIdx]);
		}
	}



	//Assign relevant image data to the global pixelData structure
	//swap the r and b values to get RGB (bitmap is BGR)
	//ignore the 8-mult padding
	//change from bottom-up to top-down
	if(commentsOn){
		printf("\n\nPixelData data:\n");
	}
	int pixIdx = 0;
	int pix = 0;

	int rowlength = 3*width;

	//if there is padding
	if(rowlength%4 != 0){
		if(commentsOn){
			printf("Padding is present\n");
		}
		int padding = rowlength%4;
		rowlength += padding;
		int endOfData = height*rowlength; //ignore 2-byte end, start at last row

		for (imageIdx = endOfData-rowlength; imageIdx >= 0; imageIdx -= rowlength) //BRG BRG padding padding
		{
			int pixStart;
			for(pixStart = imageIdx; pixStart < (imageIdx+width*3); pixStart+=3){
				pixelData[pixIdx+0] = bitmapImage[pixStart+2];
				pixelData[pixIdx+1] = bitmapImage[pixStart+1];
				pixelData[pixIdx+2] = bitmapImage[pixStart+0];

				pixIdx+=3;
				pix++;

			}
		}
	}
	else {//if there is not padding
		if(commentsOn){
			printf("No padding present\n");
		}
		int endOfData = height*rowlength;
		//int rowlength = 3*width;

		pixIdx = 0;
		for (imageIdx = endOfData-rowlength; imageIdx >= 0; imageIdx -= rowlength) //BRG BRG
		{
			//printf("ROW%d,",imageIdx);
			int pixStart;
			for(pixStart = imageIdx; pixStart < (imageIdx+width*3); pixStart+=3){
				pixelData[pixIdx+0] = bitmapImage[pixStart+2];
				pixelData[pixIdx+1] = bitmapImage[pixStart+1];
				pixelData[pixIdx+2] = bitmapImage[pixStart+0];

				pixIdx+=3;
				pix++;

			}
		}
	}

	if(commentsOn){
		printf("Pixels loaded: %d\n", pix);


		//Print pixel data
		int i;
		for(i = 0; i < (num_pix*3); i++){
			printf("%d,", pixelData[i]);
		}
		printf("\n");
	}

	//close file and return
	fclose(fptr);
	return 1;

}


int main(int argc, char **argv) {
	filename = argv[1];

	BMPtoCharArray();

	printToVGA();
	//return 1;
}



