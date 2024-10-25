#include <iostream>
#include <array>
#include <cmath>
using namespace std;

// Вычисление градиента
void grad_func(double x1, double x2, double& grad1, double& grad2)
{
    grad1 = 4 * x1 + x2;
    grad2 = x1 + 2 * x2;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Начальные условия  x_0
    double x1{ 0.5 }, x2 = { 1.0 };

    // Точность вычисления
    double eps_1 = 0.1, eps_2 = 0.15;

    // Максимальное количество итераций
    const int M = 10;

    // объявление счетчика итераций
    int k{ 0 };

    // переменные для записи значения градиента в точках
    double grad1, grad2;

    // Матрица Гессе
    double H11 = 4, H12 = 1, H22 = 2;

    do
    {
        // вычисления градиента
        grad_func(x1, x2, grad1, grad2);

        // Вычисление нормы градиента
        double grad_norm = sqrt(grad1 * grad1 + grad2 * grad2);

        // проверка условия величины нормы градиента
        if (grad_norm <= eps_1)
        {
            std::cout << "Условие завершения выполнено на итерации " << k << ": норма градиента " << grad_norm << " <= " << eps_1 << std::endl;
            break;
        }


    } while (k < M);
    return 0;
}
