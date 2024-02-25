#include <stdint.h>
#include "stm32f407xx.h"

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
  GPIOD->MODER |= 0x1 << GPIO_MODER_MODER12_Pos;
  GPIOD->ODR |= GPIO_ODR_OD12_Msk;
  uint16_t a = 8;
  uint32_t b = 71; 
  while (1)
  {
    GPIOD->ODR ^= GPIO_ODR_OD12_Msk;
    for(int i = 0; i < 100000; i++){
        for(int j = 0; j < 100; j++){
        __NOP();
      }
    }
  a = 81;
  b = 7; 
  };
  return 0;
}