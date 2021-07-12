#include <iostream>
#include "FileManger.h"

using namespace std;

int main()
{
	//Initialize systems
	vector <IncomeObj> listOfIncomeNodes;
	vector <ExpenseObj> listOfExpenseNodes;

	vector <string> listOfExpenses;
	vector <string> listOfIncome;
	
	initializeExpenses(listOfExpenses);
	initializeIncome(listOfIncome);
	initializeListsOfNodes(listOfIncomeNodes, listOfExpenseNodes, listOfExpenses, listOfIncome);

	calculateTotal(listOfIncomeNodes);

	int choice;

	while (1)
	{
		char asci = 178;
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 34; i++)
			cout << asci;
		cout << endl;
		cout << "\t\t\t\t\t" << asci << "   |Monthly expenses program|   " << asci << endl;
		cout << "\t\t\t\t\t" << asci << "--------------------------------" << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [1]Add New Income.             " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [2]Change Monthly Income.      " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [3]View Income Info.           " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [4]Add New Expense.            " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [5]Add to existing Expense.    " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [6]View Expense Info.          " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [7]View Remaing Money.         " << asci << endl;
		cout << "\t\t\t\t\t" << asci << " [8]Exit.                       " << asci << endl;
		cout << "\t\t\t\t\t" << asci << "--------------------------------" << asci << endl;
		cout << "\t\t\t\t\t" << asci << " Choose option:[1/2/3/4/5/6/7/8]" << asci << endl;
		cout << "\t\t\t\t\t" << asci << "--------------------------------" << asci << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i < 34; i++)
			cout << asci;
		cout << endl;
		cin >> choice;
		cout << "\n";
		system("CLS");
		switch (choice)
		{
		case 1:
		{
			addNewIncome(listOfIncome,listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			break;
		}
		case 2:
		{
			changeMontlyIncome(listOfIncome,listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			
			break;
		}
		case 3:
		{
			printIncomeIntoFile(listOfIncomeNodes);
			calculateTotal(listOfIncomeNodes);
			ViewIncomeInfo(listOfIncome);
			break;
		}
		case 4:
		{
			addNewExpenseCategory(listOfExpenses);
			break;
		}
		case 5:
		{
			addExistingExpense(listOfExpenses, listOfIncomeNodes);
			printIncomeIntoFile(listOfIncomeNodes);
			cleanVector(listOfIncomeNodes, listOfExpenseNodes);
			initializeListsOfNodes(listOfIncomeNodes, listOfExpenseNodes, listOfExpenses, listOfIncome);
			break;
		}
		case 6:
		{
			ViewExpenseInfo(listOfExpenses,listOfExpenseNodes);
			break;
		}
		case 7:
		{
			Remaining(listOfIncomeNodes);
			break;
		}
		case 8:
		{
			printIncomeIntoFile(listOfIncomeNodes);
			cleanVector(listOfIncomeNodes, listOfExpenseNodes);
			exit(0);
		}
		default:
		{
			cout << "Not a valid choice::Try Again\n";
			break;
		}
		}

		cout << "\n\n";
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}