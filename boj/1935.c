#include <stdio.h>
int N, top = -1;
double value[26], stack[200];
char inputStr[200];

int main(void) {
    scanf("%d %s", &N, inputStr);
    for (int i = 0; i < N; i++)
        scanf("%lf", &value[i]);
    for (int i = 0; inputStr[i] != '\0'; i++) {
        if ('A' <= inputStr[i] && inputStr[i] <= 'Z') stack[++top] = value[inputStr[i] - 'A'];
        else {
            double rear = stack[top--], front = stack[top--];

            if (inputStr[i] == '+') stack[++top] = front + rear;
            else if (inputStr[i] == '-') stack[++top] = front - rear;
            else if (inputStr[i] == '*') stack[++top] = front * rear;
            else if (inputStr[i] == '/') stack[++top] = front / rear;
        }
    }
    printf("%.2f\n", stack[top]);
}
