// segmentation in c programming
#include<stdio.h>

#define SEGMENT_COUNT 3

typedef struct 
{
    int baseAddress;
    int limit;
}Segment;

int main(){
    Segment segments[SEGMENT_COUNT]={
        {0,100},
        {101,200},
        {201,300}
    };

    int segmentNumber,offset;
    printf("Enter Segment Number(0-%d):",SEGMENT_COUNT-1);
    scanf("%d",&segmentNumber);

    if(segmentNumber<0 || segmentNumber>=SEGMENT_COUNT){
        printf("Invalid segment Number.\n");
        return 1;

    }

    printf("Enter Offset(0-%d):",segments[segmentNumber].limit);
    scanf("%d",&offset);

    if(offset<0 || offset>segments[segmentNumber].limit){
        printf("Offset out of bound.\n");
        return 1;
    }
    
    int physicalAddress = segments[segmentNumber].baseAddress +offset;
    printf("Physical Address: %d\n",physicalAddress);

    return 0;
}