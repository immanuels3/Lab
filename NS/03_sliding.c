#include <stdio.h>

int main()
{
    int w, i, f, frames[50];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);

    printf("Enter %d frames: ", f);
    for(i = 0; i < f; i++)
        scanf("%d", &frames[i]);

    printf("\nWith sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames):\n\n");
    printf("Sender sends up to %d frames, then waits for acknowledgment.\n\n", w);

    for(i = 0; i < f; i++)
    {
        printf("Frame: %d ", frames[i]);

        // If window is full or it's the last frame
        if ((i + 1) % w == 0 || i == f - 1)
        {
            printf("\nAcknowledgment received for above frames.\n\n");
        }
    }

    return 0;
}
