#include <bits/stdc++.h>
#define max 20
using namespace std;

// Structure of Employee
struct employee {
	string name;
	long int id;
	string designation;
	int exp,age,eff;
	long long salary;
};

int num;
void showMenu();

// Array of Employees to store the
// data in the form of the Structure
// of the Array
employee emp[max], tempemp[max],
	sortemp[max], sortemp1[max];

// Function to enter employee details
void build()
{
	cout<<"\n";
	cout << "Maximum Enteries can be "
		<< max << "\n";

	cout << "Enter the number of Enteries required \n";
	cin >> num;

	if (num > 20) {
		cout << "Maximum number of "
			<< "Enteries are 20\n";
		showMenu();
	}
	cout << "Enter the Employee Details :\n";

	for (int i = 0; i < num; i++) {
		cout << "Name             ";
		cin >> emp[i].name;

		cout << "Employee ID      ";
		cin >> emp[i].id;

		cout << "Designation      ";
		cin >> emp[i].designation;

		cout << "Experience       ";
		cin >> emp[i].exp;

		cout << "Age              ";
		cin >> emp[i].age;
		
		cout << "Salary           ";
		cin >> emp[i].salary;
		
		cout << "Efficiency       ";
		cin >> emp[i].eff; 
		cout<<"\n";
	}

	showMenu();
}

// Function to insert the data into
// given data type
void insert()
{
	cout<<"\n";
	if (num < max) {
		int i = num;
		num++;

		cout << "Enter the information "
			<< "of the Employee\n";
		cout << "Name             ";
		cin >> emp[i].name;

		cout << "Employee ID      ";
		cin >> emp[i].id;

		cout << "Designation      ";
		cin >> emp[i].designation;

		cout << "Experience       ";
		cin >> emp[i].exp;

		cout << "Age              ";
		cin >> emp[i].age;
		
		cout << "Salary           ";
		cin >> emp[i].salary;
		
		cout << "Efficiency       ";
		cin >> emp[i].eff; 
		
		cout<<"\n"; 
	}
	else {
		cout << "Employee Table Full\n";
	}

	showMenu();
}

// Function to delete record at index i
void deleteIndex(int i)
{
	cout<<"\n";
	for (int j = i; j < num - 1; j++) {
		emp[j].name = emp[j + 1].name;
		emp[j].id = emp[j + 1].id;
		emp[j].designation
			= emp[j + 1].designation;
		emp[j].exp = emp[j + 1].exp;
		emp[j].age = emp[j + 1].age;
		emp[j].salary =  emp[j+1].salary;
		emp[j].eff = emp[j+1].eff;
	}
	return;
}

// Function to delete record
void deleteRecord()
{
	cout << "Enter the Employee ID to Delete Record  ";

	int id;

	cin >> id;
	for (int i = 0; i < num; i++) {
		if (emp[i].id == id) {
			deleteIndex(i);
			num--;
			break;
		}
	}
	cout<<"\n";
	showMenu();
}

void searchRecord()
{
	cout<<"\n";
	cout << "Enter the Employee ID to Search Record  ";

	int id;
	cin >> id;

	for (int i = 0; i < num; i++) {

		// If the data is found
		if (emp[i].id == id) {
			cout << "Name         "
				<< emp[i].name << "\n";

			cout << "Employee ID  "
				<< emp[i].id << "\n";

			cout << "Designation  "
				<< emp[i].designation << "\n";

			cout << "Experience   "
				<< emp[i].exp << "\n";

			cout << "Age          "
				<< emp[i].age << "\n";
				
			cout << "Salary       "
				<< emp[i].salary << "\n";
			
			cout << "Efficiency   "
				<<  emp[i].eff << "\n"; 
		
			break;
		}
	}
	cout << "\n";
	showMenu();
}

void calculate(){
	cout<<"\n";
	cout << "Enter the Employee ID to Calculate Increment  ";

	int id;
	cin >> id;

	for (int i = 0; i < num; i++) {

		// If the data is found
		if (emp[i].id == id) {
			if(emp[i].eff >= 60 && emp[i].eff<70){
				emp[i].salary = emp[i].salary + (emp[i].salary * .25);
				cout << "Incremented Salary =    "<< emp[i].salary << "\n";
			}
			else if(emp[i].eff >= 70 && emp[i].eff<80){
				emp[i].salary = emp[i].salary + (emp[i].salary * .30);
				cout << "Incremented Salary =    "<< emp[i].salary << "\n";
			}
			else if(emp[i].eff >= 80 && emp[i].eff<90){
				emp[i].salary = emp[i].salary + (emp[i].salary * .40);
				cout << "Incremented Salary =    "<< emp[i].salary << "\n";
			}
			else if (emp[i].eff >= 90 && emp[i].eff<=100){
				emp[i].salary = emp[i].salary + (emp[i].salary * .50);
				cout << "Incremented Salary =    "<< emp[i].salary << "\n";
			}
			break;
		}
	}
	cout << "\n";
	showMenu();
}

void update(){
	cout<<"\n";
	cout << "Enter the Employee ID to Update Record  ";

	int id;
	cin >> id;
	
	string name;
	string designation;
	int exp,age;
	float salary, eff;

	for (int i = 0; i < num; i++) {

		// If the data is found
		if (emp[i].id == id) {
		cout << "Name             ";
		cin >> name;
		emp[i].name = name;

		cout << "Designation      ";
		cin >> designation;
		emp[i].designation = designation;

		cout << "Experience       ";
		cin >> exp;
		emp[i].exp = exp;

		cout << "Age              ";
		cin >> age;
		emp[i].age = age;
		
		cout << "Salary           ";
		cin >> salary;
		emp[i].salary = salary; 
		
		cout << "Efficiency       ";
		cin >> eff;
		emp[i].eff = eff; 
		
			
			break;
		}
	}
	cout << "\n";
	showMenu();

}

// Function to show menu
void showMenu()
{

	cout<< "*************************  Employee Management System *************************\n\n";

	cout << "                            Build Table                         (1)\n";
	cout << "                            Insert New Entry                    (2)\n";
	cout << "                            Delete Entry                        (3)\n";
	cout << "                            Search a Record                     (4)\n";
	cout << "                            Calculate Annual Salary Increment   (5)\n";
	cout << "                            Update Record                       (6)\n";
	cout << "                            Exit                                (0)\n";
	cout << "*******************************************************************************\n";

	int option;

	// Input Options
	cin >> option;

	// Call function on the bases of the
	// above option
	if (option == 1) {
		build();
	}
	else if (option == 2) {
		insert();
	}
	else if (option == 3) {
		deleteRecord();
	}
	else if (option == 4) {
		searchRecord();
	}
	
	else if (option == 5) {
		calculate();
	}
	
	else if (option == 6) {
		update();
	}
	
	else if (option == 0) {
		return;
	}
	else {
		cout << "WRONG CHOICE! Expected Options are 1/2/3/4/5/6 \n\n";
		showMenu();
	}
}

// Driver Code
int main()
{
	showMenu();
	return 0;
}

