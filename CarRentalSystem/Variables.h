/**********************************************************************************************//**
 * @file	C:\Users\User\Desktop\Car Rentsl System\Car Rental System\CarRentalSystem\Variables.h.
 *
 * @brief	Declares the variables class
 **************************************************************************************************/

/** @brief	The single new line */
std::string singleNewLine = "\n";
/** @brief	The double new line */
std::string doubleNewLine = "\n\n";
/** @brief	The single tab */
std::string singleTab = "\t";
/** @brief	The dashes */
std::string dashes = "--------------------------------------------";
std::string stars = "********************************************";

//std::string username;
//int userpassword;


/** @brief	Name of the admin */
std::ifstream admin_name("adminusername.txt");

/** @brief	The admin password */
std::ifstream admin_password("adminpassword.txt", std::ios::app);



/** @brief	Normal User DB */

std::ofstream normal_user_name("username.txt", std::ios::app);

/** @brief	The normal user password */
std::ofstream normal_user_password("userpassword.txt", std::ios::app);
/** @brief	The normal user deposit */
std::ofstream normal_user_deposit("userdeposit.txt", std::ios::app);

/** @brief	The normal user name copy */
std::ifstream normal_user_name_copy("username.txt", std::ios::app);

/** @brief	The normal user password copy */
std::ifstream normal_user_password_copy("userpassword.txt", std::ios::app);
/** @brief	The normal user deposit copy */
std::ifstream normal_user_deposit_copy("userdeposit.txt", std::ios::app);


/** @brief	The confirm username */
std::string confirm_username = "";
/** @brief	The confirm password */
int confirm_password = 0;
