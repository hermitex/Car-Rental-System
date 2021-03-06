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
 * @fn	std::vector<std::string> returnArrayOfCars(std::ifstream& cars_db)
 *
 * @brief	Inserts cars from cars_db and returns a vector of cars
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param [in,out]	cars_db	The cars database.
 *
 * @returns	A std::vector&lt;std::string&gt;
 **************************************************************************************************/

std::vector<std::string> returnArrayOfCars(std::ifstream& cars_db)
{
    std::string car = " ";
    std::vector<std::string> cars = {};
    while (cars_db)
    {
        if (std::getline(cars_db, car))
            cars.push_back(car);
    }

    return cars;
}

/**********************************************************************************************//**
 * @fn	void displayCars()
 *
 * @brief	Displays the cars described by cars
 *
 * @author	User
 * @date	4/4/2021
 **************************************************************************************************/

void displayCars()
{
    std::vector <std::string> cars;
    std::ifstream cars_db("carsDb.txt", std::ios::app);
    cars = returnArrayOfCars(cars_db);
    int count = 1;
    for (std::string car : cars)
    {
        std::cout << singleTab << count << ". " << car << singleNewLine;
        count++;
    }
    std::cout << singleNewLine;
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
    normal_user_name << userName << singleNewLine;
    std::cout << "Create the Customer's password: ";
    std::cin >> userPassword;
    normal_user_password << userPassword << singleNewLine;
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
 * @fn	bool isValidRenter(std::istream& userDepositdDb)
 *
 * @brief	Query if 'usernameDb' is valid renter
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param [in,out]	userDepositdDb	The user deposit database.
 *
 * @returns	True if valid renter, false if not.
 **************************************************************************************************/

bool isValidRenter(std::istream& userDepositdDb)
{
    int confirm_deposit = 0;

    while (userDepositdDb >> confirm_deposit);

    return confirm_deposit >= 10500 ? true : false;

}

/**********************************************************************************************//**
 * @fn	const std::string currentDateTime()
 *
 * @brief	Current date time
 *
 * @author	User
 * @date	4/4/2021
 *
 * @returns	A const std::string.
 **************************************************************************************************/

const std::string currentDateTime()
{
    time_t  now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

/**********************************************************************************************//**
 * @fn	void approveUserCarRequest(std::string cars)
 *
 * @brief	Approve user car request
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	cars	The cars.
 **************************************************************************************************/

void approveUserCarRequest(std::string cars)
{
    std::ifstream cars_db("requestedCars.txt", std::ios::app);
    std::vector <std::vector <std::string>> requestedCars = {};
    std::vector <std::string> requestedCar = {};
    int balance = 0;
    int action;

    while(normal_user_deposit_copy >> balance)


    requestedCar = returnArrayOfCars(cars_db);

    if(requestedCar.size() > 0)
    {

        std::cout << singleNewLine << "Car Requests" << doubleNewLine;
        std::cout << singleTab << "Car Name: " << requestedCar[0] << doubleNewLine;
        std::cout << singleTab << "Renter: " <<  requestedCar[1]  << doubleNewLine;
        std::cout  << singleTab<< "Balance: " << balance  << doubleNewLine;


        std::cout << "Actions" << doubleNewLine;
        std::cout  << singleTab<< "1. Approve" << singleNewLine;
        std::cout  << singleTab<< "2. Decline" << singleNewLine;
        std::cout << "Choose Action to continue: ";
        if(std::cin >> action)
        {
            if(action == 1)
            {
                std::string approvalDate = " ";
                std::string car = " ";
                std::ofstream clearFile;
                //std::vector <std::string> cars;
                std::ifstream request_car_db("requestedCars.txt", std::ios::app);
                std::ofstream rented_car_db("rentedCars.txt", std::ios::app);
                std::ofstream datesOfApproval("approvalDate.txt", std::ios::app);
                std::vector <std::string> updateCarCollection = {};

                while(request_car_db)
                {

                    if (std::getline(request_car_db, car))
                    {
                        rented_car_db << car << singleNewLine;
                    }

                }



                approvalDate = currentDateTime();

                datesOfApproval << approvalDate;

                std::cout << doubleNewLine <<" Request approved!" << doubleNewLine;
                std::cout << doubleNewLine <<" Approval Date: " << approvalDate  << doubleNewLine;




                std::ifstream car_db("CarsDB.txt", std::ios::app);



                while (car_db)
                {

                    if (std::getline(car_db, car))
                    {
                        if(car != requestedCar[0])
                            updateCarCollection.push_back(car);
                    }

                }

                std::ofstream new_car_db("CarsDB.txt", std::ios::out | std::ios::trunc);
                {
                    std::ofstream new_car_db("CarsDB.txt", std::ios::app);
                    for (std::string car : updateCarCollection) {
                        new_car_db << car << singleNewLine;
                    }
                }


            }
            else
            {
                std::cout << "Request denied!" << doubleNewLine;
            }
        }
        std::ifstream("requestedCars.txt", std::ios::out |  std::ios::trunc);
    }
    else
    {
        std::cout << doubleNewLine << "No Car Requests Yet" << doubleNewLine;
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
    std::string returnedCar;
    int option = 0;
    std::string car = " ";
    std::vector <std::string> carsCollection = {};
    std::ifstream returned_car_db("returnedCars.txt", std::ios::app);
    std::ifstream car_db("CarsDB.txt", std::ios::app);

    while (returned_car_db) {
        if (std::getline(returned_car_db, returnedCar)) {
            returnedCar;
        }
    }

    if (returnedCar.size() > 0) {
        std::cout << doubleNewLine << "Returned Car: " << returnedCar << doubleNewLine;
        carsCollection = returnArrayOfCars(car_db);
        std::cout << "1. Yes" << doubleNewLine;
        std::cout << "2. No" << doubleNewLine;
        std::cout << "Return to collection? ";

        if (std::cin >> option && option > 0 && option < 3) {
            if (option == 1) {
                carsCollection.push_back(returnedCar);
                std::ifstream car_db("CarsDB.txt", std::ios::out | std::ios::trunc);
                std::ofstream new_car_db("CarsDB.txt", std::ios::app);
                std::ifstream returned_car_db("returnedCars.txt", std::ios::out | std::ios::trunc);
                for (std::string car : carsCollection) {
                    new_car_db << car << singleNewLine;
                }
                std::cout << "Success!\nThe Car  collection has been updated.";
            }
            else {
                //
            }
        }
        else {
            std::cout << "\aInvalid option!";
        }
    }
    else {
        std::cout << doubleNewLine <<"There are no returned cars. Check again later." << doubleNewLine;
    }

    //fix this
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
    std::ifstream admin_password_copy(passwordDb, std::ios::app);

    std::cout << "What is the Current password? ";
    std::cin >> oldPassword;
    std::cout << "What is the New password? ";
    std::cin >> newPassword;

    if (isOldPasswordCorrect(oldPassword, admin_password_copy))
    {
        std::ofstream ofs;

        ofs.open(passwordDb, std::ios::out | std::ios::trunc);
        ofs.close();
        std::ofstream admin_password_copy(passwordDb, std::ios::app);

        admin_password_copy << newPassword;

        std::cout << doubleNewLine ;
        std::cout << "Password updated successfully!" << doubleNewLine;
        std::cout << "Your new password is: " << newPassword;
        std::cout << doubleNewLine ;
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

void changeAdminPassword()
{
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

    std::string carName = "None";
    std::string requestCarName = "None";
    std::string car = " ";
    std::string name = " ";

    int balance = 0;
    int password = 0;
    std::ifstream normal_user_name("username.txt", std::ios::app);
    std::ifstream normal_user_password("userpassword.txt", std::ios::app);
    std::ifstream normal_user_deposit("userdeposit.txt", std::ios::app);
    std::ifstream rentedCar("rentedCars.txt", std::ios::app);
    std::ifstream requestedCar("requestedCars.txt", std::ios::app);
    std::vector <std::string> currentCar = {};
    std::vector <std::string> carRequest = {};

    while (normal_user_name >> name);
    while (normal_user_password >> password);
    while (normal_user_deposit >> balance);


    while (rentedCar)
    {
        if(std::getline(rentedCar, car))
        {

            currentCar.push_back(car);
        }
    };

    if(currentCar.size() >= 1)
    {
        carName = currentCar[0];
    }


    while (requestedCar)
    {
        if(std::getline(requestedCar, car))
        {

            carRequest.push_back(car);
        }
    };

    if(carRequest.size() >= 1)
    {
        requestCarName = carRequest[0];

    }

    std::cout <<doubleNewLine;
    std::cout << "Hello, " << name <<"! This is your profile"<< doubleNewLine;
    std::cout << dashes << doubleNewLine;
    std::cout << stars << doubleNewLine;
    std::cout << "Name: " << name << doubleNewLine;
    std::cout << "Balance: " << balance << doubleNewLine;
    std::cout << "Current Car: " << carName << doubleNewLine;//fix it
    std::cout << "Current Request: " << requestCarName << doubleNewLine;
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

void recordRequestedCar(std::string car, std::string renterName)
{
    /** @brief	/** @brief	/** @brief	/** @brief	The rented cars */
    std::ofstream rented_cars("requestedCars.txt", std::ios::app);

    /** @brief	/** @brief	/** @brief	. */
    rented_cars << car << "\n";

    /** @brief	/** @brief	/** @brief	. */
    rented_cars << renterName << "\n";
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
    std::string car = " ";

    int option = 0;
    std::string selectedCar = " ";
    std::vector<std::string> cars = {};
    std::ifstream cars_db("carsDB.txt", std::ios::app);
    std::ifstream rentedCar("rentedCars.txt", std::ios::app);
    std::vector <std::string> confirmCars = {};

    while(rentedCar)
    {
        if(std::getline(rentedCar, car))
        {
            confirmCars.push_back(car);
        }
    }

    if(confirmCars.size() == 0)
    {
        displayCars();

        cars = returnArrayOfCars(cars_db);

        std::cout << "Make a Selection: ";

        if( std::cin >> option && (option >= 1 && option <= cars.size()))
        {

            option--;
            selectedCar = cars[option];
            if (isValidRenter(normal_user_deposit_copy))
            {

                std::string status = "Pending";
                std::cout << singleTab << doubleNewLine << "Success!" << doubleNewLine;
                std::cout << singleTab << "Request: To borrow a " << selectedCar << doubleNewLine;
                std::cout << singleTab << "Status: " << status << doubleNewLine;

                recordRequestedCar(selectedCar, renterName);

            }
            else
            {
                int confirm_deposit = 0;
                std::ifstream normal_user_deposit_copy("userdeposit.txt", std::ios::app);
                while (normal_user_deposit_copy >> confirm_deposit);
                while (normal_user_password_copy >> confirm_deposit);
                std::cout << singleTab << "Request denied! Your balance of " << confirm_deposit
                          << " is insufficient to borrow the " << selectedCar;
            }
        }
        else
        {
            std::cout << doubleNewLine << "We do not have that car in our collection. Select another or come back later" << doubleNewLine;
        }
    }
    else
    {
        std::cout << doubleNewLine << "You haven't returned your last borrow.\nKindly return the car then make another request." << doubleNewLine;
    }



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
    std::ifstream rentedCarsDb("rentedCars.txt", std::ios::app);
    std::ifstream approvalDate("approvalDate.txt", std::ios::app);
    std::ifstream userBalance("userdeposit.txt", std::ios::app);


    std::string returnTime = " ";
    std::string borrowDate = " ";
    int balance = 0;
    const int charge = 3000;
    int option;
    std::string car = " ";
    std::vector <std::string> rentedCar = {};

    while (rentedCarsDb) {
        if (std::getline(rentedCarsDb, car)) {
            rentedCar.push_back(car);
        }
    }


    while (approvalDate >> borrowDate);

    while (userBalance >> balance);


    if (rentedCar.size() > 0) {
        std::cout << doubleNewLine << "Return the: " << rentedCar[0] << "?" << doubleNewLine;

        std::cout << "1. Yes" << singleNewLine;
        std::cout << "2. No" << singleNewLine;

        std::cout << "Enter option to continue: ";
        if (std::cin >> option && option >= 1 && option <= 2) {
            balance -= charge;
            std::ifstream userBalance("userdeposit.txt", std::ios::out | std::ios::trunc);

            std::ofstream userBalancecopy("userdeposit.txt", std::ios::app);
            std::ofstream returned_car_db("returnedCars.txt", std::ios::app);
            returned_car_db << rentedCar[0];
            userBalancecopy << balance;
            returnTime = currentDateTime();
            std::cout << doubleNewLine << "You have returned the: " << rentedCar[0] << " successfully!" << doubleNewLine;
            std::cout << doubleNewLine << "Date borrowed: " << borrowDate << doubleNewLine;
            std::cout << doubleNewLine << "Return Time: " << returnTime << doubleNewLine;
            std::cout << doubleNewLine << "Money Spent: " << charge << doubleNewLine;


            std::ifstream  rentedCarsDb("rentedCars.txt", std::ios::out | std::ios::trunc);
            std::ifstream approvalDate("approvalDate.txt", std::ios::out | std::ios::trunc);
        }
    }
    else {
        std::cout << "You don't have a rented car at the moment.";

    }




}

/**********************************************************************************************//**
 * @fn	void handleSelectedTask(const int task, const std::string user)
 *
 * @brief	Handles the selected task
 *
 * @author	User
 * @date	4/2/2021
 *
 * @param 	task	The task.
 * @param 	user	The user.
 **************************************************************************************************/

void handleSelectedTask(const int task, const std::string user)
{
    if ((task >= 1 && task <= 4) && (user == "admin" || user == "user"))
    {

        if(user == "admin")
        {
            if(task == 1)
            {
                registerUser();
            }
            else if(task == 2)
            {
                approveUserCarRequest("requestedCars.txt");
            }
            else if(task == 3)
            {
                updateSystem();
            }
            else
            {
                changeAdminPassword();
            }
        }
        else
        {
            if(task == 1)
            {
                viewUserPersonalProfile();
            }
            else if(task == 2)
            {
                requestToRentCar();
            }
            else if(task == 3)
            {
                returnRentedCar();
            }
            else
            {
                changeUserPassword();
            }
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
