#include <iostream>
int main(void) {
    int x, y, a, b, c, d, e;
    std::cin >> x >> y >> a >> b >> c >> d >> e;
    b -= d; c -= e;
    std::cout << a*(y*y*y-x*x*x)/3+b*(y*y-x*x)/2+c*(y-x);
}
