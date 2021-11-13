#include <iostream>
#include "Header.h"

using namespace std;
int najmanji(int a[], int n)
{
    int x;
    if (n == 0)
        return 0;
    if (n == 1)
        return a[n - 1];
    x = najmanji(a, n - 1);
    if (x > a[n - 1])
        x = a[n - 1];
    return x;
}
int najveci(int a[], int n)
{
    int y;
    if (n == 0)
        return 0;
    if (n == 1)
        return a[n - 1];
    y = najveci(a, n - 1);
    if (y < a[n - 1])
        y = a[n - 1];
    return y;

}