#include "test_core.h"

TEST(CREDIT_CALCULATOR, ANNUITY1) {
    Model model(10000, 10, 12, ANNUITY);
    model.CreditCalculator();
    ASSERT_NEAR(model.getPayment(), 879.16, 1e-1);
    ASSERT_NEAR(model.getOverpayment(), 549.92, 1e-1);
    ASSERT_NEAR(model.getTotalPayment(), 10549.92, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY2) {
    Model model(1000000, 10, 12, ANNUITY);
    model.CreditCalculator();
    ASSERT_NEAR(model.getPayment(), 87915.89, 1e-1);
    ASSERT_NEAR(model.getOverpayment(), 54990.68, 1e-1);
    ASSERT_NEAR(model.getTotalPayment(), 1054990.68, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY3) {
    Model model(10000, 18, 1, ANNUITY);
    model.CreditCalculator();
    ASSERT_NEAR(model.getPayment(), 10150, 1e-1);
    ASSERT_NEAR(model.getOverpayment(), 150, 1e-1);
    ASSERT_NEAR(model.getTotalPayment(), 10150, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY4) {
    Model model(10000, 39, 600, ANNUITY);
    model.CreditCalculator();
    ASSERT_NEAR(model.getPayment(), 325, 1e-1);
    ASSERT_NEAR(model.getOverpayment(), 185000, 1e-1);
    ASSERT_NEAR(model.getTotalPayment(), 195000, 1e-1);
}
TEST(CREDIT_CALCULATOR, ANNUITY5) {
    Model model(439809.32, 13, 600, ANNUITY);
    model.CreditCalculator();
    ASSERT_NEAR(model.getPayment(), 4772.03, 1e-1);
    ASSERT_NEAR(model.getOverpayment(), 2423408.68, 1e-1);
    ASSERT_NEAR(model.getTotalPayment(), 2863218, 1e-1);
}

TEST(CREDIT_CALCULATOR, DIFFERENTIATED1) {
    Model model(10000, 10, 12, DIFFERENTIATED);
    model.CreditCalculator();
    ASSERT_NEAR(model.getMax(), 916.67, 1e2);
    ASSERT_NEAR(model.getMin(), 840.28, 1e2);
    ASSERT_NEAR(model.getOverpayment(), 541.67, 1e2);
    ASSERT_NEAR(model.getTotalPayment(), 10541.67, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED2) {
    Model model(1000000, 10, 12, DIFFERENTIATED);
    model.CreditCalculator();
    ASSERT_NEAR(model.getMax(), 91666.67, 1e2);
    ASSERT_NEAR(model.getMin(), 84027.78, 1e2);
    ASSERT_NEAR(model.getOverpayment(), 54166.67, 1e2);
    ASSERT_NEAR(model.getTotalPayment(), 1054166.67, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED3) {
    Model model(10000, 18, 1, DIFFERENTIATED);
    model.CreditCalculator();
    ASSERT_NEAR(model.getMax(), 10150, 1e2);
    ASSERT_NEAR(model.getMin(), 10150, 1e2);
    ASSERT_NEAR(model.getOverpayment(), 150, 1e2);
    ASSERT_NEAR(model.getTotalPayment(), 10150, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED4) {
    Model model(10000, 39, 600, DIFFERENTIATED);
    model.CreditCalculator();
    ASSERT_NEAR(model.getMax(), 341.67, 1e2);
    ASSERT_NEAR(model.getMin(), 17.21, 1e2);
    ASSERT_NEAR(model.getOverpayment(), 97662.50, 1e2);
    ASSERT_NEAR(model.getTotalPayment(), 107662.50, 1e2);
}
TEST(CREDIT_CALCULATOR, DIFFERENTIATED5) {
    Model model(439809.32, 13, 600, DIFFERENTIATED);
    model.CreditCalculator();
    ASSERT_NEAR(model.getMax(), 5497.62, 1e2);
    ASSERT_NEAR(model.getMin(), 740.96, 1e2);
    ASSERT_NEAR(model.getOverpayment(), 1431762.59, 1e4);
    ASSERT_NEAR(model.getTotalPayment(), 1871571.91, 1e4);
}
