// CarRentalSystem.cpp : Defines the entry point for the application.
//
/**
* AUTHORS:
* Haron Masebu
* Yusuf Ali
* Tiberius Mairura
*/

#include "CarRentalSystem.h"
#include "Variables.h"

using namespace std;

/**********************************************************************************************//**
 * @fn	bool isDatabaseReady(std::ifstream& usernameDb, std::ifstream& passwordDb)
 *
 * @brief	Query if 'usernameDb' is database ready
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param [in,out]	usernameDb	The username database.
 * @param [in,out]	passwordDb	The password database.
 *
 * @returns	True if database ready, false if not.
 **************************************************************************************************/

bool isDatabaseReady(std::ifstream& usernameDb, std::ifstream& passwordDb)
{

    bool databaseStatus = true;
    if (usernameDb.is_open() && passwordDb.is_open())
    {
        databaseStatus = true;
    }
    else if (!(usernameDb.is_open() && passwordDb.is_open()))
    {

        databaseStatus = false;
    }
    return databaseStatus;
}

/**********************************************************************************************//**
 * @fn	bool isCorrectPassword(std::string username, int password, std::istream& usernameDb, std::istream& userpasswordDb)
 *
 * @brief	Query if this object is correct password
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 		  	username	  	The username.
 * @param 		  	password	  	The password.
 * @param [in,out]	usernameDb	  	The username database.
 * @param [in,out]	userpasswordDb	The userpassword database.
 *
 * @returns	True if correct password, false if not.
 **************************************************************************************************/

bool isCorrectPassword(std::string username, int password, std::istream& usernameDb, std::istream& userpasswordDb)
{

    while (usernameDb >> confirm_username);
    while (userpasswordDb >> confirm_password);
    return (username == confirm_username && password == confirm_password) ? true : false;

}

/**********************************************************************************************//**
 * @fn	void adminstratorTasks()
 *
 * @brief	Adminstrator tasks
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void adminstratorTasks()
{
    std::cout << "Select one option below" << singleNewLine;
    std::cout << singleTab << "1. Register new user" << singleNewLine;
    std::cout << singleTab << "2. Approve User's car rent request" << singleNewLine;
    std::cout << singleTab << "3. Accept returned car and update system" << singleNewLine;
    std::cout << singleTab << "4. Change/Update admin login password" << singleNewLine;
}

/**********************************************************************************************//**
 * @fn	void normalUserTasks()
 *
 * @brief	Normal user tasks
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void normalUserTasks()
{
    std::cout << "Select one option below" << singleNewLine;
    std::cout << singleTab << "1. View Personal Details/Profile" << singleNewLine;
    std::cout << singleTab << "2. Request to rent a car" << singleNewLine;
    std::cout << singleTab << "3. Return rented car" << singleNewLine;
    std::cout << singleTab << "4. Change password" << singleNewLine;
}

/**********************************************************************************************//**
 * @fn	void registerUser()
 *
 * @brief	Administrator Tasks
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void registerUser()
{
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
    //normal_user_deposit << userDeposit;

    std::cout << doubleNewLine << "Customer's added to the system successfully!" << doubleNewLine;
    std::cout << "Details" << singleNewLine;
    std::cout << "Username: " << userName << singleNewLine;
    std::cout << "Password: " << userPassword << singleNewLine;
    std::cout << "Deposit: " << userDeposit << singleNewLine;
    normal_user_name.close();
    normal_user_password.close();
}

/**********************************************************************************************//**
 * @fn	bool isValidRenter(std::istream& usernameDb, std::istream& userpasswordDb, std::istream& userDepositdDb)
 *
 * @brief	Query if 'usernameDb' is valid renter
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param [in,out]	usernameDb	  	The username database.
 * @param [in,out]	userpasswordDb	The userpassword database.
 * @param [in,out]	userDepositdDb	The user deposit database.
 *
 * @returns	True if valid renter, false if not.
 **************************************************************************************************/

bool isValidRenter(std::istream& usernameDb, std::istream& userpasswordDb, std::istream& userDepositdDb)
{
    int confirm_deposit = 0;

    while (usernameDb >> confirm_username);
    while (userpasswordDb >> confirm_password);
    while (userDepositdDb >> confirm_deposit);
    std::cout << confirm_username << "\t" << confirm_password << "\t" << confirm_deposit << "\t";

    return (confirm_username != " " && confirm_password != 0 && confirm_deposit >= 10500) ? true : false;

}

