#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1();
void calculator();

int main()
{
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

void dz()
{
    char c;

    puts("Введите цифру:");
    scanf("%c", &c);

    switch (c)
    {
    case '0':
        printf("%c - zero", c);
        break;
    case '1':
        printf("%c - one", c);
        break;
    case '2':
        printf("%c - two", c);
        break;
    case '3':
        printf("%c - three", c);
        break;
    case '4':
        printf("%c - four", c);
        break;
    case '5':
        printf("%c - five", c);
        break;
    case '6':
        printf("%c - six", c);
        break;
    case '7':
        printf("%c - seven", c);
        break;
    case '8':
        printf("%c - eight", c);
        break;
    case '9':
        printf("%c - nine", c);
        break;
    default:
        printf("%c - не цифра", c);
        break;
    }
}
