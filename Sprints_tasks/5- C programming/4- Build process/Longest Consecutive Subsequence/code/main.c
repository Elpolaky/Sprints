#include"longest.h"

int main()
{
    int8_t check ;
    uint8_t b,i=0;
    uint8_t _size = sizeof(arr)/sizeof(arr[0]);

    /*
        insertionSort(arr,_size);
        printArray(arr,_size);*/

    printf("[ \n");
    while(1)
    {
        scanf("%d",&arr[i]);

        if(arr[i]==NULL  && i>=10)
        {
            i--;

            break;



        }
        else if(arr[0]==NULL &&arr[0]!=0)
        {
            break;
        }
        else
        {
            i++;
        }


    }

    check =lcsGetSize(arr,i, &b) ;

    if(check!=0)
    {
        if(arr[0]==NULL){
        printf("\nEMPTY ARRAY");

        }else{
        printf("return value : %d", check);
        }
    }
    else
    {
        printArray(arr,_size);

        printf("Longest Consecutive : %d ", b);
    }
    printf("\n");

    return 0;
}
