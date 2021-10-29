#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>

int main()
{
	while (1)
	{
    	int c;

    	puts("1. Matrix");
    	puts("2. Array");
    	puts("0. Выход");
    	scanf("%d", &c);

    	if (c == 1)
    	{
            int m;
        	void *lib = dlopen("./libmatrix.so", RTLD_LAZY);
        	int **(*create)() = dlsym(lib, "create");
        	void (*print)(int**) = dlsym(lib, "print");
        	void (*zsqr)(int**) = dlsym(lib, "zsqr");

        	int **A = (*create)();

        	puts("\nИMatrix");
        	(*print)(A);

        	m=(*zsqr)(A);

        	puts("\nNew");
        	(*print)(A);
            
            puts("Otvet:");
            printf("%d",m);

        	free(A);
        	dlclose(lib);

        	return 0;
    	}
    	else if (c == 2)
    	{
            int m;
        	void *lib = dlopen("./libarray.so", RTLD_LAZY);
        	int **(*create)() = dlsym(lib, "create");
        	void (*print)(int*) = dlsym(lib, "print");
        	void (*zsqr)(int*) = dlsym(lib, "zsqr");

        	int *arr = create();

        	puts("\nArray");
        	(*print)(arr);

        	m=(*zsqr)(arr);

        	puts("\nNew");
        	(*print)(arr);

             puts("Otvet:");
            printf("\n%d\n",m);
            
        	free(arr);
        	dlclose(lib);

        	return 0;
    	}
    	else if (c == 0)
    	{
        	return 0;
    	}
    	else
    	{
        	puts("Неверный пункт меню!");
    	}
	}
}