/**********************************************************************************************//**
 * @fn	void approveUserCarRequest()
 *
 * @brief	Approve user car request
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void approveUserCarRequest()
{
    if (isValidRenter(normal_user_name_copy, normal_user_password_copy, normal_user_deposit_copy))
    {
        std::cout << "Your request has been accepted!";

    }
    else
    {
        std::cout << "Request denied!";
    }
}

/**********************************************************************************************//**
 * @fn	void updateSystem()
 *
 * @brief	Updates the system
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void updateSystem()
{

}

/**********************************************************************************************//**
 * @fn	bool isOldPasswordCorrect(int oldPassword, std::istream& userpasswordDb)
 *
 * @brief	Validate old password
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 		  	oldPassword   	The old password.
 * @param [in,out]	userpasswordDb	The userpassword database.
 *
 * @returns	True if old password correct, false if not.
 **************************************************************************************************/

bool isOldPasswordCorrect(int oldPassword, std::istream& userpasswordDb)
{
    while (userpasswordDb >> confirm_password);

    return (oldPassword == confirm_password) ? true : false;
}

/**********************************************************************************************//**
 * @fn	void changePassword(std::string passwordDb)
 *
 * @brief	Change password
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	passwordDb	The password database.
 **************************************************************************************************/

void changePassword(std::string passwordDb)
{
    int oldPassword = 0;
    int newPassword = 0;

    std::cout << "What is the Current password? ";
    std::cin >> oldPassword;
    std::cout << "What is the New password? ";
    std::cin >> newPassword;

    if (isOldPasswordCorrect(oldPassword, admin_password))
    {
        std::ofstream ofs;

        ofs.open(passwordDb, std::ios::out | std::ios::trunc);
        ofs.close();
        std::ofstream admin_password_copy(passwordDb, std::ios::app);

        admin_password_copy << newPassword;


        std::cout << "Password updated successfully!";
    }
    else
    {
        std::cout << "The current password does not match what we have.";
    }
}

/**********************************************************************************************//**
 * @fn	void changeAdminPassword()
 *
 * @brief	Change admin password
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void changeAdminPassword(){
    changePassword("adminpassword.txt");
}

/**********************************************************************************************//**
 * @fn	void viewUserPersonalProfile()
 *
 * @brief	View user profile
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void viewUserPersonalProfile()
{
    std::string currentCar = " ";
    std::string name = " ";
    int balance = 0;
    int password = 0;
    std::ifstream normal_user_name("username.txt", std::ios::app);
    std::ifstream normal_user_password("userpassword.txt", std::ios::app);
    std::ifstream normal_user_deposit("userdeposit.txt", std::ios::app);

    while (normal_user_name >> name);
    while (normal_user_password >> password);
    while (normal_user_deposit >> balance);

    std::cout <<doubleNewLine;
    std::cout << "Hello, " << name <<"!This is your profile"<< doubleNewLine;
    std::cout << dashes << doubleNewLine;
    std::cout << stars << doubleNewLine;
    std::cout << "Name: " << name << doubleNewLine;
    std::cout << "Balance: " << balance << doubleNewLine;
    std::cout << "Current Car: " << doubleNewLine;
    std::cout << "Password: " << password << doubleNewLine;
    std::cout << dashes << doubleNewLine;
    std::cout << stars << doubleNewLine;

}

/**********************************************************************************************//**
 * @fn	void recordRequestedCar(std::string car, std::string renterName)
 *
 * @brief	Record requested car
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	car		  	The car.
 * @param 	renterName	Name of the renter.
 **************************************************************************************************/

void recordRequestedCar(std::string car, std::string renterName){
    /** @brief	The rented cars */
    std::ofstream rented_cars("rentedCars.txt", std::ios::app);
    /** @brief	. */
    rented_cars << car << "\n";
    /** @brief	. */
    rented_cars << renterName;
}

/**********************************************************************************************//**
 * @fn	void requestToRentCar()
 *
 * @brief	Request to rent car
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void  requestToRentCar()
{
    std::ifstream normal_user_name("username.txt", std::ios::app);
    std::string name = " ";
    while(normal_user_name >> name);
    std::string renterName  = name;
    std::vector<std::string> cars = {};
    int option = 0;
    std::string selectedCar = " ";
    int count = 1;
    std::string car = " ";
    std::ifstream cars_db("carsDB.txt", std::ios::app);

    while (cars_db)
    {
        if (std::getline(cars_db, car))
        {
            cars.push_back(car);
            std::cout << count << ". " << car;
            count++;
        }
        std::cout << singleNewLine;
    }

    std::cout << "Make a Selection: ";

    if( std::cin >> option && (option != -1 && option <= cars.size()))
    {
        option--;
        selectedCar = cars[option];
        std::cout << doubleNewLine << "Success!" << doubleNewLine;
        std::cout <<"You have requested to borrow a " << selectedCar << doubleNewLine;
        std::cout << "Your request will be granted shortly" << doubleNewLine;
    }
    else
    {
        std::cout << doubleNewLine << "We do not have that car in our collection" << doubleNewLine;
    }

    recordRequestedCar(selectedCar, renterName);
}

/**********************************************************************************************//**
 * @fn	void changeUserPassword()
 *
 * @brief	Change user password
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void changeUserPassword()
{
    changePassword("userpassword.txt");
}

/**********************************************************************************************//**
 * @fn	void returnRentedCar()
 *
 * @brief	Returns rented car
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void  returnRentedCar()
{

}

/**********************************************************************************************//**
 * @fn	void handleSelectedTask(int task, std::string user)
 *
 * @brief	Handles the selected task
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	task	The task.
 * @param 	user	The user.
 **************************************************************************************************/

