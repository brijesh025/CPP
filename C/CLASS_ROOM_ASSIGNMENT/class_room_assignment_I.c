#include <stdio.h>

void welcome() {
    printf("..............------------WELCOME--------------...............-----------");
    printf("\n");
}

void showoption() {
    printf("---->WHAT DO YOU WANT TO ORDER?\n");
    printf("P. PIZZA\n");
    printf("B. BURGER\n");
    printf("S. SAAHI PANEER AND CHAPATI\n");
    printf("C. CHAUMIN\n");
    printf("O. BREAD OMLETTE\n");
    printf("E. EXIT\n");
}

void executeoption(char order) {
    switch (order) {
        case 'P':
        case 'p':
            printf("YOU HAVE ORDERED A PIZZA.\n");
            break;
        case 'B':
        case 'b':
            printf("YOU HAVE ORDERED A BURGER.\n");
            break;
        case 'S':
        case 's':
            printf("YOU HAVE ORDERED SAAHI PANEER AND CHAPATI.\n");
            break;
        case 'C':
        case 'c':
            printf("YOU HAVE ORDERED CHAUMIN.\n");
            break;
        case 'O':
        case 'o':
            printf("YOU HAVE ORDERED A BREAD OMLETTE.\n");
            break;
        case 'E':
        case 'e':
            break;
        default:
            printf("FOOD ITEM IS NOT AVAILABLE.\n");
            break;
    }
}

int main() {
    welcome();
    showoption();
    char order;
    printf("ENTER: ");
    scanf(" %c", &order);
    while (order != 'E' && order != 'e') {
        executeoption(order);
        printf("ENTER: ");
        scanf(" %c", &order);
    }
    printf("--------------------------------------------------------THANK YOU. PLEASE COME BACK SOON.----------------------------------------------------------- ");
    return 0;
}
