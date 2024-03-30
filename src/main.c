#include <stdint.h>
#include "stm32f407xx.h"

#define TEST_ON 1
//#define TEST_OFF 0


void static_parameter_test(void)
{
  static uint32_t staticbaby = 0;
  staticbaby++;
}

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
  static_parameter_test();
  #ifdef TEST_ON
  a = 81;
  #endif

    
  #ifdef TEST_OFF
  b = 82;
  #endif

  b = 7; 
  
  };


  return 0;
}

