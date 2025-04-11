// Recursividad
// Fecha: 09.10.2025

// Fibonacci
int fib(int n) {
	if(n == 0 || n == 1 || n < 0) {
		return n;
	} else {
		return fib(n-1) + fib(n-2);
	}
}

// Factorial
int fact(int n) {
    // n! = n × (n - 1)!
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}
