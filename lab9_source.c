#define _USE_MATH_DEFINES

#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9
#define TRIANGLE_NUMBER 5
#define TRIANGLE_LEG 5

void piphagor();
void individual_triangle();
void number_to_digits();
void individual();
void home();

int main()
{
    setlocale(LC_CTYPE, "RUS.UTF-8");

    piphagor();
    puts("");
    individual_triangle();
    puts("");
    number_to_digits();
    puts("");
    home();

    return 0;
}

void piphagor()
{
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
            printf("%5d", col * row);
        printf("\n");
    }
}

void individual_triangle()
{
    int row, col;
    printf("\n");
    for (row = 1; row <= TRIANGLE_LEG; row++)
    {
        for (col = 1; col <= row; col++)
            printf("%3d", TRIANGLE_NUMBER);
        printf("\n");
    }
}

void number_to_digits()
{
    char a;
    int digits_number = 0; // Количество цифр, больших 5

    puts("Введите число для разложения:");
    a = getchar();

    do
    {
        // 48 - 57
        if (a > 53 && a <= 57)
        {
            digits_number++;
        }

        a = getchar();
    }
    while(a != '\n');
    printf("Количество цифр, больших 5: %d\n", digits_number);
}

void home()
{
    int r;

    puts("Отрисовка прямоугольного треугольника");
    puts("Введите радиус описанной вокруг треугольника окружности:");
    scanf("%d", &r);

    do
    {
        double leg = 2 * r * cos(45 * M_PI / 180);
        for (int y = 1; y <= round(leg); y++)
        {
            for (int x = 1; x <= y; x++)
            {
                printf("*  ");
            }
            puts("");
        }

        printf("Продолжить? (Да - введите любое число, Нет - введите 0)\n");
        scanf("%d", &r);
    }
    while (r != 0);
}
