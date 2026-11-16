#include <stdio.h>
#include <locale.h>
#include <math.h>

void printchars();
void sum_from_m_to_n();
void exponentiation();
void tabulation();

int main()
{
    setlocale(LC_CTYPE, "RUS.UTF-8");

    printchars();
    puts("");
    sum_from_m_to_n();
    puts("");
    exponentiation();
    puts("");
    tabulation();

    return 0;
}

void printchars()
{
    for (int start = 1; start <= 10; start++)
    {
        if (start == 1)
            putchar('+');
        else if (start <= 10 / 2)
            putchar('*');
        else
            putchar('#');

        putchar('!');
    }
}

void sum_from_m_to_n()
{
    int n, m;
    puts("Сумма целых чисел от n до m");
    puts("Введите n:");
    scanf("%d", &n);

    puts("Введите m:");
    scanf("%d", &m);

    int s = 0;
    int k = 1;
    for (int i = m; i >= n; i--)
    {
        s += i;
        printf("Выполнено %d раз\n", k++);
    }

    printf("результат %d\n", s);
}

void exponentiation()
{
    int n, m;
    puts("Возведение 2 в степени от n до m");
    puts("Введите n:");
    scanf("%d", &n);
    puts("Введите m:");
    scanf("%d", &m);

    for (int i = n; i <= m; i++)
    {
        double value = pow(2.0, (double)i);
        printf("2^%d = %6d\n", i, (int)value);
        printf("Результат: %.1fK\n", value / 1024.0);
    }
}

void tabulation()
{
    puts("y = 2^x - 2x^2 - 1 [2;4]");
    puts("Задайте шаг:");
    double step;
    scanf("%lf", &step);

    puts("________________________");
    puts("|   x   |     f(x)     |");
    for (double x = 2.0; x < 4.001; x += step)
    {
        puts("|-------|--------------|");
        printf("| %5.2f | %12.6f |\n", x, pow(2.0, x) - 2*pow(x, 2.0) - 1);
    }
    puts("------------------------");
}
