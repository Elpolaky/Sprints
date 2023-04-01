#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t ;
typedef signed char int8_t ;
typedef signed int int32_t ;

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);


/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t *array, uint8_t arraySize);

/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

int32_t arr[10];

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
        else if(arr[0]==NULL)
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
        printf("return value : %d", check);

    }
    else
    {
        printArray(arr,_size);

        printf("Longest Consecutive : %d ", b);
    }
    printf("\n");

    return 0;
}


int8_t insertionSort(int32_t *array, uint8_t arraySize)
{

    int32_t i =0,k,_temp,return_value;

    if( arraySize ==0 || arraySize>10)
    {

        return_value = -2;


    }
    else if(array[0] == NULL)
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

