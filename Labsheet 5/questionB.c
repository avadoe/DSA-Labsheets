#include <stdio.h>
#include <stdbool.h>

int lastRemaining(int n)
{
    bool left = true;
    int head = 1;
    int jmp = 1;
    int remaining = n;

    while (remaining > 1)
    {
        if(left || remaining % 2 == 1)
            head += jmp;
        jmp *= 2;
        remaining /= 2;
        left = !left;
    }
    return head;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", lastRemaining(n));
    return 0;
}