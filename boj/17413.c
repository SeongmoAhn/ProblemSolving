#include <stdio.h>
#include <string.h>
#define SIZE 100001

int ch, stack_flag, top = -1;
char stack[SIZE];

int main(void) {
    while ((ch = getchar()) != '\n') {
        if (stack_flag) {
            putchar(ch);
            if (ch == '>') stack_flag = 0;
        }
        else {
            if (ch == '<') {
                while (top != -1) putchar(stack[top--]);
                putchar(ch);
                stack_flag = 1;
                while (top != -1) putchar(stack[top--]);
            }
            else if (ch == ' ') {
                while (top != -1) putchar(stack[top--]);
                putchar(ch);
            }
            else stack[++top] = ch;
        }
    }
    while (top != -1) putchar(stack[top--]);
    printf("\n");
}
