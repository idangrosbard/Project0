# include <stdio.h>
# include <assert.h>
# include <math.h>

//function Decleration
int convert_letter (char);
char num_to_char (int);

int main(){

    //Variables:
    int from_base;
    int to_base;
    char c;
    int num;
    int decimal_sum;
    int digit;
    char digit_char;
    int n;
    int check;

    // First Stage : get from base and check if is legal
    printf ("Please enter the numbers base:\n");
    scanf ("%d",&from_base);
    if (from_base <2 || from_base>16){
        printf ("Invalid input base\n");
        return 0;
    }

    // Second Stage : get to base and check if is legal
    printf ("Please enter the desired base:\n");
    scanf ("%d",&to_base);
    if (to_base <2 || to_base>16){
        printf ("Invalid desired base\n");
        return 0;
    }

    // Third Stage : get to num to convert
    printf ("Please enter a number in base %d:\n", from_base);
    getchar();
    c = getchar();
    decimal_sum = 0;
    while (c!='\n'){
        // Converet letter to number and then check if is is valid char in Base
        num = convert_letter(c);
        if (num<0 || num>=from_base){
            printf ("Invalid number! \n");
            return 0;
        }
        //First convert to base 10
        decimal_sum = decimal_sum*from_base + num;
        c = getchar();
    }
    // Convert decimal_sum to to_base
    printf ("The result is: ");
    n =  (int) (log (decimal_sum)/ log (to_base))+1; //length of number in new base
    for (int i = n-1;i>=0;i--){
        check  = pow(to_base,i);
        digit = (int)(decimal_sum/check);
        digit_char = num_to_char(digit);
        printf ("%c",digit_char);
        decimal_sum = (int) (decimal_sum%check);
    }
    printf ("\n");

        
    return 0;
}

// A function that recieves a char and a base
// return 0-F if char is in range [0,15] else return -1
int convert_letter(char c){
    
    int num;

    if ((int) c >=48 && (int)c <=57){
        return (int) c - 48;
    }
    switch (c)
    {
    case 'A':
        num = 10;
        break;
    case 'B':
        num = 11;
        break;
    case 'C':
        num = 12;
        break;
    case 'D':
        num = 13;
        break;
    case 'E':
        num = 14;
        break;
    case 'F':
        num = 15;
        break;
    
    default:
        num = -1;
        break;
    }
    return num;
}

// A function that recives a number in range [0.15]
// the function returns a char that represents the number in new Base
char num_to_char(int num){
    assert (num>=0 && num<=15);
    if (num>=0 && num<=9){
        return (char) '0'+num;
    }
    switch (num)
    {
    case 10:
        return 'A';
        break;
    case 11:
        return 'B';
        break;
    case 12:
        return 'C';
        break;
    case 13:
        return 'D';
        break;
    case 14:
        return 'E';
        break;
    case 15:
        return 'F';
        break;
    }

}