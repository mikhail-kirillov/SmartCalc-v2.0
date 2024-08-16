// Copyright 2024 Burr Etienne
#ifndef SRC_CONTROLLER_CREDIT_CREDIT_H_
#define SRC_CONTROLLER_CREDIT_CREDIT_H_

#include "../../model/credit/credit.h"

namespace s21 {

class CreditController {
 public:
  CreditController() = default;
  ~CreditController() = default;

  void SetCreditType(CreditType type);
  void SetCreditAmount(double amount);
  void SetCreditTerm(int term);
  void SetCreditInterest(double interest);
  void Calculate();
  double GetMonthlyPayment();
  double GetMinMonthlyPayment();
  double GetMaxMonthlyPayment();
  double GetTotalPayment();
  double GetOverpayment();

 private:
  CreditModel model_;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_CREDIT_CREDIT_H_
