# A User-Defined Type for Complex Numbers

## Problem

We are working on an engineering project that uses complex numbers for modeling
of electric circuits. We need to develop a user-defined structure type and a set of
operations that will make complex arithmetic virtually as straightforward as arithmetic
on C's built-in numeric types.

## Analysis

A complex number is a number with a real part and an imaginary part. For example, the
complex number $a+bi$ has a real part $a$ and an imaginary part $b$, where the symbol
$i$ represents  $\sqrt{-1}$. We will need to define functions  for complex **I/O** as well as for the basic arithmetic operations (additions, subtraction, multiplication, and division) and for finding the absolute value of complex number.

## Design

The two major aspects of our solution to this problem are defining the structure of the user-defined type and describing the function name, parameters, and purpose of each operation. Each function purpose then forms a subproblem to be solved separately. The details of these subproblems will be of interest to us as we develop our operations. However, once this group of functions is complete, we will be concerned only with *what* each functions does, not with *how* it does it. In the same way, when we use C's built-in multiplication operator, we are interested only in the fact that * does multiplication, not caring in the least how it manages to accomplish this.

As soon as the specification is complete, our coworkers on the circuit modeling project can begin designing algorithms that assume the availability of these operations. Then, when our implementations is complete, our code can either be added to their programs or packaged for inclusion in a way we will describe in Chapter 12.

$$ |a+bi| = \sqrt{(a+bi)} =  \sqrt{a^2 + b^2}$$

This result always has an imaginary part of zero, so `print_complex` will display the result as a result number.

### Function `multiply_complex`

$$(a + bi) \times (c+di) = (ac - bd) + (ad + bi) i $$

### Function `divide_complex`

$$ \frac{(a + bi)}{c + di} = \frac{ac + bd}{c^2 + d^2} + \frac{bc -ad}{c^2+d^2}i$$