void handleSelectedTask(int task, std::string user)
{
    if ((task >= 1 && task <= 4) && (user == "admin" || user == "user"))
    {
        if (task == 1 && user == "admin")
        {
            registerUser();
        }
        else
        {
            viewUserPersonalProfile();
        }

        if (task == 2 && user == "admin")
        {
            approveUserCarRequest();
        }
        else
        {
            requestToRentCar();
        }
        if (task == 3 && user == "admin")
        {
            updateSystem();
        }
        else
        {
            returnRentedCar();
        }
        if (task == 4 && user == "admin")
        {
            changeAdminPassword();
        }
        else
        {
            changeUserPassword();
        }
    }

    else
    {
        std::cout << doubleNewLine << "\aInvalid Task Option!" << doubleNewLine;
    }
}

/**********************************************************************************************//**
 * @fn	void adminstratorLogin()
 *
 * @brief	Adminstrator login
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void adminstratorLogin()
{
    std::string adminUsername = " ";
    int adminPassword = 0;
    int selectedAdminTask = 0;
    std::string identity = "admin";


    std::cout << "******WELCOME TO THE ADMIN LOGIN PAGE******" << doubleNewLine;
    std::cout << "Enter your username: ";
    std::cin >> adminUsername;
    std::cout << "Enter your password: ";
    std::cin >> adminPassword;

    if (isDatabaseReady(admin_name, admin_password))
    {
        if (!isCorrectPassword(adminUsername, adminPassword, admin_name, admin_password))
        {

            std::cout << "Wrong Password or Username";
        }
        else
        {

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
    else
    {
        std::cout << "Can't access the database. Try again later.";
    }
}

/**********************************************************************************************//**
 * @fn	void normalUserLogin()
 *
 * @brief	Normal user login
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void normalUserLogin()
{
    std::string username = " ";
    int password = 0;
    int selectedUserTask = 0;
    std::string identity = "user";

    std::cout << "******WELCOME TO THE CUSTOMER LOGIN PAGE******" << doubleNewLine;

    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    if (isDatabaseReady(admin_name, admin_password))
    {
        if (!isCorrectPassword(username, password, normal_user_name_copy, normal_user_password_copy))
        {

            std::cout << "Wrong Password or Username";
        }
        else
        {

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
    else
    {
        std::cout << "Can't access the database. Try again later.";
    }
}

/**********************************************************************************************//**
 * @fn	void checkUserType(int short userType)
 *
 * @brief	Check user type
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	userType	Type of the user.
 **************************************************************************************************/

void checkUserType(int short userType)
{
    if (userType == 1 || userType == 2)
    {
        userType == 2 ? adminstratorLogin() : normalUserLogin();

    }
    else
    {
        std::cout << singleTab << "\aError!! Invalid User" << singleNewLine;

    }
}

/**********************************************************************************************//**
 * @fn	void welcome()
 *
 * @brief	Welcomes this object
 *
 * @author	User
 * @date	4/2/2021
 **************************************************************************************************/

void welcome()
{
    int trial = 0;
    int short userType = 0;
    std::cout << "******Welcome to the CAR RENTAL SYSTEM******" << doubleNewLine;

    std::cout << "Select your role to proceed:" << singleNewLine;
    std::cout << singleTab << "1. Normal User Login" << singleNewLine;
    std::cout << singleTab << "2. Adminstrator Login" << doubleNewLine;
    std::cout << "Enter role to proceed: ";
    std::cin >> userType;
    std::cout << doubleNewLine << dashes << doubleNewLine;
    checkUserType(userType);


}

/**********************************************************************************************//**
 * @fn	int main()
 *
 * @brief	Main entry-point for this application
 *
 * @author	User
 * @date	4/2/2021
 *
 * @returns	Exit-code for the process - 0 for success, else an error code.
 **************************************************************************************************/

int main()
{


    welcome();


    return 0;
}
