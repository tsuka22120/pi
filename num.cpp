#include "num.h"

#include <iomanip>
#include <iostream>

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
