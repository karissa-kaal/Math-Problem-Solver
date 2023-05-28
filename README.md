# Polynomial Operations in C++

Welcome to Polynomial Operations in C++! This code allows you to perform various operations on polynomials, including addition, multiplication, and evaluation. It provides a simple and efficient way to work with polynomial expressions.

## Introduction

This C++ code implements polynomial operations using two classes: `Term` and `Polynomial`. The `Term` class represents a single term in a polynomial expression, while the `Polynomial` class handles polynomial operations such as addition, multiplication, and evaluation. With this code, you can easily create and manipulate polynomials to perform common mathematical operations.

## Usage

To use the code, you can follow these steps:

1. Create a `Polynomial` object by calling its default constructor.
2. Use the `InsertTerm` function to add terms to the polynomial. Specify the coefficient and exponent for each term.
3. Perform various operations on the polynomials, such as addition (`Add` function), multiplication (`Multiply` function), and evaluation (`Evaluate` function).
4. Print the polynomials using the `Print` function to see the results.

## Examples

Here's an example to demonstrate the usage of the code:

```cpp
// Create a polynomial
Polynomial poly1;
poly1.InsertTerm(3.0, 2); // Add the term 3x^2
poly1.InsertTerm(-2.5, 1); // Add the term -2.5x^1
poly1.InsertTerm(1.0, 0); // Add the term 1x^0

// Print the polynomial
cout << "Polynomial 1: ";
poly1.Print();
cout << endl;

// Perform addition
Polynomial poly2;
poly2.InsertTerm(2.0, 3);
poly2.InsertTerm(4.5, 2);
poly2.InsertTerm(1.5, 1);

Polynomial sum = poly1 + poly2;
cout << "Sum of Polynomial 1 and Polynomial 2: ";
sum.Print();
cout << endl;

// Perform multiplication
Polynomial product = poly1 * poly2;
cout << "Product of Polynomial 1 and Polynomial 2: ";
product.Print();
cout << endl;

// Evaluate the polynomial
float value = 2;
float result = poly1.Evaluate(value);
cout << "Evaluation of Polynomial 1 for x = " << value << ": " << result << endl;

// Repeat the above steps for other polynomials or custom operations as needed
```

## Conclusion

Thank you for using Polynomial Operations in C++! We hope this code proves to be helpful in working with polynomial expressions. If you have any further questions or feedback, please don't hesitate to reach out. Happy coding!
