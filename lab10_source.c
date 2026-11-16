#define _USE_MATH_DEFINES

#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9
#define TRIANGLE_NUMBER 5
#define TRIANGLE_LEG 5

void function_calc();
void calculate_sin();
double sin_n(double x, int n);
double sin_eps(double x, double eps);
void number_to_digits();
void calculate_individual();
double individual_n(double x, int n);
double individual_eps(double x, double eps);
void home();
double area_triangle(double a, double h);
int get_legs();
void draw_triangle(int a, int b, char ch);
double fa(double x);
double fb(double x);

int main()
{
    setlocale(LC_CTYPE, "RUS.UTF-8");

    function_calc();
    puts("");
    calculate_sin();
    puts("");
    calculate_individual();
    puts("");
    home();

    return 0;
}

void function_calc()
{
    double x, ya, yb;
    puts("Введите x для вычисления значений функций:");
    scanf("%lf", &x);
    
    ya = fa(x);
    yb = fb(x);
    
    int action;
    do
    {
        puts("Выберите действие:");
        puts("1. F1(x)");
        puts("2. F2(x)");
        puts("3. Произведение значений функций");
        puts("4. Разность квадратов значений функций");
        puts("5. Двойная сумма значений функций");
        puts("6. Выход");

        scanf("%d", &action);
        switch (action)
        {
            case 1:
                printf("F1(x)=%f\n", ya);
                break;
            case 2:
                printf("F2(x)=%f\n", yb);
                break;
            case 3:
                printf("Произведение: %f\n", ya * yb);
                break;
            case 4:
                printf("Разность квадратов: %f\n", pow(ya, 2.0) - pow(yb, 2.0));
                break;
            case 5:
                printf("Двойная сумма: %f\n", 2 * (ya+yb));
                break;
            case 6:
                break;
            default:
                printf("Действие не найдено\n");
                break;
        }
    } while (action != 6);
}

double fa(double x)
{
    if (x <= 3)
        return pow(x, 2.0) - 3*x + 9;

    return 1 / (pow(x, 3.0) + 3);
}

double fb(double x)
{
    return x * exp(sin(pow(x, 2.0)));
}

void calculate_sin()
{
    double x, eps;
    int n;
    puts("Введите x для вычисления синуса:");
    scanf("%lf", &x);
    printf("sin(x): %f\n", sin(x));

    puts("Введите n для sin_n(x):");
    scanf("%d", &n);
    printf("sin_n(x): %f\n", sin_n(x, n));

    puts("Введите eps для sin_eps(x):");
    scanf("%lf", &eps);
    printf("sin_eps(x): %f\n", sin_eps(x, eps));

}

double sin_n(double x, int n)
{
    double result = 0;
    double part = x;

    for (int k = 1; k < n; k++)
    {
        result += part;
        part *= (-x * x) / ((2.0 * k) * (2.0 * k + 1.0));
    }

    return result;
}

double sin_eps(double x, double eps)
{
    double result = 0;
    double part = x;
    int k = 1;

    while (fabs(part) >= eps)
    {
        result += part;
        part *= (-x * x) / ((2.0 * k) * (2.0 * k + 1.0));
        k++;
    }

    return result;
}

void calculate_individual()
{
    double x, eps;
    int n;
    puts("Введите x для вычисления sin(x)/x:");
    scanf("%lf", &x);
    printf("sin(x)/x: %f\n", sin(x) / x);

    puts("Введите n для sin_n(x):");
    scanf("%d", &n);
    printf("sin_n(x)/x: %f\n", individual_n(x, n));

    puts("Введите eps для sin_eps(x):");
    scanf("%lf", &eps);
    printf("sin_eps(x)/x: %f\n", individual_eps(x, eps));
}

double individual_n(double x, int n)
{
    double result = 0;
    double part = 1.0;

    for (int k = 1; k < n; k++)
    {
        result += part;
        part *= (-x * x) / ((2.0 * k) * (2.0 * k + 1.0));
    }

    return result;
}

double individual_eps(double x, double eps)
{
    double result = 0;
    double part = 1.0;
    int k = 1;

    while (fabs(part) >= eps)
    {
        result += part;
        part *= (-x * x) / ((2.0 * k) * (2.0 * k + 1.0));
        k++;
    }

    return result;
}

void home()
{
    int a = 30;
    int b = 6;
    char ch = '*';
    printf("Площадь треугольника: %f\n", area_triangle((double)a, (double)b));
    draw_triangle(a, b, ch);
}

double area_triangle(double a, double h)
{
    return a * h / 2;
}

int get_legs()
{
    return 1;
}

void draw_triangle(int a, int b, char ch)
{
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= i * a / b; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
