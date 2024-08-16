
# SmartCalc v2.0

## Project Description

SmartCalc v2.0 is a calculator developed in C++ (C++17 standard) that supports complex arithmetic expressions, function graph plotting, and includes additional modes for loan and deposit calculations.

## Features

### Main Functions

1. **Arithmetic Expression Calculation**:
    - Support for integer and floating-point numbers, including exponential notation.
    - Calculation occurs after the full expression is entered and the `=` symbol is pressed.
    - Support for bracketed arithmetic expressions in infix notation.
    - Support for variable substitution with the variable _x_.
    - Precision of fractional parts up to 7 decimal places.
    - Input up to 255 characters.
    - Support for the following arithmetic operators:
        - Brackets: `(a + b)`
        - Addition: `a + b`
        - Subtraction: `a - b`
        - Multiplication: `a * b`
        - Division: `a / b`
        - Exponentiation: `a ^ b`
        - Modulus: `a mod b`
        - Unary plus: `+a`
        - Unary minus: `-a`
    - Support for mathematical functions:
        - Cosine: `cos(x)`
        - Sine: `sin(x)`
        - Tangent: `tan(x)`
        - Arccosine: `acos(x)`
        - Arcsine: `asin(x)`
        - Arctangent: `atan(x)`
        - Square root: `sqrt(x)`
        - Natural logarithm: `ln(x)`
        - Common logarithm: `log(x)`

2. **Function Graph Plotting**:
    - Plotting function graphs.
    - Displaying coordinate axes, scale markings, and grid with adaptive steps.
    - Setting the domain and range from -1,000,000 to 1,000,000.

### Additional Functions

1. **Loan Calculator**:
    - Input parameters: total loan amount, term, interest rate, type (annuity, differentiated).
    - Output data: monthly payment, total overpayment, total repayment.

2. **Deposit Calculator**:
    - Input parameters: deposit amount, term, interest rate, tax rate, payment frequency, interest capitalization, list of additions, list of partial withdrawals.
    - Output data: accrued interest, tax amount, final amount in the deposit at the end of the term.

## Technical Details

- The project is implemented in C++ (C++17 standard).
- The source code is located in the `src` folder.
- The code follows the Google C++ Style Guide.
- Classes are implemented within the `s21` namespace.
- Complete unit test coverage using the GTest library.
- The program build is configured using a Makefile with the following targets: `all`, `install`, `uninstall`, `clean`, `dvi`, `dist`, `tests`, and `open`.

## Graphical Interface

Implemented using Qt `6.7.2`.

## Design Pattern

The program is designed using the MVC pattern:

- Business logic is separated from views.
- No interface in controllers and models.
- Thin controllers.

## Installation and Build

To build and install the program, use CMake. Ensure that you have CMake version 3.16 or higher, Qt version 6.7.2 or higher, make, and g++ installed on your computer.

### Build Steps

1. **Clone the repository**:

    ```sh
    git clone git@github.com:mikhail-kirillov/SmartCalc-v2.0.git
    cd SmartCalc
    ```

2. **Install and run all targets**:

   ```sh
   make
   ```
