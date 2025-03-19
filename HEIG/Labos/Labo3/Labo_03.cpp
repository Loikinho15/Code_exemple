//
// Created by loicd on 23.09.2024.
//
/*
#include <iomanip>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
 string user_name;
 string bank_account;

 cout << "Quel est votre numéro de compte ?" << endl;
 cin >> bank_account;

 cout << "Quel est votre nom de famille ?" << endl;
 cin >> user_name;

 float acc_amt = 1000.00;
 float tx_change_CHF_to_EUR = 1.024;
 float op_fee = 5.00;
 printf("Solde de votre compte en CHF : %.2f\n", acc_amt);
 printf("Taux de change : 1 CHF = %.3f Euro\n" , tx_change_CHF_to_EUR);
 printf("Frais d'opération : %.2f CHF\n", op_fee);

 float eur_amt;
 printf("Entrez la somme souhaitée en Euro : \n");
 cin >> eur_amt;

 float chf_amt = eur_amt/tx_change_CHF_to_EUR;
 float acc_tot_amt = acc_amt - chf_amt - op_fee;

 printf("Somme CHF : %.2f, Solde compte : %.2f\n", chf_amt,acc_tot_amt);

 printf("+-------------------+\n");
 printf("|\n");
 printf("| %s\n", user_name.c_str());
 printf("| %s\n", bank_account.c_str());
 printf("|\n");
 printf("| Somme EUR : %.2f\n", eur_amt);
 printf("| 1 CHF en EUR : %.3f\n", tx_change_CHF_to_EUR);
 printf("|\n");
 printf("| Somme CHF : %.2f\n", chf_amt);
 printf("| Frais : %.2f\n", op_fee);
 printf("|\n");
 printf("| Solde du compte : %.2f\n", acc_tot_amt);
 printf("+-------------------+\n");
}
*/