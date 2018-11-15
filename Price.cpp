//
// Created by Mustafa on 11/14/2018.
//

#include "Price.h"
#include <iostream>
#include <sstream>


Price::Price(int dollar) : m_price(dollar * DOLLAR) {}

Price::Price(int dollars, int cents) : m_price(dollars * DOLLAR + cents) {}

Price::~Price() = default;

std::ostream &operator<<(std::ostream &os, const Price &price1) {
    std::stringstream s1;
    if (price1.m_price % Price::DOLLAR < 10)
        s1 << "0" << price1.m_price % Price::DOLLAR;
    else
        s1 << price1.m_price % Price::DOLLAR;
    os << price1.m_price / Price::DOLLAR << "." << s1.str();
    return os;
}

bool operator==(const Price &lhs, const Price &rhs) {
    return lhs.m_price == rhs.m_price;
}

bool operator!=(const Price &lhs, const Price &rhs) {
    return !(rhs == lhs);
}

bool operator<(const Price &lhs, const Price &rhs) {
    return lhs.m_price < rhs.m_price;
}

bool operator>(const Price &lhs, const Price &rhs) {
    return rhs < lhs;
}

bool operator<=(const Price &lhs, const Price &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Price &lhs, const Price &rhs) {
    return !(lhs < rhs);
}

Price Price::operator-() const {
    return Price(-this->m_price / DOLLAR);

}

Price Price::operator*(const Price &p1) {
    return Price((this->m_price * p1.m_price) / 10000, ((this->m_price * p1.m_price) % 10000) / DOLLAR);
}

Price Price::operator+(const Price &p1) {
    int amount = this->m_price + p1.m_price;
    return Price(amount / DOLLAR, amount % DOLLAR);
}

Price Price::operator-(const Price &p1) {
    int amount = this->m_price - p1.m_price;
    return Price(amount / DOLLAR, amount % DOLLAR);;
}

Price Price::operator/(const Price &p1) {
    return Price((this->m_price / p1.m_price), ((this->m_price % p1.m_price) * DOLLAR) / p1.m_price);
}

Price Price::operator%(const Price &p1) {
    int amount = this->m_price % p1.m_price;
    return Price(amount / DOLLAR, amount % DOLLAR);
}

Price &Price::operator+=(const Price &p1) {
    *this = *this + p1;
    return *this;
}

Price &Price::operator/=(const Price &p1) {
    *this = *this / p1;
    return *this;
}

Price &Price::operator-=(const Price &p1) {
    *this = *this - p1;
    return *this;
}

Price &Price::operator*=(const Price &p1) {
    *this = *this * p1;
    return *this;
}

Price &Price::operator%=(const Price &p1) {
    *this = *this % p1;
    return *this;
}

Price &Price::operator++() {
    *this = *this + Price(1);
    return *this;
}

const Price Price::operator++(int)  {
    Price res;
    res.m_price = m_price + DOLLAR;
    return res;
}

Price &Price::operator--() {
    *this = *this - Price(1);
    return *this;
}

const Price Price::operator--(int) {
    Price res;
    res.m_price = m_price + DOLLAR;
    return res;
}

Price& Price::operator=(const Price &D) = default;

Price::operator double() {
    double dollars = (double) this->m_price / DOLLAR;
    return dollars;
}

Price & Price::operator=(int number) {
    this->m_price = number;
    return *this;
}

