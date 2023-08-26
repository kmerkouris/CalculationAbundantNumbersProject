#include <stdio.h>
#define MAXNUM 1000

int main ()
{
    int currentNumber,digitsOfnumbers,power10,subsequence,countSub,oneChild=0,sumDiv,abundants=0,BothOA=0;
    printf("Numbers both one-child and abundant : \n");
    for(int  numbers =0; numbers <= MAXNUM; numbers++)
    {
        currentNumber = numbers;                             //keep number without changes
        digitsOfnumbers = 0;
       
        while (currentNumber !=  0)                                     //found number of digits
        {
            digitsOfnumbers++;
            currentNumber=currentNumber/10;
        }
        power10 = 1;
        countSub=0;
        for (int i = 1 ; i<= digitsOfnumbers ; i++)
        {   
            power10=power10*10;                                             
            currentNumber=numbers;
            for (int j=1 ; j <=digitsOfnumbers- i+1;j++ )
            {
                subsequence = currentNumber % power10;                                      
                if (subsequence % digitsOfnumbers == 0)
                {
                    countSub++;
                }    
                currentNumber=currentNumber/10;
               // printf("  %d  ",subsequence);
            }
        }
        if (countSub==1)
        {
            oneChild++;
        }

        //printf("\n");
        sumDiv=1;

        for (int divisors = 2; divisors*divisors < numbers;divisors++)        // check half of divisors 
        {
            if (numbers % divisors == 0)
            {
                sumDiv = sumDiv + divisors + numbers/divisors;               // etc if i found for 24 12 then sum 12 and 2 

            }
            if (divisors*divisors == numbers)
            {
                sumDiv=sumDiv+divisors;
            }
        }
        if (sumDiv > numbers)
        {
            abundants++;
            if (countSub==1)
            {
                BothOA++;
                printf(" %4d ",numbers);
            }

        }

    }
    printf("\n");

    printf("Found %4d one-child numbers\n",oneChild);
    printf("Found %4d abundant numbers\n",abundants);
    printf("Found %4d numbers in both classes\n",BothOA);
}