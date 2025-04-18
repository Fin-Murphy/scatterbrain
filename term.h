#ifndef __TERM_H__
#define __TERM_H__

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <sstream> 
#include <iomanip>
#include <exception>
#include <stdexcept>

 const int MIN_DD = 1;
 
 const int MIN_YYYY = 0;   // minimum year 
 const int MAX_YYYY = 2121;   // maximum year 
 
 const int MIN_MM = 1;   // minimum month 
 const int MAX_MM = 12;  // maximum month 
 
 const int DEFAULT_YY = MIN_YYYY;  // default year value 
 const int DEFAULT_MM = MIN_MM;    // default month value 
 const int DEFAULT_DD = MIN_DD;    // default day value 
 
 
 const int MIN_HOUR = 0;           // minimum hour 
 const int MAX_HOUR = 24;          // 24:00 is valid for midnight, 00:00 would also be valid
 const int DEFAULT_H = MAX_HOUR;   // default hour
 
 const int MIN_MINUTE = 0;    // minimum minute 
 const int MAX_MINUTE = 59;   // maximum minute 
 const int DEFAULT_M = MIN_MINUTE;     // default minute 






class Date
 {
         // can NOT be implemented in-line 
     friend std::istream& operator>>(std::istream&, Date&);
     friend std::ostream& operator<<(std::ostream&, const Date&);
 
 
 private:
 
     int yyyy; 
     int mm;   
     int dd;   
 public:
    
     Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD); //yyyy, mm, dd
     Date(const Date&);
     void setDate(int, int, int);  //yyyy, mm, dd
     void setDate(const Date&);
     Date& operator=(const Date&);
     int getYear() const;
     int getMonth() const;
     int getDay() const;
     bool operator ==(const Date&) const;
     bool operator !=(const Date&) const;
     bool operator <=(const Date&) const;
     bool operator <(const Date&) const;
     bool operator >=(const Date&) const;
     bool operator >(const Date&) const;
 
 }; //end class Date declaration 


struct Task {
    std::string name = "Task_";
    int val_needed = 1;
    int current_val = 0;
    std::string list = "Basic_Task";
    Date dueDate;
};

 class terminal {

    public:
    std::vector<Task> tasklist;

    terminal();
    ~terminal();

    void termDisp(); 
    void runTime();
    void listAllTasks();
};



 Date::Date(int year,int month, int day) {

    // call method setDate where data validation will be accomplished
    try{
    setDate(year, month, day);
    } catch (...) {
        std::cout << "Could not initialize Date item.\n";
    }

}

std::ostream& operator<<(std::ostream &os, const Date &rhsObj){

    std::string errMessage = "ERROR: in Time class overloaded operator<<\n";
    errMessage += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errMessage);
    }

    os << std::setfill('0');

    os << rhsObj.yyyy;
    os << "/";
    os << std::setw(2) << rhsObj.mm;
    os << "/";
    os << std::setw(2) << rhsObj.dd;

    // set the fill character back to a blank space to prevent really ugly output of other values
    os << std::setfill(' ');

    return os;

}



Date::Date(const Date& otherDate)
{
    try {
    setDate(otherDate);
    } catch (...) {
        std::cout << "Could not initialize Date item.\n";
        throw;
    }

} //END Date class copy constructor


void Date::setDate(int year, int month, int day)
{
    std::ostringstream errStrm;
    errStrm << "ERROR: in method Date::setDate( " 
    << year << ", " 
    << month << ", " 
    << day << " )\n";

    yyyy = MIN_YYYY;
    mm = MIN_MM;
    dd = MIN_DD;

    bool badArguments = false;
	bool badYear = false;
	bool badMonth = false;
    bool badDay = false;

    if ( year < MIN_YYYY || year > MAX_YYYY )
    {
        badYear = true;
        errStrm << "The year value argument (" << year << ") is not valid.\n";
		errStrm << "Valid values are in the range [" << MIN_YYYY << ", " << MAX_YYYY << "].\n";
    }
    else if ( month < MIN_MM || month > MAX_MM )
    {
        badMonth = true;
        errStrm << "The month value argument (" << month << ") is not valid.\n";
		errStrm << "Valid values are in the range [" << MIN_MM << ", " << MAX_MM << "].\n";
    }
    switch(month)  //Switch statement for proper month days ID
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day < MIN_DD || day > 31){
                badDay = true;
                errStrm << "The day value argument (" << day << ") is not valid.\n";
                errStrm << "Valid values are in the range [" 
                << MIN_DD 
                << ", " << "31" << "] for this month.\n";
            }
            break;
        case 2:
            if(day < MIN_DD || day > 28){
                badDay = true;
                errStrm << "The day value argument (" << day << ") is not valid.\n";
                errStrm << "Valid values are in the range [" 
                << MIN_DD << ", " 
                << "28" << "] for this month.\n";
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day < MIN_DD || day > 30){
                badDay = true;
                errStrm << "The day value argument (" << day << ") is not valid.\n";
                errStrm << "Valid values are in the range [" 
                << MIN_DD << ", " 
                << "30" << "] for this month.\n";
            }
            break;
    }

    badArguments = badArguments || badYear || badMonth || badDay;
    if (badArguments)
    {
        errStrm << "Year set to MIN_YYYY (" << MIN_YYYY << "), ";
        errStrm << "Month set to MIN_MM (" << MIN_MM << "), ";
        errStrm << "Day set to MIN_DD (" << MIN_DD << ")\n";
        std::string errMessageText = errStrm.str();

        throw std::invalid_argument(errMessageText);
    }


    yyyy = year;
    mm = month;
    dd = day;


} //END member function setDate



