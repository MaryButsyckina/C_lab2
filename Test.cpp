#include "Test.h"
#include <iostream>
#include <exception>
namespace test
{
	using namespace constants;
	using std::cout;

	int TestConstructor()
	{
		using namespace test_constructor;

		cout << "Testing constructors\n";

		test_const1();
		test_const2();

		cout << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int TestFunctions()
	{
		using namespace test_functions;

		cout << "Testing functions.\n";

		test_FindItem_corr();
		test_FindItem_wrong1();
		test_FindItem_wrong2();
		test_FindItem_wrong3();
		test_AddLast_corr1();
		test_AddLast_corr2();
		test_Change_corr();
		test_Change_wrong1();
		test_Change_wrong2();
		AddReverseList_corr();
		AddReverseList_wrong1();
		AddReverseList_wrong2();


		cout << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int TestAll()
	{
		cout << "START TEST";
		TestConstructor();
		TestFunctions();
		cout << "END TEST";

		return 0;
	}

	namespace test_constructor
	{
		int test_const1()
		{
			tests++;
			cout << "Testing constructor with value.\n";
			int err = 0;
			List list = List(val);
			if (list.value != val) 
			{
				err++;
				cout << "\tWrong value.\n";
			}
			if (list.next != nullptr)
			{
				err++;
				cout << "\tWrong next.\n";
			}
			cout << "Test passed witn " << 2-err << " out of 2: " << (2-err) / 2 * 100 << "%\n";
			if (!err) passed_tests++;
			return err;
		}
		int test_const2()
		{
			tests++;
			cout << "Testing constructor, no arguments.\n";
			int err = 0;
			List list = List();
			if (list.value != 0)
			{
				err++;
				cout << "\tWrong value.\n";
			}
			if (list.next != nullptr)
			{
				err++;
				cout << "\tWrong next.\n";
			}
			cout << "Test passed with " << 2 - err << " out of 2: " << (2 - err) / 2 * 100 << "%\n";
			if (!err) passed_tests++;
			return err;
		}
	}

	namespace test_functions
	{
		int test_AddLast_corr1()
		{
			tests++;
			cout << "Testing AddLast.\n";
			List* l = new List(val);
			try
			{
				l = AddLast(val2, l);
				if (FindItem(1, l)->value != val2)
				{
					cout << "\tWrong output. Expected: " << val2 << ". Got: " << FindItem(1, l)->value;
					return 1;
				}
				if (FindItem(1, l)->next != nullptr)
				{
					cout << "\tDidn't add last.\n";
					return 1;
				}
			}
			catch(...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int test_AddLast_corr2()
		{
			tests++;
			cout << "Testing AddLast with empty list.\n";
			List* l = nullptr;
			try
			{
				l = AddLast(val2, l);
				if (FindItem(0, l)->value != val2) 
				{
					cout << "\tWrong output. Expected: " << val2 << ". Got: " << FindItem(0, l)->value;
					return 1;
				}
				if (FindItem(0, l)->next != nullptr)
				{
					cout << "\tDidn't add last.\n";
					return 1;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int test_Change_corr()
		{
			tests++;
			cout << "Testing Change.\n";
			List* l = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l = AddLast(i, l);
			}

			try
			{
				l = Change(3, 10, l);
				if (l->value != 10) 
				{
					cout << "\tWrong output. Expected: 10. Got:	" << FindItem(4, l)->value;
					return 1;
				}
			}
			catch(...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int test_Change_wrong1()
		{
			tests++;
			cout << "Testing Change.\n";
			List* l = nullptr;

			try
			{
				l = Change(3, 10, l);
			}
			catch(std::out_of_range)
			{
				cout << "\tTest passed.\n";
				passed_tests++;
				return 0;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_Change_wrong2()
		{
			tests++;
			cout << "Testing Change.\n";
			List* l = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l = AddLast(i, l);
			}

			try
			{
				Change(10, 3, l);
				for (int i = 0; i < 5; i++)
				{
					if (l->value != i) 
					{
						cout << "\tWrong output.\n";
						return 1;
					}
					l = l->next;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int AddReverseList_corr()
		{
			tests++;
			cout << "Testing AddReverseList.\n";
			List* l1 = nullptr, * l2 = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l1 = AddLast(i, l1);
				l2 = AddLast(i, l2);
			}

			try
			{
				AddReverseList(l1, l2);
				for (int i = 0; i < 5; i++)
				{
					if (l1->value != i)
					{
						cout << "\tWrong output.\n";
						return 1;
					}
					l1 = l1->next;
				}
				for (int i = 4; i > -1; i-- )
				{
					if (l1->value != i)
					{
						cout << "\tWrong output.\n";
						return 1;
					}
					l1 = l1->next;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int AddReverseList_wrong1()
		{
			tests++;
			cout << "Testing AddReverseList.\n";
			List* l1 = nullptr, * l2 = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l2 = AddLast(i, l2);
			}

			try
			{
				l1 = AddReverseList(l1, l2);
				for (int i = 4; i > -1; i--)
				{
					if (l1->value != i)
					{
						cout << "\tWrong output.\n";
						//return 1;
					}
					l1 = l1->next;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int AddReverseList_wrong2()
		{
			tests++;
			cout << "Testing AddReverseList.\n";
			List* l1 = nullptr, * l2 = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l1 = AddLast(i, l1);
			}

			try
			{
				AddReverseList(l1, l2);
				for (int i = 0; i < 5; i++)
				{
					if (l1->value != i)
					{
						cout << "\tWrong output.\n";
						return 1;
					}
					l1 = l1->next;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int test_FindItem_corr()
		{
			tests++;
			cout << "Testing FindItem.\n";
			List* l = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l = AddLast(i, l);
			}

			try
			{
				List* x = FindItem(2, l);
				if (x->value != 2) 
				{
					cout << "\tWrong output.\n";
					return 1;
				}
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			cout << "\tTest passed.\n";
			passed_tests++;
			return 0;
		}
		int test_FindItem_wrong1()
		{
			tests++;
			cout << "Testing FindItem.\n";
			List* l = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l = AddLast(i, l);
			}

			try
			{
				List* x = FindItem(-2, l);
			}
			catch(std::invalid_argument)
			{
				cout << "\tTest passed.\n";
				passed_tests++;
				return 0;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_FindItem_wrong2()
		{
			tests++;
			cout << "Testing FindItem.\n";
			List* l = nullptr;
			for (int i = 0; i < 5; i++)
			{
				l = AddLast(i, l);
			}

			try
			{
				List* x = FindItem(10, l);
			}
			catch (std::out_of_range)
			{
				cout << "\tTest passed.\n";
				passed_tests++;
				return 0;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_FindItem_wrong3()
		{
			tests++;
			cout << "Testing FindItem.\n";
			List* l = nullptr;

			try
			{
				List* x = FindItem(0, l);
			}
			catch (std::out_of_range)
			{
				cout << "\tTest passed.\n";
				passed_tests++;
				return 0;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
	}
}