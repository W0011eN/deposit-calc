#include  <stdio.h>
#include  <stdlib.h>
int vapod (int aod, int pod)	// Функция для проверки на коректность введеных данных
{
  if (aod < 10000){  // Проверка на корректность суммы вклада
    printf("Сумма вклада введена неверно.\n");
    return -1;
  }
  if((pod < 0) || (pod > 365)){ // Проверка на корректность периода вклада
    printf("Срок вклада введен не верно.\n");
    return -1;
  }
  return 0;
}

float income_deposit(int aod, int pod)//Функция расчета дохода на момент окончания срока
{
  float income;//Доход по окончанию срока вклада
  if((pod >= 0) && (pod <= 30))
  {
    income =aod-((aod/100)*10);
    printf("Сумма вклада на момент окончания срока (штраф -10%%): %.2f\n",income);
  }
  if((pod > 30) && (pod <= 120))
  {
    if (aod < 100000 )
    {
      income =aod+((aod/100)*2);
      printf("Сумма вклада на момент окончание срока (+2%%): %.2f\n",income);
    }
    else
    {
      income =aod+((aod/100)*3);
      printf("Сумма вклада на момент окончание срока(+3%%): %.2f\n",income);
    }
  }
  if((pod > 120) && (pod <= 240))
  {
    if (aod < 100000 )
    {
      income =aod+((aod/100)*6);
      printf("Сумма вклада на момент окончание срока(+6%%): %.2f\n",income);
    }
    else
    {
      income =aod+((aod/100)*8);
      printf("Сумма вклада на момент окончание срока(+8%%): %.2f\n",income);
    }
  }
  if((pod > 240) && (pod <= 365))
  {
    if (aod < 100000 )
    {
      income =aod+((aod/100)*12);
      printf("Сумма вклада на момент окончание срока(+12%%): %.2f\n",income);
    }
    else
    {
      income =aod+((aod/100)*15);
      printf("Сумма вклада на момент окончание срока(+15%%): %.2f\n",income);
    }
  }
  return income;
}