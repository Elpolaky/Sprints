#include"longest.h"

int8_t insertionSort(int32_t *array, uint8_t arraySize)
{

    int32_t i =0,k,_temp,return_value;

    if( arraySize ==0 || arraySize>10)
    {

        return_value = -2;


    }
    else if(array[0] == NULL && arr[0]!=0)
    {
        return_value = -2;


    }
    else
    {
        for(i=0 ; i<=arraySize-1 ; i++)
        {

            for(k=i+1; k>0 && k<=arraySize-1; --k)
            {
                if(array[k]<array[k-1])
                {
                    _temp  = array[k];
                    array[k]= array[k-1];
                    array[k-1] =_temp;

                }

            }

        }
        return_value = 0;
    }
    return return_value;
}


void printArray(int32_t *array, uint8_t arraySize)
{
    int32_t i;
    for (i = 0; i <= arraySize-1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    uint8_t x=0, max=0;
    int8_t return_value = insertionSort(array,arraySize),counter =0;

    if(return_value==-1)
    {
        return -1;
    }
    else if(return_value == 0)
    {
        for(uint8_t i = 0 ; i<=arraySize-1 ; i++)
        {
            if(array[i+1]==array[i]+1)
            {

                ++counter;
            }
            else
            {
                if(counter!=0 && max<=counter)
                {
                    max=counter;
                    *sizeofLCS=counter+1;
                    counter=0;
                    return_value = 0;
                }
                else if(max==0)
                {
                    return_value = -3;

                }
            }

        }
    }
    else
    {
        return_value = -2 ;
    }
    return return_value;
}

