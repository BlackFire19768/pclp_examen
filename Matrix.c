#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Matrix
{
	int row, column;
	double** m;
} Matrix;

Matrix initializare(int row, int column)
{
	Matrix mat;
	mat.row = row;
	mat.column = column;
	mat.m = malloc(sizeof(double*) * row);

	for (int i = 0; i < row; i++)
		mat.m[i] = malloc(sizeof(double) * column);
	
	return mat;
}

void dealocare(Matrix* mat)
{
	for (int i = 0; i < mat->row; i++)
		free(mat->m[i]);
	
	free(mat->m);
}

void citire(Matrix* mat)
{
	for (int i = 0; i < mat->row; i++)
	{
		for (int j = 0; j < mat->column; j++)
		{
			scanf("%lf", &mat->m[i][j]);
		}
	}
}

void afisare(const Matrix* mat)
{
	for (int i = 0; i < mat->row; i++)
	{
		for (int j = 0; j < mat->column; j++)
		{
			printf("%.2f ", mat->m[i][j]);
		}

		printf("\n");
	}
}

void inversare_linii(Matrix* mat, int linie1, int linie2)
{
	double* aux = mat->m[0];
	mat->m[0] = mat->m[1];
	mat->m[1] = aux;
}

void eliminare_linie(Matrix* mat, int linie)
{
	free(mat->m[linie]);
	mat->row -= 1;

	for (int i = linie; i < mat->row; i++)
		mat->m[i] = mat->m[i + 1];
}

double suma_line(const Matrix* mat, int linie)
{
	double suma = 0;
	for (int i = 0; i < mat->column; i++)
		suma += mat->m[linie][i];

	return suma;
}

int main()
{
	int rows, columns;
	printf("Introduceti dimensiunile unei matrice:\n");
	scanf("%d", &rows);
	scanf("%d", &columns);

	Matrix mat = initializare(rows, columns);
	printf("Introduceti valorile elementelor matricei %dx%d:\n", mat.row, mat.column);
	citire(&mat);
	
	afisare(&mat);

	int min_suma = INT_MAX;
	int min_index = 0;
	for (int i = 0; i < mat.row; i++)
	{
		int suma = suma_line(&mat, i);
		printf("Suma liniei %d este %d.\n", i, suma);

		if (suma < min_suma)
		{
			min_index = i;
			min_suma = suma;
		}
	}

	eliminare_linie(&mat, min_index);
	afisare(&mat);
	
	dealocare(&mat);
	
	getchar();
	getchar();
	return 0;
}

