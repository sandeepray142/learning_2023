#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%f", &c->real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->imag);
}

void writeComplex(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex c1, c2, sum, product;

    printf("Reading complex number 1:\n");
    readComplex(&c1);

    printf("Reading complex number 2:\n");
    readComplex(&c2);

    printf("Complex number 1:\n");
    writeComplex(c1);

    printf("Complex number 2:\n");
    writeComplex(c2);

    sum = addComplex(c1, c2);
    printf("Sum of complex numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(c1, c2);
    printf("Product of complex numbers:\n");
    writeComplex(product);

    return 0;
}
