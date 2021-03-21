// CarRentalSystem.cpp : Defines the entry point for the application.
//

#include "CarRentalSystem.h"
#include "Variables.h"

using namespace std;

bool isDatabaseReady(std::ifstream& usernameDb, std::ifstream& passwordDb) {

	bool databaseStatus = true;
	if (usernameDb.is_open() && passwordDb.is_open()) {
		databaseStatus = true;
	}
	else if (!(usernameDb.is_open() && passwordDb.is_open())) {

		databaseStatus = false;
	}
	return databaseStatus;
}

bool isCorrectPassword(std::string username, int password, std::istream& usernameDb, std::istream& userpasswordDb) {

	while (usernameDb >> confirm_username);
	std::cout << "Death " << confirm_username;

	while (userpasswordDb >> confirm_password);
	std::cout << "\nDeath" << confirm_password << singleNewLine;
	return (username == confirm_username && password == confirm_password) ? true : false;

}

void adminstratorTasks() {
	std::cout << "Select one option below" << singleNewLine;
	std::cout << singleTab << "1. Register new user" << singleNewLine;
	std::cout << singleTab << "2. Approve User's car rent request" << singleNewLine;
	std::cout << singleTab << "3. Accept returned car and update system" << singleNewLine;
	std::cout << singleTab << "4. Change/Update admin login password" << singleNewLine;
}

void normalUserTasks() {
	std::cout << "Select one option below" << singleNewLine;
	std::cout << singleTab << "1. View Personal Details/Profile" << singleNewLine;
	std::cout << singleTab << "2. Request to rent a car" << singleNewLine;
	std::cout << singleTab << "3. Return rented car" << singleNewLine;
	std::cout << singleTab << "4. Change password" << singleNewLine;
}

void makeCopyOfCredentials() {
}

void registerUser() {
	std::string userName = " ";
	int userPassword = 0;
	double userDeposit = 0.0;

	std::cout << doubleNewLine << "*****welcome to Customer Registration System*****" << doubleNewLine;
	std::cout << "Create the Customer's username: ";
	std::cin >> userName;
	normal_user_name << userName;
	std::cout << "Create the Customer's password: ";
	std::cin >> userPassword;
	normal_user_password << userPassword;
	std::cout << "Enter user deposit: ";
	std::cin >> userDeposit;
	normal_user_deposit << userDeposit;

	std::cout << doubleNewLine << "Customer's added to the system successfully!" << doubleNewLine;
	std::cout << "Details" << singleNewLine;
	std::cout << "Username: " << userName << singleNewLine;
	std::cout << "Password: " << userPassword << singleNewLine;
	std::cout << "Deposit: " << userDeposit << singleNewLine;
	normal_user_name.close();
	normal_user_password.close();
}

void approveUserCarRequest() {

}

void updateSystem() {

}

void changeAdminPassword() {

}

//User tasks

void viewUserPersonalProfile() {

}

void  requestToRentCar() {

}

void changeUserPassword() {

}

void  returnRentedCar() {

}


void handleSelectedTask(int task, std::string user) {
	if ((task >= 1 && task <= 4) && (user == "admin" || user == "user")) {
		if (task == 1 && user == "admin") {
			registerUser();
		}
		else {
			viewUserPersonalProfile();
		}

		if (task == 2 && user == "admin") {
			approveUserCarRequest();
		}
		else {
			requestToRentCar();
		}
		if (task == 3 && user == "admin") {
			updateSystem();
		}
		else {
			returnRentedCar();
		}
		if (task == 4 && user == "admin") {
			changeAdminPassword();
		}
		else {
			changeUserPassword();
		}
	}

	else {
		std::cout << doubleNewLine << "\aInvalid Task Option!" << doubleNewLine;
	}
}



void adminstratorLogin() {
	std::string adminUsername = " ";
	int adminPassword = 0;
	int selectedAdminTask = 0;
	std::string identity = "admin";


	std::cout << "******WELCOME TO THE ADMIN LOGIN PAGE******" << doubleNewLine;

	std::cout << "Enter your username: ";
	std::cin >> adminUsername;
	std::cout << "Enter your password: ";
	std::cin >> adminPassword;

	if (isDatabaseReady(admin_name, admin_password)) {
		if (!isCorrectPassword(adminUsername, adminPassword, admin_name, admin_password)) {

			std::cout << "Wrong Password or Username";
		}
		else {

			std::cout << doubleNewLine << dashes << doubleNewLine;
			std::cout << "Logged in successfully!";
			std::cout << doubleNewLine;
			adminstratorTasks();
			std::cout << doubleNewLine;
			std::cout << "Enter option to proceed: ";
			std::cin >> selectedAdminTask;
			handleSelectedTask(selectedAdminTask, identity);
		}
	}
	else {
		std::cout << "Can't access the database. Try again later.";
	}
}


void normalUserLogin() {
	std::string username = " ";
	int password = 0;
	int selectedUserTask = 0;
	std::string identity = "user";

	std::cout << "******WELCOME TO THE CUSTOMER LOGIN PAGE******" << doubleNewLine;

	std::cout << "Enter your username: ";
	std::cin >> username;
	std::cout << "Enter your password: ";
	std::cin >> password;
	if (isDatabaseReady(admin_name, admin_password)) {
		if (!isCorrectPassword(username, password, normal_user_name_copy, normal_user_password_copy)) {

			std::cout << "Wrong Password or Username";
		}
		else {

			std::cout << doubleNewLine << dashes << doubleNewLine;
			std::cout << "Logged in successfully!";
			std::cout << doubleNewLine;
			normalUserTasks();
			std::cout << doubleNewLine;
			std::cout << "Enter option to proceed: ";
			std::cin >> selectedUserTask;
			handleSelectedTask(selectedUserTask, identity);
		}
	}
	else {
		std::cout << "Can't access the database. Try again later.";
	}
}


void checkUserType(short userType) {
	if (userType == 1 || userType == 2) {
		userType == 2 ? adminstratorLogin() : normalUserLogin();
	}
	else {
		std::cout << "\aError!! Invalid User";
	}
}

void welcome() {
	short userType = 0;
	std::cout << "******Welcome to the CAR RENTAL SYSTEM******" << doubleNewLine;
	std::cout << "Select your role to proceed:" << singleNewLine;
	std::cout << singleTab << "1. Normal User Login" << singleNewLine;
	std::cout << singleTab << "2. Adminstrator Login" << doubleNewLine;
	std::cout << "Enter role to proceed: ";
	std::cin >> userType;
	std::cout << doubleNewLine << dashes << doubleNewLine;
	checkUserType(userType);
}


int main() {

	welcome();
	return 0;
}