#include "Date.h"
#include <sstream>

using namespace std;

Date::Date(const string& dateStr)
    : dateTime(boost::posix_time::time_from_string(dateStr))
{
}

string Date::toddmmyyyy() const {
    const auto date = dateTime.date();

    stringstream ss;
    ss << setfill('0') << setw(2) << date.day() << "/"
       << setfill('0') << setw(2) << date.month().as_number() << "/"
     << date.year();

    return ss.str();
}

string Date::toISODateString() const {
    return to_iso_extended_string(dateTime);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.toISODateString();
    return os;
}