#include "test_core.h"

TEST(CREDIT_CALCULATOR, ANNUITY1) {
    Model model(10000, 10, 12, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 879.16, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 549.92, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 10549.92, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY2) {
    Model model(1000000, 10, 12, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 87915.89, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 54990.68, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 1054990.68, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY3) {
    Model model(10000, 18, 1, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 10150, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 150, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 10150, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY4) {
    Model model(10000, 39, 600, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 325, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 185000, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 195000, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY5) {
    Model model(439809.32, 13, 600, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 4772.03, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 2423408.68, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 2863218, 1e-1);
}

TEST(CREDIT_CALCULATOR, DIFFERENTIATED1) {
    Model model(10000, 10, 12, s21::kDifferentiated);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.max_payment, 916.67, 1e2);
    ASSERT_NEAR(credit_result.min_payment, 840.28, 1e2);
    ASSERT_NEAR(credit_result.overpayment, 541.67, 1e2);
    ASSERT_NEAR(credit_result.total_payment, 10541.67, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED2) {
    Model model(1000000, 10, 12, s21::kDifferentiated);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.max_payment, 91666.67, 1e2);
    ASSERT_NEAR(credit_result.min_payment, 84027.78, 1e2);
    ASSERT_NEAR(credit_result.overpayment, 54166.67, 1e2);
    ASSERT_NEAR(credit_result.total_payment, 1054166.67, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED3) {
    Model model(10000, 18, 1, s21::kDifferentiated);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.max_payment, 10150, 1e2);
    ASSERT_NEAR(credit_result.min_payment, 10150, 1e2);
    ASSERT_NEAR(credit_result.overpayment, 150, 1e2);
    ASSERT_NEAR(credit_result.total_payment, 10150, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED4) {
    Model model(10000, 39, 600, s21::kDifferentiated);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.max_payment, 341.67, 1e2);
    ASSERT_NEAR(credit_result.min_payment, 17.21, 1e2);
    ASSERT_NEAR(credit_result.overpayment, 97662.50, 1e2);
    ASSERT_NEAR(credit_result.total_payment, 107662.50, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED5) {
    Model model(439809.32, 13, 600, s21::kDifferentiated);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.max_payment, 5497.62, 1e2);
    ASSERT_NEAR(credit_result.min_payment, 740.96, 1e2);
    ASSERT_NEAR(credit_result.overpayment, 1431762.59, 1e4);
    ASSERT_NEAR(credit_result.total_payment, 1871571.91, 1e4);
}

TEST(CREDIT_CALCULATOR, SET_VALUES) {
    Model model(10000, 10, 12, s21::kAnnuity);
    model.CreditCalculator();
    CreditResult credit_result = model.GetCreditResult();
    ASSERT_NEAR(credit_result.payment, 879.16, 1e-1);
    ASSERT_NEAR(credit_result.overpayment, 549.92, 1e-1);
    ASSERT_NEAR(credit_result.total_payment, 10549.92, 1e-1);
    CreditData credit_data = {439809.32, 13, 600, s21::kDifferentiated};
    model.SetValues(credit_data);
    model.CreditCalculator();
    CreditResult credit_result2 = model.GetCreditResult();
    ASSERT_NEAR(credit_result2.max_payment, 5497.62, 1e2);
    ASSERT_NEAR(credit_result2.min_payment, 740.96, 1e2);
    ASSERT_NEAR(credit_result2.overpayment, 1431762.59, 1e4);
    ASSERT_NEAR(credit_result2.total_payment, 1871571.91, 1e4);
}
