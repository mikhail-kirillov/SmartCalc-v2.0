// Copyright 2024 Burr Etienne
#ifndef SRC_CONTROLLER_DEPOSIT_DEPOSIT_H_
#define SRC_CONTROLLER_DEPOSIT_DEPOSIT_H_

#include <vector>

#include "../../model/deposit/deposit.h"

namespace s21 {

class DepositController {
 public:
  DepositController() = default;
  ~DepositController() = default;

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
  DepositModel model_;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_DEPOSIT_DEPOSIT_H_
