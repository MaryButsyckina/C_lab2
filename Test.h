#ifndef TEST
#define TEST
#include "List.h"
//пространство имен, в котором определены тесты для проверки работы списка и функций
namespace test
{
	using list::List;
	using list::AddLast;
	using list::FindItem;
	using list::Change;
	using list::AddReverseList;

	static int tests = 0; //количество пройденных тестов
	static int passed_tests = 0; //количество успешно пройденных тестов

	//ф-ия, тестирующая конструктор
	int TestConstructor();
	//ф-ия, тестирующая функции
	int TestFunctions();
	//ф-ия, проводящая все тесты
	int TestAll();

	// константы для тестов
	namespace constants
	{
		const int val = 10;
		const int val2 = 5;
	}
	//тесты конструктора
	namespace test_constructor
	{
		int test_const1(); //тест конструктора с указанными аргументами
		int test_const2(); //тест конструктора с аргументами по умолчанию
	}
	//тесты функций
	namespace test_functions
	{
		int test_AddLast_corr1(); //тест AddLast, заполненный список
		int test_AddLast_corr2(); //тест AddLast, пустой список
		int test_FindItem_corr(); //тест FindItem, без ошибок
		int test_FindItem_wrong1(); //тест FindItem, отрицательный индекс
		int test_FindItem_wrong2(); //тест FindItem, индекс вне списка
		int test_FindItem_wrong3(); //тест FindItem, пустой список
		int test_Change_corr(); //тест Change, без ошибок
		int test_Change_wrong1(); //тест Change, пустой список
		int test_Change_wrong2(); //тест Change, нет числа А
		int AddReverseList_corr(); //тест AddReverseList, без ошибок
		int AddReverseList_wrong1(); // тест AddReverseList, первый список пустой
		int AddReverseList_wrong2(); //тест AddReverseList, второй список пустой
	}
}
#endif
