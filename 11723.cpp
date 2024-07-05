#include <stdio.h>
int T, x, S;
int main() {
    scanf("%d", &T);
    char cmd[9];
    while (T--) {
        scanf("%s %d", cmd, &x);
        if (cmd[0] == 'a' && cmd[1] == 'd') S |= (1 << x);
        else if (cmd[0] == 'r') S &= ~(1 << x);
        else if (cmd[0] == 'c') printf("%d\n", (S & (1 << x) ? 1 : 0));
        else if (cmd[0] == 't') S ^= (1 << x);
        else if (cmd[0] == 'e') S = 0;
        else S = (1 << 21) - 1;
    }
}
