#include <cstdio>
using namespace std;

int main(void)
{
    int ch;
    int count = 0;;

    while ((ch = getchar()) != '#') {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
            count++;
    
        if (ch == '\n') {
            printf("%d\n", count);
            count = 0;
        }
    }

	return 0;
}
