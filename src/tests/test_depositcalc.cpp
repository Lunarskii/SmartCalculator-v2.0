#include "test_core.h"

TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_OFF) {
    Model model(10000, 12, 10, 35, 12, false);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1000, 1e-1);
    ASSERT_NEAR(model.getAmount(), 10000, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_ON) {
    Model model(10000, 12, 10, 35, 12, true);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1049, 1e1);
    ASSERT_NEAR(model.getAmount(), 11049, 1e2);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_OFF2) {
    Model model(1000000, 12, 10, 35, 12, false);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 100000, 1e-1);
    ASSERT_NEAR(model.getAmount(), 1000000, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_ON2) {
    Model model(1000000, 12, 10, 35, 12, true);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 104713.06, 1e-1);
    ASSERT_NEAR(model.getAmount(), 1104713.06, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, DEPOSIT_LIST1) {
    Model model(10000, 12, 17, 35, 12, false);
    model.pushDeposit(480, 1);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 2150.71, 1e1);
    ASSERT_NEAR(model.getAmount(), 15760, 1e1);
}
TEST(DEPOSIT_CALCULATOR, DEPOSIT_LIST2) {
    Model model(10000, 12, 17, 35, 12, false);
    model.pushDeposit(480, 1);
    model.pushDeposit(130, 6);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 2161.71, 1e1);
    ASSERT_NEAR(model.getAmount(), 16020, 1e1);
}
TEST(DEPOSIT_CALCULATOR, WITHDRAWAL_LIST1) {
    Model model(10000, 12, 17, 35, 12, false);
    model.pushWithdrawal(480, 1);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1255.26, 1e1);
    ASSERT_NEAR(model.getAmount(), 4240, 1e1);
}
TEST(DEPOSIT_CALCULATOR, WITHDRAWAL_LIST2) {
    Model model(10000, 12, 17, 35, 12, false);
    model.pushWithdrawal(480, 1);
    model.pushWithdrawal(130, 6);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1244.28, 1e1);
    ASSERT_NEAR(model.getAmount(), 3980, 1e1);
}
TEST(DEPOSIT_CALCULATOR, ALL_LISTS_CAPITALIZATION_OFF) {
    Model model(10000, 12, 17, 35, 12, false);
    model.pushDeposit(943, 1);
    model.pushDeposit(350, 6);
    model.pushDeposit(35, 12);
    model.pushWithdrawal(480, 1);
    model.pushWithdrawal(130, 6);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 2153.48, 1e1);
    ASSERT_NEAR(model.getAmount(), 16031, 1e1);
}
TEST(DEPOSIT_CALCULATOR, ALL_LISTS_CAPITALIZATION_ON) {
    Model model(10000, 12, 17, 35, 12, true);
    model.pushDeposit(943, 1);
    model.pushDeposit(350, 6);
    model.pushDeposit(35, 12);
    model.pushWithdrawal(480, 1);
    model.pushWithdrawal(130, 6);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 2314.62, 1e1);
    ASSERT_NEAR(model.getAmount(), 18345.62, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_YEAR) {
    Model model(10000, 11, 17, 35, 1, false);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1563.66, 1e1);
    ASSERT_NEAR(model.getAmount(), 10000, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_SIX_MONTHS) {
    Model model(10000, 11, 17, 35, 2, false);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 1563.66, 1e2);
    ASSERT_NEAR(model.getAmount(), 10000, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_SIX_MONTHS2) {
    Model model(10000, 5, 17, 35, 2, false);
    model.DepositCalculator();
    ASSERT_NEAR(model.getEarnedInterest(), 712.6, 1e1);
    ASSERT_NEAR(model.getAmount(), 10000, 1e1);
}
