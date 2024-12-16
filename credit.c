#include <stdio.h>
#include <cs50.h>

int validation(long n);

int main(void){
    long n = get_long("Card's number: ");
    long length = 0, temp = n;
    while(temp != 0){
        temp /= 10;
        length++;
    }




    if (validation(n) && (length == 13 || length == 15 || length == 16)){
        do { n /= 10; }while(n >= 100);
        switch(n){
            case 34:
            case 37:
                if(length == 15){
                    printf("AMEX\n");
                    break;
                }
                printf("INVALID\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 60:
                if(length == 16){
                    printf("MASTERCARD\n");
                    break;
                }
                printf("INVALID\n");
                break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                if(length == 13 || length == 16){
                    printf("VISA\n");
                    break;
                }
                printf("INVALID\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }

    }else{
        printf("INVALID\n");
    }

    return 0;
    //AMEX
    //VISA
    //MASTERCARD
    //INVALID
}
//4003600000000014
int validation(long n){
    long temp = n, total = 0,digit;
    temp /= 10;
    //printf("%ld\n",temp);

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    while(temp > 0){
        digit = temp % 10;
        //printf("%ld\n",digit);
        temp /= 100;
        //printf("%ld\n",temp);
        digit *= 2;
        if(digit >= 10){
            total += (digit%10) + (digit/10);
            continue;
        }
        total += digit;
    }
    //printf("%ld\n",total);
    //Add the sum to the sum of the digits that weren’t multiplied by 2.
    while(n > 0){
        total += (n%10);
        n /= 100;
    }
    //printf("%ld\n",total);
    //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (total % 10 == 0){
        return 1;
    }

    return 0;
}
