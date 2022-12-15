#include<stdio.h>

int main()
{
    int incoming, outgoing, buck_size, n, store = 0;
    printf("Enter bucket size:\n");
    scanf("%d",&buck_size);
    printf("Enter outgoing rate:\n");
    scanf("%d",&outgoing,&n);
    printf("Enter no of inputs:\n");
    scanf("%d",&n);

    while (n != 0) 
    {   
        printf("\n\nEnter the no of incoming packets:");
        scanf("%d", &incoming);
        printf("Incoming no of packets: %d\n", incoming);
        if (incoming <= (buck_size - store))
        {   
            store += incoming;//Add to bucket
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        } 
        else 
        {   
            printf("DROPPED %d no of packets.\n", incoming - (buck_size - store));
            store = buck_size;//Drop extra packets
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        }
        store = store - outgoing;
        if(store<0)
        {
            store=0;
        }
        printf("After outflow: %d packets left out of %d in buffer.\n", store, buck_size);
        n--;
    }
}
