#include "app_main.h"
#include "cw32l031_gpio.h"
#include "cw32l031_rcc.h"
#include "cw32l031_systick.h"
#include "log.h"

static inline void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_AHBPeriphClk_Enable(RCC_AHB_PERIPH_GPIOC, ENABLE);

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.IT = GPIO_IT_NONE;
    GPIO_InitStruct.Pins = GPIO_PIN_13;
    GPIO_Init(CW_GPIOC, &GPIO_InitStruct);
}

int main(void)
{
    InitTick(8000000ul); // 初始化SysTick

    LogInit();
    LED_Init();

    // 开启两线调试接口
    RCC_SWDIO_Config(RCC_SYSCTRL_SWDIOEN);
    while (1) {
        printf("Hello CW32L031 ...\r\n");
        GPIO_TogglePin(CW_GPIOC, GPIO_PIN_13);
        SysTickDelay(500);
    }

    return 0;
}

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
