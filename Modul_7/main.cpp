#include <iostream>
#include "IntegerArray.h"

using std::cout;
using std::endl;
int main()
{
	try
	{
		//IntegerArray array1(-1);											// Проверка инициализации контейнера отрицательным значением
		IntegerArray array1(10);
		for (int i(0); i < array1.getLength(); i++)
			array1[i] = i * 2;

		cout << "Array1: " << array1 << endl;
		cout << "Array1 size: " << array1.getLength() << endl;
		//cout << "Array:\n" << array1[11] << endl;						    // Проверка контейнера на выход за пределы диапазона

		IntegerArray array2(array1);										// Инициализация одного контейнера другим
		cout << "Array2: " << array1 << endl;
		cout << "Array2 size: " << array2.getLength() << endl;

		// array1.resize(-1);												// Проверка некорректного изменения размера контейнера
		array1.resize(7);													// Изменение размера контейнера
		cout << "Array1 after resize: " << array1 << endl;
		cout << "Array1 size: " << array1.getLength() << endl;

		array1.resize(10);
		cout << "\nArray1 after resize: " << array1 << endl;
		cout << "\nArray1 size: " << array1.getLength() << endl;

		array2.copyContainerTo(array1);										// Копирование контейнера при одинаковых размерах
		cout << "\nArray1 after copy from Array2: ";
		for (int i(0); i < array1.getLength(); i++)
			cout << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		// array1.findElement(145);											// Проверка поиска элемента по некорректному индексу
		array1.findElement(5);

		//array1.insertBefore(100, 100);									// Проверка вставки элемента в контейнер перед некорректным индексом
		array1.insertBefore(100, 5);
		cout << "\nArray1 after insert: ";
		for (int i(0); i < array1.getLength(); i++)
			cout  << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		//array1.remove(100);												// Проверка удаления элемента с некорректным индексом
		array1.remove(7);
		cout << "\nArray1 after remove: ";
		for (int i(0); i < array1.getLength(); i++)
			cout << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		array1.insertAtBeginning(73);
		cout << "\nArray1 after insert: ";
		for (int i(0); i < array1.getLength(); i++)
			cout << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		array1.insertAtEnd(37);
		cout << "\nArray1 after insert: ";
		for (int i(0); i < array1.getLength(); i++)
			cout << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		array1.erase();
		cout << "\nArray1 after erase: ";
		for (int i(0); i < array1.getLength(); i++)
			cout << array1[i] << " ";
		cout << "\nArray1 size: " << array1.getLength() << endl;

		array2.erase();
		cout << "\nArray2 after erase: ";
		for (int i(0); i < array2.getLength(); i++)
			cout << array2[i] << " ";
		cout << "\nArray2 size: " << array1.getLength() << endl;
	}
	catch (bad_length& bl)
	{
		cout << "\nbad_length caught!" << endl;
		cout << bl .what() << endl;
	}
	catch (bad_range& br)
	{
		cout << "\nbad_range caught!" << endl;
		cout << br.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}