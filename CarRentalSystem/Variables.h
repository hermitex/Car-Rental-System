std::string singleNewLine = "\n";
std::string doubleNewLine = "\n\n";
std::string singleTab = "\t";
std::string dashes = "--------------------------------------------";


//std::string username;
//int userpassword;


std::ifstream admin_name("adminusername.txt");

std::ifstream admin_password("adminpassword.txt");



//Normal User DB

std::ofstream normal_user_name("username.txt", std::ios::app);

std::ofstream normal_user_password("userpassword.txt", std::ios::app);
std::ofstream normal_user_deposit("userpassword.txt", std::ios::app);

std::ifstream normal_user_name_copy("username.txt", std::ios::app);

std::ifstream normal_user_password_copy("userpassword.txt", std::ios::app);


std::string confirm_username = "";
int confirm_password = 0;
