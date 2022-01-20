#pragma once
#include "iostream"
class Operations
{
public:
	float add(float num_a, float num_b);
	float substract(float num_a, float num_b);
	float multiply(float num_a, float num_b);
	float divide(float num_a, float num_b);
	float pos_unary(float num_a);
	float neg_unary(float num_a);
};