void Date::setDate(const Date &otherDate)
{
    try{
        *this = otherDate;
    } catch (...){throw;}

} //END overloaded Data class setDate function



int Date::getDay() const
{
	return dd; 
}


int Date::getMonth() const{
    return mm;
}

int Date::getYear() const {
    return yyyy;
}


Date& Date::operator=(const Date& rhsObj)
{
	if (this != &rhsObj)
    {
        try{setDate(rhsObj.yyyy, rhsObj.mm, rhsObj.dd);}
        catch(...){throw std::invalid_argument("Failed assignment");}
        
    } else {std::cout << "WARNING: SELF ASSIGNMENT" << std::endl;}
	
    return *this;

} //END overload assignment operator for Date


std::istream& operator>>(std::istream &in, Date &rhsObj){

    char ch;
    int year = -1;
    int month = -1;
    int day = -1;
    std::string errMessage = "";
    bool streamFailed = false;

    errMessage = "ERROR: in Date class overloaded operator>>\n";
    errMessage += "the input stream is in a failed state, no processing can take place...\n";
    if (!in)
    {
        throw std::invalid_argument(errMessage);
    }

    try
    {   
        streamFailed = false;

        in >> month; 
        // if (!in) { streamFailed = true; }

        in >> ch; 
        // if (!in) { streamFailed = true; }

        in >> day; 
        // if (!in) { streamFailed = true; }

        in >> ch; 
        // if (!in) { streamFailed = true; }

        in >> year; 
        // if (!in) { streamFailed = true; }
    

        if(streamFailed)
        {
            errMessage = "WARNING: In Date class overloaded operator>>\n";
            errMessage += "the input stream entered a failed state during processing. ";
            errMessage += "Possible attempt to read past end of file, ";
            errMessage += "time object data members not updated.\n";
            throw std::invalid_argument(errMessage);
        }

        rhsObj.setDate(year, month, day); // call setTime method where validation will take place
        
    } // END outer try block
    catch (std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Date class overloaded operator>>\n";
        std::cout << e.what() << std::endl;
        // do not allow processing to continue, re-throw
        throw;
    }   
    catch (std::runtime_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Date class overloaded operator>>\n";
        std::cout << e.what() << std::endl;
        throw;

    }
    catch (std::logic_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught logic_error exception in Date class overloaded operator>>\n";
        std::cout << e.what() << std::endl;
        throw;

    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Date class overloaded operator>>\n";
        throw;
    }

    return in;
}






bool Date::operator==(const Date& rhsObj) const
{

    bool answer = true;
	
	if (this->yyyy != rhsObj.yyyy)
		answer = false;
	
	if (this->mm != rhsObj.mm)
		answer = false;

    if (this->dd != rhsObj.dd)
		answer = false;
	
    return answer;


}

bool Date::operator!=(const Date& rhsObj) const
{
    return !( *this == rhsObj );
}


bool Date::operator<=(const Date& rhsObj) const
{
    bool answer = false;

    if ( *this == rhsObj )
    {
        answer = true;
    }
    else if ( this->yyyy < rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm == rhsObj.mm) && (this->dd < rhsObj.dd))
    {
        answer = true;
    }

    return answer;
}


bool Date::operator<(const Date& rhsObj) const
{
    bool answer = false;

    if ( *this == rhsObj )
    {
        answer = false;
    }
    else if ( this->yyyy < rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm == rhsObj.mm) && (this->dd < rhsObj.dd))
    {
        answer = true;
    }

    return answer;

}


bool Date::operator>=(const Date& rhsObj) const 
{
    bool answer = false;

    if ( *this == rhsObj )
    {
        answer = true;
    }
    else if ( this->yyyy > rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm == rhsObj.mm) && (this->dd > rhsObj.dd))
    {
        answer = true;
    }

    return answer;
}


bool Date::operator>(const Date& rhsObj) const //INCORRECT IMP REWORK
{

   bool answer = false;

    if ( *this == rhsObj )
    {
        answer = false;
    }
    else if ( this->yyyy > rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm == rhsObj.mm) && (this->dd > rhsObj.dd))
    {
        answer = true;
    }

    return answer;

}


#endif