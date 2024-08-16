// Copyright 2024 Burr Etienne
#ifndef SRC_MODEL_CREDIT_CREDIT_H_
#define SRC_MODEL_CREDIT_CREDIT_H_

namespace s21 {
enum CreditType { ANNUITY, DIFFERENTIAL };
class CreditModel {
 public:
  CreditModel() = default;
  ~CreditModel() = default;

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
  CreditType type_ = CreditType::ANNUITY;
  double amount_ = 0;
  int term_ = 0;
  double interest_ = 0;
  double monthly_payment_ = 0;
  double min_monthly_payment_ = 0;
  double max_monthly_payment_ = 0;
  double total_payment_ = 0;
  double overpayment_ = 0;
  double monthly_interest_ = 0;

  void CalculateAnnuity();
  void CalculateDifferential();
  void NullableCalculation();
};

}  // namespace s21

#endif  // SRC_MODEL_CREDIT_CREDIT_H_
