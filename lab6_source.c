#include <stdio.h>
#include <locale.h>

void bissectus_year();
void f();

int main()
{
    setlocale(LC_CTYPE, "RUS.UTF-8");
    bissectus_year();
    puts("");
    f();

    return 0;
}

void bissectus_year()
{
    int years;
    puts("Введите год: ");
    scanf("%d", &years);

    if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0)
    {
        printf("Год %d високосный", years);
    }
    else
    {
        printf("Год %d не високосный", years);
    }
}

void f()
{
    float x;

    puts("Введите x: ");
    scanf("%f", &x);
    printf("F(x)=%f", x <= 1 ? 0 : 1 / (x+6));
}
