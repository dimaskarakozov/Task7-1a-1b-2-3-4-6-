﻿// task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int q, w=0, e=0, *r, i, j,*t,*y,*mas1,*mas2,*mas3;

	setlocale(LC_ALL, "Russian");
							//Task7 
							//Задание 1 А
	printf("(1) - Одна из задач:\nДан массив ненулевых целых чисел.Определить, сколько раз элементы массива при просмотре от его начала меняют знак.Например, в массиве 10, –4, 12, 56, –4, –89 знак меняется 3 раза.\n В массиве из n элементов числа образуют неубывающую последовательность.Несколько элементов, идущих подряд, равны между собой.Сколько различных чисел имеется в массиве ?");
	printf("\nВведите кол-во чисел в массиве? ");
	scanf_s("%d",&q);//q - кол-во эллементов массива
	r = (int*)malloc(q * sizeof(int)); //выделяем необходимую память
	w = 0;
	for ( i = 0; i < q; i++) {
		scanf_s("%d", &r[i]);//скан чисел; w- сколько раз знак менялся; e - с какого знака начинается и какой сейчас знак

		if (i == 0) 
		{
			if (r[0] >= 0) { e = 1; }
			else { e = -1; }
		}
		else if ( ( (r[i] > 0) && ( e == -1) ) || ( (r[i] < 0) && (e == 1) ) ) {
			
			w = w + 1; e = -e;
		}
		//printf("\n %d  %d\n", r[i], e);

	}
	
		printf("\n%d",w);

		
						//Задание 1 Б
		printf("\n\n\n\nВ массиве из n элементов числа образуют неубывающую последовательность. Несколько элементов, идущих подряд, равны между собой. Сколько различных чисел имеется в массиве? ");
		printf("\nВведите кол-во эллементов в массиве? ");
		scanf_s("%d",&q);
		r = (int*)malloc(q * sizeof(int));  //выделяем необходимую память
		for (i = 0; i < q; i++) {
			scanf_s("%d", &r[i]);
		//q - кол-во эллементов в массиве
		//w - последнее введенное число
		//e - кол-во разных чисел
			
			if (i == 0) { //для первого числа делаем отдельную проверку,чтобы найти w
				w = r[0];
			}
			else if( w == r[i] ){ 
				e = e - 1;
			}
			e=e+1;
			w = r[i];
		}

		printf("\nВсего различных эллементов %d", e);

		


									//задание 2
	printf("\n\n\n\n(2) - Дан массив целых чисел. Рассмотреть отрезки массива (группы идущих подряд чисел), состоящие из нечетных чисел. Получить наибольшую из длин рассматриваемых отрезков.");
	printf("\nВведите кол-во чисел в массиве? ");
	scanf_s("%d", &q);//q - кол-во эллементов массива
	r = (int*)malloc(q * sizeof(int)); //выделяем необходимую память
	e = 1;//т,к, первая проверка идет отдельно
	j = 0; //макс нечетных чисел подрят идущих во всей последовательности
	w = 0;// 1 - нечетное; 2 четное;
	for (i = 0; i < q; i++) {
		scanf_s("%d", &r[i]);
		//q - кол-во эллементов в массиве
		//w - четность последнего числа
		//e - макс нечетных чисел подрят идущих в текущей последовательности
		
		if (i == 0) {
			if (r[0] % 2 == 0)
			{
				w = 2;
			 }
			else {
				w = 1;
			}
		}
		else if ((r[i] % 2 != 0 ) &&( w == 1))
		{
			e = e + 1;
		}
		else if ((r[i] % 2 == 1) && w == 0)
		{
			e = 1;
		}
		else 
		{
			if (e>j)
			{
				j = e;
			}


			e = 1;
			if(w==1){  //меняем четность последнего числа 
				w = w + 1;
			}
			else{
				w = w - 1; 
			}
		}
		//printf("\n%d %d\n",e,j); проверял для себя знач переменных после каждого шага
	}
	if (e > j)
	{
		j = e;
	}
	printf("\nВо всей последовательности макс. длина подрят идущих нечетных чисел равна %d", j);

	



								//Задание 3
printf("\n\n\n\n(2) Удалить из массива все повторяющиеся элементы, оставив их первые вхождения, т. е. в массиве должны остаться только различные элементы.( под удалением элемента массива следует понимать:  исключение этого элемента из массива путем смещения всех следующих за ним элементов влево на 1 позицию;  присвоение последнему элементу массива значения 0.)");
printf("\nВведите кол-во чисел в массиве? ");
scanf_s("%d", &q);//q - кол-во эллементов массива
t = (int*)malloc(q * sizeof(int)); //выделяем необходимую память

for (i = 0; i < q;i++) {
	scanf_s("%d",&t[i]);
			for (int b = 0; b < i; b++) {
				if (t[b] == t[i] && b!= i)
				{
					t[i] = 0;
				}
			}
}


for (i = 1; i < q; i++) {
	for (int m = 1; m < q; m++) {
		if (t[m] != 0 && t[m-1] == 0)
		{
			t[m - 1] = t[m];
			t[m] = 0;
		}
	}
}
for (i = 0; i < q; i++) {printf("%d  ", *&t[i]);}


								//Задание 4
printf("\n\n\n\n(1) - Найти  мах2 в одномерном массиве.( наибольший элемент массива при исключении максимального элемента этого массива; один проход по массиву)");
printf("\nВведите кол-во чисел в массиве? ");
scanf_s("%d", &q);//q - кол-во эллементов массива
y = (int*)malloc(q * sizeof(int)); //выделяем необходимую память
w = 0;//максимальный эллемент
e = 0;// второй эллемент по рамеру после максимального
for (i = 0; i < q; i++) {
	scanf_s("%d", &y[i]);
	if (i == 0) {
		w = y[0];
		e = y[0]; //пусть первый эллемент будет максимальным
	}
	else if (e == w && y[i] < w) {  //проверка,на случай,если первое число наибольшее
		e = y[i];
	}
	else if(y[i] > w) {  //если число наибольшее
		e = w;
		w = y[i];
		

	}
	else if (y[i] > e && y[i]!=w) {  // если число наибольшее после наибольшего

		e = y[i];
		
	}
}

printf("\nСамое большое %d, Второе по убываннию %d ", w,e);



										//Задание 6
printf("\n\n\n\n(2) Написать функцию, объединяющую два упорядоченных массива размером m и n в упорядоченный массив размером m+n (итоговый массив не сортировать)");
printf("\nВведите кол-во чисел в массиве? ");
scanf_s("%d", &q);//q - кол-во эллементов массива 1
mas1 = (int*)malloc(q * sizeof(int)); //выделяем необходимую память
for (i = 0; i < q; i++) {
	scanf_s("%d",&mas1[i]);
}
printf("\nВведите кол-во чисел в массиве? ");
scanf_s("%d", &w);//w - кол-во эллементов массива 2
mas2 = (int*)malloc(w * sizeof(int)); //выделяем необходимую память
for (i = 0; i < w; i++) {
	scanf_s("%d", &mas2[i]);
}

mas3 = (int*)malloc((q * w) * sizeof(int)); //выделяем необходимую память
for (i = 0; i < q; i++)
{
	mas3[i] = mas1[i];
}
for (i = 0; i < w; i++)
{
	mas3[i+q] = mas2[i];
}

for (i = 0; i < q + w; i++) {
	printf("%d ", mas3[i]);
}


	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
