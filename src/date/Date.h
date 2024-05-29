#ifndef DATE_H
#define DATE_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

class Date {
public:
    explicit Date(const std::string& dateStr);

    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    [[nodiscard]] std::string toddmmyyyy() const;
    [[nodiscard]] std::string toISODateString() const;

private:
    boost::posix_time::ptime dateTime;
};

#endif // DATE_H
