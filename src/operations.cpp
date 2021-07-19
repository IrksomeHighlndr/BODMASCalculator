#include "operations.h"

float Operations::add(float num_a, float num_b)
{
   std::cout << "(" << num_a << '+' << num_b << ")\n";
    return num_a + num_b;
}

float Operations::substract(float num_a, float num_b)
{
    std::cout << "(" << num_a << '-' << num_b << ")\n";
    return num_a - num_b;
}

float Operations::multiply(float num_a, float num_b)
{
    std::cout << "(" << num_a << '*' << num_b << ")\n";
    return num_a * num_b;
}

float Operations::divide(float num_a, float num_b)
{
    std::cout << "(" << num_a << '/' << num_b << ")\n";
    return num_a / num_b;
}

float Operations::pos_unary(float num_a)
{
    std::cout << "(+" << num_a <<  ")\n";

    return num_a;
}

float Operations::neg_unary(float num_a)
{
    std::cout << "(-" << num_a << ")\n";

    return -num_a;
}
