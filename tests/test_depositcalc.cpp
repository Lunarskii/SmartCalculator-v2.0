#include "test_core.h"

TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_OFF) {
    Model model(10000, 12, 10, 35, 12, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1000, 1e-1);
    ASSERT_NEAR(deposit_result.amount, 10000, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_ON) {
    Model model(10000, 12, 10, 35, 12, true);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1049, 1e1);
    ASSERT_NEAR(deposit_result.amount, 11049, 1e2);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_OFF2) {
    Model model(1000000, 12, 10, 35, 12, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 100000, 1e-1);
    ASSERT_NEAR(deposit_result.amount, 1000000, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, WITHOUT_LISTS_CAPITALIZATION_ON2) {
    Model model(1000000, 12, 10, 35, 12, true);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 104713.06, 1e-1);
    ASSERT_NEAR(deposit_result.amount, 1104713.06, 1e-1);
}
TEST(DEPOSIT_CALCULATOR, DEPOSIT_LIST1) {
    Model model(10000, 12, 17, 35, 12, false);
    model.PushDeposit(480, 1);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 2150.71, 1e1);
    ASSERT_NEAR(deposit_result.amount, 15760, 1e1);
}
TEST(DEPOSIT_CALCULATOR, DEPOSIT_LIST2) {
    Model model(10000, 12, 17, 35, 12, false);
    model.PushDeposit(480, 1);
    model.PushDeposit(130, 6);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 2161.71, 1e1);
    ASSERT_NEAR(deposit_result.amount, 16020, 1e1);
}
TEST(DEPOSIT_CALCULATOR, WITHDRAWAL_LIST1) {
    Model model(10000, 12, 17, 35, 12, false);
    model.PushWithdrawal(480, 1);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1255.26, 1e1);
    ASSERT_NEAR(deposit_result.amount, 4240, 1e1);
}
TEST(DEPOSIT_CALCULATOR, WITHDRAWAL_LIST2) {
    Model model(10000, 12, 17, 35, 12, false);
    model.PushWithdrawal(480, 1);
    model.PushWithdrawal(130, 6);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1244.28, 1e1);
    ASSERT_NEAR(deposit_result.amount, 3980, 1e1);
}
TEST(DEPOSIT_CALCULATOR, ALL_LISTS_CAPITALIZATION_OFF) {
    Model model(10000, 12, 17, 35, 12, false);
    model.PushDeposit(943, 1);
    model.PushDeposit(350, 6);
    model.PushDeposit(35, 12);
    model.PushWithdrawal(480, 1);
    model.PushWithdrawal(130, 6);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 2153.48, 1e1);
    ASSERT_NEAR(deposit_result.amount, 16031, 1e1);
}
TEST(DEPOSIT_CALCULATOR, ALL_LISTS_CAPITALIZATION_ON) {
    Model model(10000, 12, 17, 35, 12, true);
    model.PushDeposit(943, 1);
    model.PushDeposit(350, 6);
    model.PushDeposit(35, 12);
    model.PushWithdrawal(480, 1);
    model.PushWithdrawal(130, 6);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 2314.62, 1e1);
    ASSERT_NEAR(deposit_result.amount, 18345.62, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_YEAR) {
    Model model(10000, 11, 17, 35, 1, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1563.66, 1e1);
    ASSERT_NEAR(deposit_result.amount, 10000, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_SIX_MONTHS) {
    Model model(10000, 11, 17, 35, 2, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1563.66, 1e2);
    ASSERT_NEAR(deposit_result.amount, 10000, 1e1);
}
TEST(DEPOSIT_CALCULATOR, INCOMPLETE_SIX_MONTHS2) {
    Model model(10000, 5, 17, 35, 2, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 712.6, 1e1);
    ASSERT_NEAR(deposit_result.amount, 10000, 1e1);
}

TEST(DEPOSIT_CALCULATOR, SET_VALUES) {
    Model model(10000, 12, 10, 35, 12, false);
    model.DepositCalculator();
    DepositResult deposit_result = model.GetDepositResult();
    ASSERT_NEAR(deposit_result.interest, 1000, 1e-1);
    ASSERT_NEAR(deposit_result.amount, 10000, 1e-1);
    DepositData deposit_data = {10000, 17, 35, 5, 2, false};
    model.SetValues(deposit_data);
    model.DepositCalculator();
    DepositResult deposit_result2 = model.GetDepositResult();
    ASSERT_NEAR(deposit_result2.interest, 712.6, 1e1);
    ASSERT_NEAR(deposit_result2.amount, 10000, 1e1);
}
