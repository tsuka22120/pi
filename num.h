#ifndef NUM_H
#define NUM_H

#include <vector>

enum class Sign { POSITIVE, NEGATIVE, ZERO };
const int BASE = 100;
const int BASE_DIGITS = 2;

using RADIX_T = long long;

class num {
   private:
    std::vector<RADIX_T> value;
    Sign sign;

   public:
    num();
    Sign getSign() const;
    void setSign(Sign newSign);
    void setValue(RADIX_T val);
    RADIX_T getValue() const;
    void print() const;
    bool isZero() const;
    int compare(const num& other) const;

    friend std::ostream& operator<<(std::ostream& os, const num& n);
    friend std::istream& operator>>(std::istream& is, num& n);

    num& operator+(const num& other);
    num& operator-(const num& other);
    num& operator*(const num& other);
    num& operator/(const num& other);
    num& operator%(const num& other);
    num& operator+=(const num& other);
    num& operator-=(const num& other);
    num& operator*=(const num& other);
    num& operator/=(const num& other);
    num& operator%=(const num& other);
};

num operator+(const num& lhs, const num& rhs);
num operator-(const num& lhs, const num& rhs);
num operator*(const num& lhs, const num& rhs);
num operator/(const num& lhs, const num& rhs);
num operator%(const num& lhs, const num& rhs);

bool operator==(const num& lhs, const num& rhs);
bool operator!=(const num& lhs, const num& rhs);
bool operator<(const num& lhs, const num& rhs);
bool operator<=(const num& lhs, const num& rhs);
bool operator>(const num& lhs, const num& rhs);
bool operator>=(const num& lhs, const num& rhs);

#endif