#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>
  
void InsertionSort(int IntArray[], int length);
int main(int argc, char *argv[])
{

     int i = 0;
    int arr[argc - 1];

    while (argc <=1){
        printf("Please input the numbers from CLI");
        exit(0);
    }

    for (i; i< (argc - 1); i++)
    {
        arr[i] = atoi(argv[i+1]);
    }

   // int arr[] = {90, 81, 78, 95, 79, 72, 85};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    int average, minimum, maximum, median;
    // Creating first child
    int n1 = fork();
    
    // Creating second child. First child
    // also executes this line and creates
    // grandchild.
    int n2 = fork();
  
    if (n1 > 0 && n2 > 0) {
        printf("-----------------average-----------------------\n");
        
        
        for(int i=0; i<len;i++)
        {
            sum += arr[i];
        }
        average = sum / len;
        printf("average: %d\n", average);

    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("---------------minimum------------------------\n");
       
        int min = INT_MAX;
            for (int i= 0; i < len; i++)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                }
            }

        printf("minimum: %d\n", min);
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("----------------------maximum------------------------\n");
        
        int max = INT_MIN;
        for(int i=1; i < len; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }

        printf("maximum: %d\n", max);
    }
    else {
        printf("----------------------median------------------\n");
      
        InsertionSort(arr, len);
        int median=0;
    
        // if number of elements are even
        if(len%2 == 0)
        {
            median = (arr[(len-1)/2] + arr[len/2])/2.0;
        }
        // if number of elements are odd
        else
        {
            median = arr[len/2];
        }
        printf("median: %d\n", median);
    }

    return 0;
}

void InsertionSort(int IntArray[], int length)
{
    int key,j;
    for(int i=1; i<length; i++)
    {
        key = IntArray[i];
        j = i -1;
        while(j>=0 && IntArray[j]>key)
        {
            IntArray[j+1] = IntArray[j]; //if previous index is greater than next index then swap
            j = j-1; //going back an index until j = -1
        }
        IntArray[j+1] = key;
    }

}