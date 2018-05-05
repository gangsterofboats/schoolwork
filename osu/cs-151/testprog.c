#include <stdio.h>

void showMessage(void);

int main()
{
    int count = 0;

    while (count < 10)
    {
        showMessage();
        ++count;
    }

    return 0;
}

void showMessage(void)
{
    printf("Hello, World!\n");
}