#include <iostream>
#include <cstdlib>

int N = 0;

int Diagonal(int **matrix)
{
    int suma = 0;
    
    for(int i = 0; i < N; ++i)
    {
        suma += matrix[i][i];
    }
    
    return suma;
}

int TriangularSuperior(int **matrix)
{
    int suma = 0;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(j > i)
            {
                suma += matrix[i][j];
            }
        }
    }
    
    return suma;
}

int TriangularInferior(int **matrix)
{
    int suma = 0;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(i > j)
            {
                suma += matrix[i][j];
            }
        }
    }
    
    return suma;
}

void OrdenarArreglo(int* &array)
{
    int aux;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(array[i] > array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

int main()
{
    int *array;
    //int **matrix;
    //Garantiza que rand() genere numeros al azar
    srand(time(0));
    
    std::cin >> N;
    
    array = new int[N];
    /*
    matrix = new int*[N];
    
    for(int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }
    */
    
    for(int i = 0; i < N; ++i)
    {
        //Genera numeros al azar entre el 0 y el 100
        array[i] = rand() % 101;
    }
    
    /*
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    */
    
    for(int i = 0; i < N; ++i)
    {
        std::cout << array[i] << " ";
    }
    
    OrdenarArreglo(array);
    std::cout << std::endl;
    
    for(int i = 0; i < N; ++i)
    {
        std::cout << array[i] << " ";
    }
    
    /*
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    */
    
    /*
    std::cout << Diagonal(matrix) << std::endl;
    std::cout << TriangularSuperior(matrix) << std::endl;
    std::cout << TriangularInferior(matrix) << std::endl;
    */

    return 0;
}