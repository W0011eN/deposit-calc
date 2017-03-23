#include  <stdio.h>
#include  <stdlib.h>
#include  "deposit.h"
int main ()
{
  unsigned int pod;	// Входные данные pod(срок вклада)
  unsigned int aod;	// Входные данные aod (период вклада)
  printf("Введите сумму вклада, т.р. (минимальная сумма 10т.р): ");
  scanf("%d",&aod);
  printf("Введите срок вклада(до года, в днях): ");
  scanf("%d",&pod);
  vapod (aod,pod);// Функция для проверки на коректность введенных данных пользователем
  income_deposit(aod,pod); //Функция расчета суммы вклада на момент окончания срока
  return 0;
}