#include <stdio.h>
int main(void) {
    int h, m, s, d;
    scanf("%d%d%d%d",&h,&m,&s,&d);
    m += h * 60; s += m * 60; d += s;
    s = d % 60; d /= 60;
    m = d % 60; d /= 60;
    h = d % 24;
    printf("%d %d %d\n", h, m, s);
}
