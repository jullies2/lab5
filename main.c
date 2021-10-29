#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int main()
{
	//setlocale(LC_ALL, "Rus");

	while (1)
	{
    	int c;

    	puts("1. Work with Matrix");
    	puts("2. Work with Array");
    	puts("0. Exit");
    	scanf("%d", &c);

    	if (c == 1)
    	{
            int m;
        	void *lib = LoadLibrary("libmatrix.dll");
        	int **(*create)() = GetProcAddress((HINSTANCE)lib, "create");
        	void (*print)(int**) = GetProcAddress((HINSTANCE)lib, "print");
        	int (*zsqr)(int**) = GetProcAddress((HINSTANCE)lib, "zsqr");

        	int **A = (*create)();

        	puts("\nMatrix");
        	(*print)(A);

        	m=(*zsqr)(A);

        	puts("\nNew Matrix");
        	(*print)(A);

            puts("Otvet:");
            printf("%d",m);
            
        	free(A);
        	FreeLibrary((HINSTANCE)lib);
            system("pause");
        	return 0;
    	}
    	else if (c == 2)
    	{
            int m;
        	void *lib = LoadLibrary("libarray.dll");
        	int **(*create)() = GetProcAddress((HINSTANCE)lib, "create");
        	void (*print)(int*) = GetProcAddress((HINSTANCE)lib, "print");
        	int (*zsqr)(int*) = GetProcAddress((HINSTANCE)lib, "zsqr");

        	int *arr = create();

        	puts("\nArray");
        	(*print)(arr);

        	m=(*zsqr)(arr);

        	puts("\nNew Array");
        	(*print)(arr);

            puts("\nOtvet:");
            
            printf("\n%d\n",m);
            
            system("pause");
        	free(arr);
        	FreeLibrary((HINSTANCE)lib);
            
        	return 0;
    	}
    	else if (c == 0)
    	{
        	return 0;
    	}
    	else
    	{
        	puts("Again!");
    	}
	}
    
}
