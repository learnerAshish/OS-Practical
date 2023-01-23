#include <stdio.h>
int main()
{
    printf("Ashish Joshi B 20011905\n");
    int pages;
    printf("enter number of pages: ");
    scanf("%d",&pages);
    int incomingStream[pages];
    printf("enter the pages value: ");
    for(int i=0;i<pages;i++)
        scanf("%d",&incomingStream[i]);
    int frames,pageFaults = 0;
    printf("enter size of frame: ");
    scanf("%d",&frames);
    printf("Frame 1 \t Frame 2 \t Frame 3 \t Frame 4");
    int temp[frames];
    for(int m = 0; m < frames; m++)
        temp[m] = -1;
    for(int m = 0; m < pages; m++)
    {
        int s = 0;
        for(int n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if((pageFaults <= frames) && (s == 0))
            temp[m] = incomingStream[m];
        else if(s == 0)
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        printf("\n");
        for(int n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
