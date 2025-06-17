#include "num.h"

#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

// コンストラクタ
num::num() : sign(Sign::ZERO), value{0} {}

// 符号を取得
Sign num::getSign() const { return sign; }

// 符号を設定
void num::setSign(Sign newSign) { sign = newSign; }

// 値を設定
void num::setValue(RADIX_T val) {
    value.clear();
    if (val > 0) {
        sign = Sign::POSITIVE;
    } else if (val < 0) {
        sign = Sign::NEGATIVE;
        val = -val;
    } else {
        sign = Sign::ZERO;
    }

    if (val == 0) {
        value.push_back(0);
    } else {
        while (val > 0) {
            value.push_back(val % BASE);
            val /= BASE;
        }
    }
}

// 値を取得（簡易版）
RADIX_T num::getValue() const {
    RADIX_T result = 0;
    for (int i = value.size() - 1; i >= 0; --i) {
        result = result * BASE + value[i];
    }
    if (sign == Sign::NEGATIVE) result *= -1;
    return result;
}

// 出力
void num::print() const {
    if (sign == Sign::ZERO) {
        std::cout << "+ 0" << std::endl;
        return;
    }

    std::cout << (sign == Sign::POSITIVE ? "+ " : "- ");
    for (int i = value.size() - 1; i >= 0; --i) {
        std::cout << std::setfill('0') << std::setw(BASE_DIGITS) <<  value[i] << (i > 0 ? " " : "");
    }
    std::cout << std::endl;
}

bool num::isZero() const {
    return sign == Sign::ZERO;
}

int num::compare(const num& other) const {
    if (sign != other.sign) {
        return (sign == Sign::POSITIVE) ? 1 : -1;
    }

    if (value.size() != other.value.size()) {
        return (value.size() > other.value.size()) ? 1 : -1;
    }

    for (int i = value.size() - 1; i >= 0; --i) {
        if (value[i] != other.value[i]) {
            return (value[i] > other.value[i]) ? 1 : -1;
        }
    }
    return 0; // 同じ値
}

std::ostream& operator<<(std::ostream& os, const num& n) {
    if (n.sign == Sign::ZERO) {
        os << "+ 0";
        return os;
    }

    os << (n.sign == Sign::POSITIVE ? "+ " : "- ");
    for (int i = n.value.size() - 1; i >= 0; --i) {
        os << std::setfill('0') << std::setw(BASE_DIGITS) << n.value[i] << (i > 0 ? " " : "");
    }
    return os;
}

std::istream& operator>>(std::istream& is, num& n) {
    std::string input;
    is >> input;

    if (input == "0") {
        n.setValue(0);
        return is;
    }

    n.value.clear();
    n.sign = (input[0] == '-') ? Sign::NEGATIVE : Sign::POSITIVE;

    int start = (n.sign == Sign::NEGATIVE) ? 1 : 0;
    for (int i = static_cast<int>(input.size()); i > start; i -= BASE_DIGITS) {
        int end = (i < BASE_DIGITS + start) ? start : i - BASE_DIGITS;
        RADIX_T part = std::stoll(input.substr(end, i - end));
        n.value.push_back(part);
    }

    return is;
}

