#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1();
void calculator();

int main()
{
    setlocale(LC_CTYPE, "RUS.UTF-8");
    
    task1();
    puts("");
    calculator();
    puts("");

    return 0;
}

void task1()
{
    char c;
    printf("Введите символы 'a' or 'b': ");
    scanf("%c", &c); // считывание с консоли

    if (c >= 48 && c <= 57)
    {
        puts("это цифра");
    }
    else if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
    {
        puts("это буква");
    }
    else
    {
        puts("это символ");
    }
}

void calculator()
{
    float x, y;
    char c;

    puts("Допустимые операции: +, -, *, /, ^. Введите выражение (например, 5+2):");
    scanf("%f%c%f", &x, &c, &y);

    switch (c)
    {
    case '+':
        printf("=%f", x + y);
        break;
    case '-':
        printf("=%f", x - y);
        break;
    case '*':
        printf("=%f", x * y);
        break;
    case '/':
        printf("=%f", x / y);
        break;
    case '^':
        printf("=%f", pow((double)x, (double)y));
        break;
    default:
        printf("Неизвестная операция: '%c'", c);
        break;
    }
}
