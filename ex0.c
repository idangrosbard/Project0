#include <stdio.h>
#include <assert.h>
#include <math.h>

int verify_base(char c, int base) {
    if ((c - '0' > base) || (c - '0' < 0)) {
        if (base > 10) {
            if ((c - 'a' > base - 10) || (c - 'a' < 0)) {
                printf("> Invalid number!");
                return 0;
            }
        }
        else {
            printf("> Invalid number!");
            return 0;
        }
    }
    return 1;
}

unsigned int base_to_dec(char c) {
    if (c - '0' <= 10) {
        return (unsigned int)(c - '0');
    } else {
        return 10 + (unsigned int)(c - 'a');
    }
}

char dec_to_base(unsigned int num, unsigned int base) {
    int digit = num%base;
    if (digit >= 10) {
        return 'a' + (digit - 10);
    }
    return (char)digit;
}

void print_dec_in_base_rec(unsigned int num, unsigned int base) {
    char c;
    if (num == 0) {
        return;
    }
    c = dec_to_base(num, base);
    print_dec_in_base_rec(num / base, base);
    printf("%u", c);
}

unsigned int get_dec_input(unsigned int base) {
    unsigned int num = 0;
    char c;
    do {
        c = getchar();
        if ((c != '\n') && (c != EOF)) {
            assert(verify_base(c, base) == 1);
            num *= base;
            num += base_to_dec(c);
        }
    } while ((c != '\n')&& (c != EOF));

    return num;
}


int main() {
    unsigned int a = 0, b = 0, num = 0;

    printf("> Please enter the numbers base:\n");
    scanf("%u", &a);
    if (a > 16 || a < 2) {
        printf("> Invalid input base");
        assert((16 >= a) && (a >= 2));
    }

    printf("> Please enter the desired base:\n");
    scanf("%u", &b);
    if (b > 16 || b < 2) {
        printf("> Invalid desired base");
        assert((16 >= b) && (b >= 2));
    }

    printf("> Please enter a number in base %u:\n", a);
    getchar();
    num = get_dec_input(a);

    printf("> The result is: ");
    if (num == 0) {
        printf("%u", num);
    } else {
        print_dec_in_base_rec(num, b);
    }
    printf("\n");
    return 0;
}
