#ifndef CPP3_SMARTCALC_V2_0_TYPE_PREDICATES_H_
#define CPP3_SMARTCALC_V2_0_TYPE_PREDICATES_H_

#include <string>

namespace s21 {

inline bool isX(char c) { return c == 'x' || c == 'X'; }

inline bool isDec(char c) { return (c >= '0' && c <= '9') || isX(c); }

inline bool isFuncChar(char c) {
  return std::string("cstal").find(c) != std::string::npos;
}

inline bool isSign(char c) { return c == '+' || c == '-'; }

inline bool isOp(char c) {
  return std::string("+-*/^").find(c) != std::string::npos;
}

inline bool isMod(std::string::iterator it) {
  return std::string(it, it + 3) == "mod";
}

inline bool isDot(char c) { return c == '.'; }

inline bool isExp(char c) { return c == 'e' || c == 'E'; }

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_TYPE_PREDICATES_H_