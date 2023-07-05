#ifndef TEST
#define TEST
#include "List.h"
//������������ ����, � ������� ���������� ����� ��� �������� ������ ������ � �������
namespace test
{
	using list::List;
	using list::AddLast;
	using list::FindItem;
	using list::Change;
	using list::AddReverseList;

	static int tests = 0; //���������� ���������� ������
	static int passed_tests = 0; //���������� ������� ���������� ������

	//�-��, ����������� �����������
	int TestConstructor();
	//�-��, ����������� �������
	int TestFunctions();
	//�-��, ���������� ��� �����
	int TestAll();

	// ��������� ��� ������
	namespace constants
	{
		const int val = 10;
		const int val2 = 5;
	}
	//����� ������������
	namespace test_constructor
	{
		int test_const1(); //���� ������������ � ���������� �����������
		int test_const2(); //���� ������������ � ����������� �� ���������
	}
	//����� �������
	namespace test_functions
	{
		int test_AddLast_corr1(); //���� AddLast, ����������� ������
		int test_AddLast_corr2(); //���� AddLast, ������ ������
		int test_FindItem_corr(); //���� FindItem, ��� ������
		int test_FindItem_wrong1(); //���� FindItem, ������������� ������
		int test_FindItem_wrong2(); //���� FindItem, ������ ��� ������
		int test_FindItem_wrong3(); //���� FindItem, ������ ������
		int test_Change_corr(); //���� Change, ��� ������
		int test_Change_wrong1(); //���� Change, ������ ������
		int test_Change_wrong2(); //���� Change, ��� ����� �
		int AddReverseList_corr(); //���� AddReverseList, ��� ������
		int AddReverseList_wrong1(); // ���� AddReverseList, ������ ������ ������
		int AddReverseList_wrong2(); //���� AddReverseList, ������ ������ ������
	}
}
#endif
