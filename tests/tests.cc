// Copyright 2024 Burr Etienne
#include "tests.h"

#include <gtest/gtest.h>

#include "../src/controller/calculator/calculator.h"
#include "../src/controller/credit/credit.h"
#include "../src/controller/deposit/deposit.h"

TEST(CalculateTest, FirstExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_first);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_first,
              precision);
}

TEST(CalculateTest, SecondExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_second);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_second,
              precision);
}

TEST(CalculateTest, ThirdExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_third);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_third,
              precision);
}

TEST(CalculateTest, FourthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_fourth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_fourth,
              precision);
}

TEST(CalculateTest, FifthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_fifth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_fifth,
              precision);
}

TEST(CalculateTest, SixthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_sixth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_sixth,
              precision);
}

TEST(CalculateTest, SeventhExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_seventh);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_seventh,
              precision);
}

TEST(CalculateTest, EighthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_eighth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_eighth,
              precision);
}

TEST(CalculateTest, NinthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_ninth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_ninth,
              precision);
}

TEST(CalculateTest, TenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_tenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_tenth,
              precision);
}

TEST(CalculateTest, EleventhExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_eleventh);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_eleventh,
              precision);
}

TEST(CalculateTest, TwelfthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twelfth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twelfth,
              precision);
}

TEST(CalculateTest, ThirteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_thirteenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_thirteenth,
              precision);
}

TEST(CalculateTest, FourteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_fourteenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_fourteenth,
              precision);
}

TEST(CalculateTest, FifteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_fifteenth);
  calculator_controller.SetX(x_calculator);
  EXPECT_THROW(calculator_controller.Calculate(), std::invalid_argument);
}

TEST(CalculateTest, SixteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_sixteenth);
  calculator_controller.SetX(x_calculator);
  EXPECT_THROW(calculator_controller.Calculate(), std::invalid_argument);
}

TEST(CalculateTest, SeventeenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_seventeenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_seventeenth,
              precision);
}

TEST(CalculateTest, EighteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_eighteenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_eighteenth,
              precision);
}

TEST(CalculateTest, NineteenthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_nineteenth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_nineteenth,
              precision);
}

TEST(CalculateTest, TwentiethExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twentieth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twentieth,
              precision);
}

TEST(CalculateTest, TwentyFirstExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_first);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twenty_first,
              precision);
}

TEST(CalculateTest, TwentySecondExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_second);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(),
              result_calculator_twenty_second, precision);
}

TEST(CalculateTest, TwentyThirdExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_third);
  calculator_controller.SetX(x_calculator);
  EXPECT_THROW(calculator_controller.Calculate(), std::invalid_argument);
}

TEST(CalculateTest, TwentyFourthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_fourth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(),
              result_calculator_twenty_fourth, precision);
}

TEST(CalculateTest, TwentyFifthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_fifth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twenty_fifth,
              precision);
}

TEST(CalculateTest, TwentySixthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_sixth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twenty_sixth,
              precision);
}

TEST(CalculateTest, TwentySeventhExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_seventh);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(),
              result_calculator_twenty_seventh, precision);
}

TEST(CalculateTest, TwentyEighthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_eighth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(),
              result_calculator_twenty_eighth, precision);
}

TEST(CalculateTest, TwentyNinthExpression) {
  s21::CalculatorController calculator_controller;
  calculator_controller.SetExpression(expression_calculator_twenty_ninth);
  calculator_controller.SetX(x_calculator);
  calculator_controller.Calculate();
  EXPECT_NEAR(calculator_controller.GetResult(), result_calculator_twenty_ninth,
              precision);
}

TEST(CreditTest, FirstTest) {
  s21::CreditController credit_controller;
  credit_controller.SetCreditAmount(total_amount_credit);
  credit_controller.SetCreditTerm(total_term_credit);
  credit_controller.SetCreditInterest(total_percent_credit);

  credit_controller.SetCreditType(type_credit_first);
  credit_controller.Calculate();
  EXPECT_NEAR(credit_controller.GetTotalPayment(), total_payment_credit_first,
              precision);
  EXPECT_NEAR(credit_controller.GetMonthlyPayment(),
              monthly_payment_credit_first, precision);
  EXPECT_NEAR(credit_controller.GetOverpayment(),
              total_overpayment_credit_first, precision);
}

TEST(CreditTest, SecondTest) {
  s21::CreditController credit_controller;
  credit_controller.SetCreditAmount(total_amount_credit);
  credit_controller.SetCreditTerm(total_term_credit);
  credit_controller.SetCreditInterest(total_percent_credit);

  credit_controller.SetCreditType(type_credit_second);
  credit_controller.Calculate();
  EXPECT_NEAR(credit_controller.GetTotalPayment(), total_payment_credit_second,
              precision);
  EXPECT_NEAR(credit_controller.GetMinMonthlyPayment(),
              min_monthly_payment_credit_second, precision);
  EXPECT_NEAR(credit_controller.GetMaxMonthlyPayment(),
              max_monthly_payment_credit_second, precision);
  EXPECT_NEAR(credit_controller.GetOverpayment(),
              total_overpayment_credit_second, precision);
}

TEST(DepositTest, FirstTest) {
  s21::DepositController deposit_controller;
  deposit_controller.SetAmount(total_amount_deposit);
  deposit_controller.SetTerm(total_term_deposit);
  deposit_controller.SetInterest(total_percent_deposit);
  deposit_controller.SetTax(total_tax_deposit);
  deposit_controller.SetStartDate(start_date_deposit);
  deposit_controller.AddTransactions(transactions_deposit);

  deposit_controller.SetRecurrence(recurrence_deposit_first);
  deposit_controller.SetCapitalization(capitalization_deposit_first);
  deposit_controller.Calculate();
  EXPECT_NEAR(deposit_controller.GetTotalInterest(),
              total_interest_deposit_first, precision);
  EXPECT_NEAR(deposit_controller.GetTotalTax(), total_tax_deposit_first,
              precision);
  EXPECT_NEAR(deposit_controller.GetTotalSum(), total_sum_deposit_first,
              precision);
}

TEST(DepositTest, SecondTest) {
  s21::DepositController deposit_controller;
  deposit_controller.SetAmount(total_amount_deposit);
  deposit_controller.SetTerm(total_term_deposit);
  deposit_controller.SetInterest(total_percent_deposit);
  deposit_controller.SetTax(total_tax_deposit);
  deposit_controller.SetStartDate(start_date_deposit);
  deposit_controller.AddTransactions(transactions_deposit);

  deposit_controller.SetRecurrence(recurrence_deposit_second);
  deposit_controller.SetCapitalization(capitalization_deposit_second);
  deposit_controller.Calculate();
  EXPECT_NEAR(deposit_controller.GetTotalInterest(),
              total_interest_deposit_second, precision);
  EXPECT_NEAR(deposit_controller.GetTotalTax(), total_tax_deposit_second,
              precision);
  EXPECT_NEAR(deposit_controller.GetTotalSum(), total_sum_deposit_second,
              precision);
}
