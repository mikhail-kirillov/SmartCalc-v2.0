// Copyright 2024 Burr Etienne
#ifndef SRC_MODEL_DEPOSIT_DEPOSIT_H_
#define SRC_MODEL_DEPOSIT_DEPOSIT_H_

#include <ctime>
#include <vector>

namespace s21 {
enum TransactionRecurrence { ONCE, DAILY, MONTHLY };

struct Transaction {
  std::tm date;
  double amount;
  TransactionRecurrence recurrence;

  Transaction(const std::tm& date, double amount,
              TransactionRecurrence recurrence);
};

class DepositModel {
 public:
  DepositModel() = default;
  ~DepositModel() = default;

  void SetAmount(double amount);
  void SetTerm(int term);
  void SetStartDate(const std::tm& start_date);
  void SetInterest(double interest);
  void SetTax(double tax);
  void SetRecurrence(TransactionRecurrence recurrence);
  void SetCapitalization(bool capitalization);
  void AddTransactions(const std::vector<Transaction>& transactions);
  void Calculate();
  double GetTotalInterest();
  double GetTotalTax();
  double GetTotalSum();

 private:
  std::vector<Transaction> transactions_ = {};
  double amount_ = 0;
  int term_ = 0;
  std::tm start_date_ = {};
  double interest_ = 0;
  double tax_ = 0;
  TransactionRecurrence recurrence_ = TransactionRecurrence::ONCE;
  std::tm end_date_ = {};
  bool capitalization_ = false;
  double total_interest_ = 0;
  double total_tax_ = 0;
  double total_sum_ = 0;

  void NullableValues();
  void CalculateDeposit();
  void CalculateEndDate();
};

}  // namespace s21

#endif  // SRC_MODEL_DEPOSIT_DEPOSIT_H_
