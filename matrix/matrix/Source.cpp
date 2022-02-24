#include <iostream>

//созание ячеек двумерного динамического массива
void CreateDinDArr(int ** arr,const int rows,const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
} 
//заполнение ячеек двумерного динамического массива рандомными числами
void FillDinDArr(int** arr, const int R, const int C)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = rand() % 10 + 1;
		}
	}
}
//вывод на экран двумерного динамического массива
void PrintDinDArr(int** arr, const int R, const int C)
{
	std::cout << std::endl;
	for (int i = 0; i < R; i++)
	{
		for (int  j = 0; j < C; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
//удаление двумерного динамического массива
void DelDinDArr(int** arr, const int R)
{
	for (int i = 0; i < R; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


/////Перегрузка для кв. матриц,функция работают также//////
void CreateDinDArr(int** arr, const int N)
{

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}
}
void FillDinDArr(int** arr, const int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 2 + 1;
		}
	}
}
void PrintDinDArr(int** arr, const int N)
{
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
////////////////////////////////////

//функция для умножения матриц
void MultiplyMatrix(int** arrA, int** arrB, const int cols1, const int cols2, const int rows1)
{

	std::cout << "\n";
	std::cout << "Результат: " << std::endl;
	std::cout << "\n";

	int** arrC = new int* [rows1];
	for (int i = 0; i < rows1; i++)
	{
		arrC[i] = new int[cols2];
		for (int j = 0; j < cols2; j++)
		{
			arrC[i][j] = 0;
			for (int k = 0; k < cols1; k++)
				arrC[i][j] += arrA[i][k] * arrB[k][j];
			std::cout << arrC[i][j] << "\t";
		}
		std::cout << "\n";
		std::cout << "\n";
	}
}
//функция для удаления столбца и строки
void newMatrix(int** arrA, int **arrANew,int ro,int co,int& size)
{
	int DelCol{ 0 }, DelRow{ 0 }; // строка, столбец

	for (int i = 0; i < size-1; i++)
	{
		if (ro == i)
			DelRow = 1;

		DelCol = 0;
		for (int j = 0; j < size-1; j++)
		{
			if (co == j)
				DelCol = 1;

			arrANew[i][j] = arrA[i + DelRow][j + DelCol];
		}
	}
}
//функция нахождения определителя
int Det(int** arrA, int size)
{
	int detA{ 0 };
	int degree{ 1 };


	int** arrANew = new int* [size - 1];


	if (size < 1)
		return 0;

	if (size == 1)
		return arrA[0][0];

	if (size == 2)
		return arrA[0][0] * arrA[1][1] - arrA[0][1] * arrA[1][0];

	else
	{
		CreateDinDArr(arrANew, size - 1);

		for (int k = 0; k < size; k++)
		{
			newMatrix(arrA, arrANew, 0, k, size);

			detA += degree * arrA[0][k] * Det(arrANew, size - 1);
			degree *= -1;
		}
		
		DelDinDArr(arrANew, size-1);
	}

	return detA;


}


//////Задача 1 Умножение матрицы//////
void numberBer()
{
	int rows1{ 0 };
	int cols1{ 0 };

	std::cout << "Введите количество строк Матрицы A\t: ";
	std::cin >> rows1;
	std::cout << "Введите количество столбцов Матрицы A\t: ";
	std::cin >> cols1;

	int rows2{ 0 };
	int cols2{ 0 };



	std::cout << "Введите количество строк Матрицы B\t: ";
	std::cin >> rows2;
	std::cout << "Введите количество столбцов Матрицы B\t: ";
	std::cin >> cols2;

	if(rows1!=cols2)
	{
		std::cout << "Ошибка!";
	}

	else
	{
		int** arrA = new int* [rows1];
		int** arrB = new int* [rows2];
	

		CreateDinDArr(arrA, rows1, cols1);
		CreateDinDArr(arrB, rows2, cols2);

		FillDinDArr(arrA, rows1, cols1);
		FillDinDArr(arrB, rows2, cols2);


		PrintDinDArr(arrA, rows1, cols1);
		PrintDinDArr(arrB, rows2, cols2);


		MultiplyMatrix(arrA, arrB, cols1, cols2, rows1);

		

		DelDinDArr(arrA, rows1);
		DelDinDArr(arrB, rows2);

	}
}
//////////////////////////////////////

//////Задача 2 Найти определитель//////
void numberIke()
{
	int size{ 1 };
	std::cout << "Введите размерность матрицы: ";
	std::cin >> size;

	int** arrA = new int* [size];


	CreateDinDArr(arrA, size);


	FillDinDArr(arrA,size);
	PrintDinDArr(arrA, size);

	std::cout << "\n";
	std::cout << Det(arrA, size);
	
	DelDinDArr(arrA, size);

}


int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));

	//numberBer();
	//numberIke();

	return 0;
}