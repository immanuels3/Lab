#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int n, r;

struct frame {
    char ack;
    int data;
} frm[10];

int sender(void);
void recvack(void);
void resend(void);
void resend1(void);
void goback(void);
void selective(void);

int main()
{
    int c;
    srand(time(NULL));  // Seed rand()

    do {
        printf("\n\n1. Selective Repeat ARQ\n2. Go-Back-N ARQ\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch(c) {
            case 1: selective(); break;
            case 2: goback(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n"); break;
        }
    } while(c != 3);
}

int sender()
{
    int i;
    printf("\nEnter the number of packets to be sent: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter data for packet[%d]: ", i + 1);
        scanf("%d", &frm[i].data);
        frm[i].ack = 'y';
    }
    return 0;
}

void recvack()
{
    r = rand() % n;  // Randomly lose one packet
    frm[r].ack = 'n';

    int i;
    for(i = 0; i < n; i++) {
        if(frm[i].ack == 'n')
            printf("\nThe packet number %d is not received.\n", i + 1);
    }
}

void resend()  // Selective Repeat
{
    printf("\nResending packet %d...\n", r + 1);
    sleep(2);
    frm[r].ack = 'y';
    printf("Packet %d received successfully. Data = %d\n", r + 1, frm[r].data);
}

void resend1() // Go-Back-N
{
    printf("\nResending from packet %d...\n", r + 1);
    int i;
    for(i = r; i < n; i++) {
        sleep(2);
        frm[i].ack = 'y';
        printf("Packet %d received successfully. Data = %d\n", i + 1, frm[i].data);
    }
}

void goback()
{
    sender();
    recvack();
    resend1();
    printf("\nAll packets sent successfully using Go-Back-N ARQ.\n");
}

void selective()
{
    sender();
    recvack();
    resend();
    printf("\nAll packets sent successfully using Selective Repeat ARQ.\n");
}
