#include "test_core.h"

using namespace std;

TEST(SMART_CALCULATOR, NUMBERS1) {
    Model model("2 + 3 / 4");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(2. + 3. / 4.));
}
TEST(SMART_CALCULATOR, NUMBERS2) {
    Model model("-3 - 4");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(-3. - 4.));
}
TEST(SMART_CALCULATOR, NUMBERS3) {
    Model model("5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(5.));
}
TEST(SMART_CALCULATOR, NUMBERS4) {
 Model model("(2 + 3 / 4)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string((2. + 3. / 4.)));
}
TEST(SMART_CALCULATOR, NUMBERS5) {
 Model model("2 - -3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(2. - -3.));
}
TEST(SMART_CALCULATOR, NUMBERS6) {
 Model model("+2 + 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(+2. + 3.));
}
TEST(SMART_CALCULATOR, NUMBERS7) {
 Model model("-(1 - 152)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(-(1. - 152.)));
}
TEST(SMART_CALCULATOR, NUMBERS8) {
 Model model("-1 * -1 * (-1 * -1)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(-1. * -1. * (-1. * -1.)));
}
TEST(SMART_CALCULATOR, NUMBERS9) {
 Model model("-1 * -1 * -1");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(-1. * -1. * -1.));
}
TEST(SMART_CALCULATOR, NUMBERS10) {
 Model model("-1 * (10 - -15)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(-25.));
}
TEST(SMART_CALCULATOR, NUMBERS11) {
 Model model("1 - 3 * -1 + 2 / -2 ^ 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(1. -3. * -1. + 2. / -8));
}
TEST(SMART_CALCULATOR, NUMBERS12) {
 Model model("(1 - 5) + (2 * (3 - 5) + (2 * (4 / 8)))");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string((1. - 5.) + (2. * (3. - 5.) + (2. * (4. / 8.)))));
}
TEST(SMART_CALCULATOR, NUMBERS13) {
    Model model("9124.234 + 3849.1239");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(9124.234 + 3849.1239));
}
TEST(SMART_CALCULATOR, NUMBERS14) {
 Model model(".1 / .1");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(.1 / .1));
}
//TEST(SMART_CALCULATOR, NUMBERS15) {
// Model model("1 / 0");
//    model.SmartCalculator();
// ASSERT_EQ(model.GetResult(), "inf");
//}
TEST(SMART_CALCULATOR, NUMBERS16) {
 Model model("0 / 0");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "-nan");
}
TEST(SMART_CALCULATOR, NUMBERS17) {
 Model model("-.9 / -0.3 + (((((128 / 16) * 2) + 3) - 4) / 8)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(-.9 / -0.3 + (((((128. / 16.) * 2.) + 3.) - 4.) / 8.)));
}
TEST(SMART_CALCULATOR, NUMBERS18) {
 Model model("1 - (-4)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(1. - (-4.)));
}
TEST(SMART_CALCULATOR, NUMBERS19) {
 Model model("5 mod 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(2.));
}
TEST(SMART_CALCULATOR, NUMBERS20) {
 Model model("442 mod 35 * 28");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(616.));
}
TEST(SMART_CALCULATOR, NUMBERS21) {
 Model model("442 mod 35 ^ 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(442.));
}
TEST(SMART_CALCULATOR, NUMBERS22) {
 Model model("2893.124 mod 129.324 mod 1.32");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(0.476));
}
TEST(SMART_CALCULATOR, NUMBERS23) {
 Model model("+");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS24) {
 Model model("-");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS25) {
 Model model("*");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS26) {
 Model model("mod");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS27) {
 Model model("mod 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS28) {
 Model model("* 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS29) {
 Model model("3 *");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS30) {
 Model model("- 3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS31) {
 Model model("1.1.2 / 2.1");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS32) {
 Model model("45 * (*28 + 31)");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS33) {
 Model model("-2^2");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(4.));
}
TEST(SMART_CALCULATOR, NUMBERS34) {
 Model model("2^2^3");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(64.));
}
TEST(SMART_CALCULATOR, NUMBERS35) {
 Model model("3,5*2,8");
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(9.8));
}
TEST(SMART_CALCULATOR, NUMBERS36) {
    Model model("123.-123");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(0.));
}
TEST(SMART_CALCULATOR, NUMBERS37) {
    Model model("123*/123");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS38) {
    Model model("-0.25^3");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(-0.015625));
}
TEST(SMART_CALCULATOR, NUMBERS39) {
    Model model(".");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, NUMBERS40) {
    Model model("----++");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}

TEST(SMART_CALCULATOR, X1) {
 Model model("x", 2.5);
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(2.5));
}
TEST(SMART_CALCULATOR, X2) {
 Model model("x + x", 2.5);
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(5.));
}
TEST(SMART_CALCULATOR, X3) {
 Model model("x / x", 2.5);
    model.SmartCalculator();
 ASSERT_EQ(model.GetResult(), to_string(1.));
}
TEST(SMART_CALCULATOR, X4) {
    Model model("x.x", 123);
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, X5) {
    Model model("xx", 123);
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}

TEST(SMART_CALCULATOR, EXP1) {
    Model model("1e5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(1e5));
}
TEST(SMART_CALCULATOR, EXP2) {
    Model model("-1e5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(-1e5));
}
TEST(SMART_CALCULATOR, EXP3) {
    Model model("1e-5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(1e-5));
}
TEST(SMART_CALCULATOR, EXP4) {
    Model model("-1e-5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(-1e-5));
}
TEST(SMART_CALCULATOR, EXP5) {
    Model model("1.e5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), to_string(1.e5));
}
TEST(SMART_CALCULATOR, EXP6) {
    Model model("e");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP7) {
    Model model("1e");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP8) {
    Model model("1-e5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP9) {
    Model model("1e-.5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP10) {
    Model model("1e.5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP11) {
    Model model("e5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EXP12) {
    Model model("e-5");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}

TEST(SMART_CALCULATOR, EMPTY_INPUT_1) {
    Model model(" ");
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}
TEST(SMART_CALCULATOR, EMPTY_INPUT_2) {
    Model model("", 123);
    model.SmartCalculator();
    ASSERT_EQ(model.GetResult(), "ERROR");
}

 TEST(SMART_CALCULATOR, FUNCTIONS1) {
     Model model("cos(1)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.540302));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS2) {
     Model model("cos(1 + cos(cos(3 + 4 * 5) + 10) / 2)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.877367));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS3) {
     Model model("cos(x)", 1.5);
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.070737));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS4) {
     Model model("cos(125 + 90328 / sin(185))");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.999086));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS5) {
     Model model("tan(9009142.324)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.216169));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS6) {
     Model model("atan(3892.1247032)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(1.570539));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS7) {
     Model model("log(3941.1348983123)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(3.595621));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS8) {
     Model model("sqrt(930124.1324903)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(964.429434));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS9) {
     Model model("ln(2089349.12740)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(14.552363));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS10) {
     Model model("-cos(1)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(-0.540302));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS11) {
     Model model("acos(0.92304912)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.394864));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS12) {
     Model model("asin(0.998329140)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(1.512978));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS13) {
     Model model("cos(-)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }
 TEST(SMART_CALCULATOR, FUNCTIONS14) {
     Model model("cos(-1)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.540302));
 }
 TEST(SMART_CALCULATOR, FUNCTIONS15) {
     Model model("cos(*)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }
 TEST(SMART_CALCULATOR, FUNCTIONS16) {
     Model model("cos(*/+-)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }
 TEST(SMART_CALCULATOR, FUNCTIONS17) {
     Model model("cos(cos(1.1.2))");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }
  TEST(SMART_CALCULATOR, FUNCTIONS18) {
     Model model("sqrt(*)");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }

TEST(SMART_CALCULATOR, SET_VALUES) {
     Model model("1 + 3 / 5");
    model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(1.6));
     model.SetValues("cos(125)", 0);
     model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), to_string(0.787715));
     model.SetValues("+", 0);
     model.SmartCalculator();
     ASSERT_EQ(model.GetResult(), "ERROR");
 }