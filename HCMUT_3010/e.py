import math


class Fraction:
    def __init__(self, numerator, denominator):
        gcd = math.gcd(numerator, denominator)
        self.numerator = numerator // gcd
        self.denominator = denominator // gcd
    
    def __str__(self):
        return f"{self.numerator}/{self.denominator}"
    
    def __add__(self, other):
        new_numerator = self.numerator * other.denominator + other.numerator * self.denominator
        new_denominator = self.denominator * other.denominator
        return Fraction(new_numerator, new_denominator)
    
    def __sub__(self, other):
        new_numerator = self.numerator * other.denominator - other.numerator * self.denominator
        new_denominator = self.denominator * other.denominator
        return Fraction(new_numerator, new_denominator)

input_str = input()

postfix = []
operator_stack = []

operator_priority = {
    '+': 0,
    '-': 0,
    '/': 1,
    '(': 2,
    ')': 2,
}

# for char in input_str:
#     if char.isdigit():
#         pass
#     else:
#         while 
#         operator_stack.insert(0, char)