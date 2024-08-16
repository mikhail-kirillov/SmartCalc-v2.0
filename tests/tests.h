// Copyright 2024 Burr Etienne
#ifndef TESTS_TESTS_H_
#define TESTS_TESTS_H_

#include <cmath>
#include <ctime>
#include <limits>
#include <string>
#include <vector>

#include "../src/controller/credit/credit.h"
#include "../src/controller/deposit/deposit.h"

const double precision = 1e-7;

const std::string expression_calculator_first = "1+2";
const std::string expression_calculator_second = "2.1234567-3";
const std::string expression_calculator_third = "4*5.0";
const std::string expression_calculator_fourth = "6/7";
const std::string expression_calculator_fifth = "8+9+1";
const std::string expression_calculator_sixth = "2+3-4";
const std::string expression_calculator_seventh = "5+6*7";
const std::string expression_calculator_eighth = "8+9/1";
const std::string expression_calculator_ninth = "2-3-4";
const std::string expression_calculator_tenth = "5-6*7";
const std::string expression_calculator_eleventh = "8-9/1";
const std::string expression_calculator_twelfth = "0.001-1";
const std::string expression_calculator_thirteenth = "2-0";
const std::string expression_calculator_fourteenth = "3*0";
const std::string expression_calculator_fifteenth = "4/0";
const std::string expression_calculator_sixteenth = "5mod0";
const std::string expression_calculator_seventeenth = "6^0";
const std::string expression_calculator_eighteenth = "-7^2";
const std::string expression_calculator_nineteenth = "-8+2e2";
const std::string expression_calculator_twentieth = "sin(0)";
const std::string expression_calculator_twenty_first = "cos(1)";
const std::string expression_calculator_twenty_second = "tan(2)";
const std::string expression_calculator_twenty_third = "asin(3)";
const std::string expression_calculator_twenty_fourth = "acos(-1)";
const std::string expression_calculator_twenty_fifth = "atan(5.3)";
const std::string expression_calculator_twenty_sixth = "log(6)";
const std::string expression_calculator_twenty_seventh = "ln(7)";
const std::string expression_calculator_twenty_eighth = "sqrt(8)";
const std::string expression_calculator_twenty_ninth = "x*2+3-sin(x)";

const double x_calculator = 0.5;

const double result_calculator_first = 1.0 + 2.0;
const double result_calculator_second = 2.1234567 - 3.0;
const double result_calculator_third = 4 * 5.0;
const double result_calculator_fourth = 6.0 / 7.0;
const double result_calculator_fifth = 8.0 + 9.0 + 1.0;
const double result_calculator_sixth = 2.0 + 3.0 - 4.0;
const double result_calculator_seventh = 5.0 + 6.0 * 7.0;
const double result_calculator_eighth = 8.0 + 9.0 / 1.0;
const double result_calculator_ninth = 2.0 - 3.0 - 4.0;
const double result_calculator_tenth = 5.0 - 6.0 * 7.0;
const double result_calculator_eleventh = 8.0 - 9.0 / 1.0;
const double result_calculator_twelfth = 0.001 - 1.0;
const double result_calculator_thirteenth = 2.0 - 0;
const double result_calculator_fourteenth = 3.0 * 0;
const double result_calculator_seventeenth = std::pow(6.0, 0);
const double result_calculator_eighteenth = std::pow(-7.0, 2);
const double result_calculator_nineteenth = -8.0 + 2e2;
const double result_calculator_twentieth = std::sin(0.0);
const double result_calculator_twenty_first = std::cos(1.0);
const double result_calculator_twenty_second = std::tan(2.0);
const double result_calculator_twenty_fourth = std::acos(-1.0);
const double result_calculator_twenty_fifth = std::atan(5.3);
const double result_calculator_twenty_sixth = std::log10(6.0);
const double result_calculator_twenty_seventh = std::log(7.0);
const double result_calculator_twenty_eighth = std::sqrt(8.0);
const double result_calculator_twenty_ninth =
    x_calculator * 2.0 + 3.0 - std::sin(x_calculator);

const double total_amount_credit = 12345.67;
const int total_term_credit = 5;
const double total_percent_credit = 10.2;
const s21::CreditType type_credit_first = s21::CreditType::ANNUITY;
const s21::CreditType type_credit_second = s21::CreditType::DIFFERENTIAL;

const double total_payment_credit_first = 12662.26094008;
const double total_overpayment_credit_first = 316.59094008;
const double monthly_payment_credit_first = 2532.45218802;

const double total_payment_credit_second = 12660.48458500;
const double total_overpayment_credit_second = 314.81458500;
const double max_monthly_payment_credit_second = 2490.12163900;
const double min_monthly_payment_credit_second = 2574.07219500;

const double total_amount_deposit = 12345.67;
const int total_term_deposit = 5;
const double total_percent_deposit = 10.2;
const double total_tax_deposit = 1.5;
const std::tm start_date_deposit = {0, 0, 0,  1, 1 - 1,  2000 - 1900,
                                    0, 0, -1, 0, nullptr};
const s21::TransactionRecurrence recurrence_deposit_first =
    s21::TransactionRecurrence::ONCE;
const s21::TransactionRecurrence recurrence_deposit_second =
    s21::TransactionRecurrence::DAILY;
const bool capitalization_deposit_first = false;
const bool capitalization_deposit_second = true;
const std::vector<s21::Transaction> transactions_deposit = {
    s21::Transaction{
        std::tm{0, 0, 0, 2, 2 - 1, 2000 - 1900, 0, 0, -1, 0, nullptr}, -1000,
        s21::TransactionRecurrence::ONCE},
    s21::Transaction{
        std::tm{0, 0, 0, 4, 3 - 1, 2000 - 1900, 0, 0, -1, 0, nullptr}, 3000,
        s21::TransactionRecurrence::MONTHLY},
};

const double total_interest_deposit_first = 1121.80488263;
const double total_tax_deposit_first = 17.08332309;
const double total_sum_deposit_first = 27467.47488263;

const double total_interest_deposit_second = 14658.51782310;
const double total_tax_deposit_second = 223.22615974;
const double total_sum_deposit_second = 41885.93180594;

#endif  // TESTS_TESTS_H_
