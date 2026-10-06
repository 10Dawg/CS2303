#include <iostream>
#include <string>

class CSClass {
    private:
        std::string name;
        int size;
        int courseNumber;

    public:
        
		/*****************************************
		*  CSClass(std::string n, int s, int c)
		*  Constructor to initialize member variables with provided values
		*  Parameters:
		*   n - Name of the class
		*   s - Size of the class
		*   c - Course number
		*****************************************/
        CSClass(std::string n, int s, int c) : name(n), size(s), courseNumber(c) {}

		/*****************************************
		*  CSClass()
		*  Constructor to initialize member variables to default values
		*****************************************/
		CSClass() : name(""), size(0), courseNumber(0) {}

		/*****************************************
		*  void setClassDetails(std::string n, int s, int c);
		*  sets the member variables of the class
		*  Parameters:
		*   n - new name of the class
		*   s - new size of the class
		*   c - new course number
		*****************************************/
		void setClassDetails(std::string n, int s, int c);

		/*****************************************
		*  void display();
		*  Displays the class at the terminal in the following format
		*  Class Name: Introduction to Program Design
		*	Class Size: 200
		*	Course Number: 1101
		*****************************************/
        void display();
		
		/*****************************************
		*  void setName(std::string n);
		*  sets the name of the object
		*  Parameters:
		*		n: the new name
		*****************************************/
		void setName(std::string n);
		
		/*****************************************
		*  void setNumber(int num);
		*  sets the course number
		*  Parameters:
		*		num: the new course number
		*****************************************/
		void setNumber(int num);
		
		/*****************************************
		*  void setSize(int newSize);;
		*  sets the course size
		*  Parameters:
		*		newSize: the new course size
		*****************************************/
		void setSize(int newSize);
		
		/*****************************************
		*  std::string getName();
		*  Returns the name
		*****************************************/
		std::string getName();
		
		/*****************************************
		*  std::string getNumber();
		*  Returns the course number
		*****************************************/
		int getNumber();
		
		/*****************************************
		*  std::string getSize();
		*  Returns the course size
		*****************************************/
		int getSize();

};