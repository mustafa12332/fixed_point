//
// Created by Mustafa on 11/14/2018.
//

#ifndef FIXED_POINT_PRICE_H
#define FIXED_POINT_PRICE_H


#include <ostream>

class Price {
public:

    /*********************************/

    explicit Price(int m_price = 0);

    Price(int dollars, int cents);

    virtual ~Price();

    /*********************************/

    Price operator-() const;

    Price operator/(const Price &p1);

    Price operator-(const Price &p1);

    Price operator*(const Price &p1);

    Price operator+(const Price &p1);

    Price operator%(const Price &p1);

    /*********************************/

    Price &operator++();

    const Price operator++(int);

    Price &operator--();

    const Price operator--(int);

    /*********************************/

    Price & operator=(const Price &D);

    Price & operator=(int number);

    /*********************************/

    explicit operator double();

    /*********************************/
    Price &operator+=(const Price &p1);

    Price &operator/=(const Price &p1);

    Price &operator-=(const Price &p1);

    Price &operator*=(const Price &p1);

    Price &operator%=(const Price &p1);

    /*********************************/

    friend std::ostream &operator<<(std::ostream &os, const Price &price1);

    /*********************************/

    friend bool operator<(const Price &lhs, const Price &rhs);

    friend bool operator>(const Price &lhs, const Price &rhs);

    friend bool operator<=(const Price &lhs, const Price &rhs);

    friend bool operator>=(const Price &lhs, const Price &rhs);

    friend bool operator==(const Price &lhs, const Price &rhs);

    friend bool operator!=(const Price &lhs, const Price &rhs);

private:
    static const int DOLLAR = 100;
    int m_price;
};


#endif //FIXED_POINT_PRICE_H
