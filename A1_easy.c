#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char data[28],temp[28],divisor[28];
int l,i,j,N;

void xorl()
{
    for(j=1;j<N;j++)
    {
        if(temp[j]==divisor[j])
            temp[j]='0';
        else
            temp[j]='1';
    }
}

void crc() //gives remainder and stores in temp
{
    for(i=0;i<N;i++)
        temp[i]=data[i];
    do
    {
        if(temp[0]=='1') //apply division where dataword starts with 1
            xorl();
        for(j=0;j<N-1;j++)
            temp[j]=temp[j+1]; //single shift
        temp[j]=data[i++];
    }
    while(i<=l+N-1);
}

void main()
{
    int ch,flag;

    printf("Enter new data:\n");
    scanf("%s",&data);
    printf("Enter the divisor to be used for crc:\n");
    scanf("%s",&divisor);
    N=strlen(divisor); //
    l=strlen(data); //
    while(1)
    {
        printf("\nMENU\n");
        printf("1.Find sender's side codeword\n");
        printf("2.Check receiver's side codeword\n");
        printf("3.EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                for(i=l;i<l+N-1;i++) //padding with zeroes
                    data[i]='0';
                crc();
                for(i=l;i<l+N-1;i++) //redundant bits added to dataword
                    data[i]=temp[i-l];
                printf("Divisor is: %s\n",divisor);
                printf("Remainder is: %s\n",temp);
                printf("Final sender's codeword is: %s\n",data);
                break;
            }
            case 2:
            {
                flag=0;
                printf("Enter the recieved data on receiver's side:\n");
                scanf("%s",&data);
                crc();
                printf("Remainder is: %s\n",temp);
                for(i=l;i<l+N-1;i++) //remainder supposed to be zero for no error
                {
                    if(temp[i-l]=='1')
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    printf("Therefore data has no errors.\n");
                else
                    printf("Therefore data has errors.\n");
                break;
            }
            case 3: exit(0);
            default:
            {
                printf("Invalid input.\n");
                break;
            }
        }
    }
}
