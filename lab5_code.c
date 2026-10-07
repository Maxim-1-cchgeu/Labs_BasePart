#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define t -6

void calculate_sin();
void calc_indiv_expression();
int get_condition_result(int a, int b, int c);

int main()
{
	setlocale(LC_CTYPE, "RUS.UTF-8");
	calculate_sin();
	puts("");
	calc_indiv_expression();
	puts("");

    return 0;
}

void calculate_sin()
{
    double gr, agl;
    puts("Введите угол (град.):");
    scanf("%f", &gr);

    agl = gr * M_PI / 180;
	printf("sin %f = %.6f\n", gr, sin(agl));
}

void calc_indiv_expression()
{
    double x;
    puts("Введите значение x:");
    scanf("%f", &x);
    
    double a, b, y;
    a = log(x);
    b = sqrt(pow(x, 2) + pow(t, 2));
    y = pow(fabs(a - b*x), 1./5);
    printf("При значении x = %.1f y = %.4f\n", x, y);

    int logic_result = get_condition_result((int)a, (int)b, (int)y);
    printf("условие выполнено (1 - да, 0 - нет): %d\n", logic_result);
}

int get_condition_result(int a, int b, int c)
{
    int a_expr = (a + b) % 2 == 1;
    int b_expr = a % 3 == 0
                && b % 3 == 0
                && c % 3 == 0;

    return a_expr && b_expr;
}
