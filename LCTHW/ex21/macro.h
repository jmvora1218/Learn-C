
#define jay(print, ...) fprintf(stderr,"[DEBUG] %s:%d:" print "\n",__FILE__, __LINE__, ##__VA_ARGS__)


//https://stackoverflow.com/questions/52891546/what-does-va-args-mean
//https://riptutorial.com/c/example/18583/variadic-arguments-macro
//https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
//https://www.geeksforgeeks.org/fprintf-in-c/
//https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
//https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html