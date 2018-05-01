// variables defined on LinkerScript.ld
void _estack(void);
extern int _sidata;
extern int _sdata;
extern int _edata;
extern int _sbss;
extern int _ebss;

int main(void);
void SystemInit(void);
#ifdef __cplusplus
void __libc_init_array(void);
#endif /* __cplusplus */

/*
 * estack: the end point of stack
 * .isr_vector: the section for interrupt vector
 * _sidata: the address for the start of .data section(not aligned)
 * _sdata: the address for the start of .data section(aligned)
 * _edata: the address for the end of .data section
 */
void Reset_Handler(void) {
	// copy .data section to SRAM
	int offset = 0;
	while( &_sdata + offset < &_edata ) {
		*(&_sdata + offset) = *(&_sidata + offset);
		offset++;
	}

	// .bss section initialization
	offset = 0;
	while( &_sbss + offset < &_ebss ) {
		*(&_sbss + offset) = 0;
		offset++; // Fill zero in all area
	}

	SystemInit();
#ifdef __cplusplus
	__libc_init_array();
#endif /* __cplusplus */
	main();

	/*
	 * main() should not return. If it returns, program goes into infinite loop.
	 * Note that all IRQHandlers can be called even in this loop.
	 */
	while(114514);
}

__attribute__((weak)) void NMI_Handler(void) {}
__attribute__((weak)) void HardFault_Handler(void) {}
__attribute__((weak)) void MemManage_Handler(void) {}
__attribute__((weak)) void BusFault_Handler(void) {}
__attribute__((weak)) void UsageFault_Handler(void) {}
__attribute__((weak)) void SVC_Handler(void) {}
__attribute__((weak)) void DebugMon_Handler(void) {}
__attribute__((weak)) void PendSV_Handler(void) {}
__attribute__((weak)) void SysTick_Handler(void) {}
__attribute__((weak)) void WWDG_IRQHandler(void) {}
__attribute__((weak)) void PVD_IRQHandler(void) {}
__attribute__((weak)) void TAMP_STAMP_IRQHandler(void) {}
__attribute__((weak)) void RTC_WKUP_IRQHandler(void) {}
__attribute__((weak)) void FLASH_IRQHandler(void) {}
__attribute__((weak)) void RCC_IRQHandler(void) {}
__attribute__((weak)) void EXTI0_IRQHandler(void) {}
__attribute__((weak)) void EXTI1_IRQHandler(void) {}
__attribute__((weak)) void EXTI2_TSC_IRQHandler(void) {}
__attribute__((weak)) void EXTI3_IRQHandler(void) {}
__attribute__((weak)) void EXTI4_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel1_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel2_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel3_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel4_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel5_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel6_IRQHandler(void) {}
__attribute__((weak)) void DMA1_Channel7_IRQHandler(void) {}
__attribute__((weak)) void ADC1_2_IRQHandler(void) {}
__attribute__((weak)) void CAN_TX_IRQHandler(void) {}
__attribute__((weak)) void CAN_RX0_IRQHandler(void) {}
__attribute__((weak)) void CAN_RX1_IRQHandler(void) {}
__attribute__((weak)) void CAN_SCE_IRQHandler(void) {}
__attribute__((weak)) void EXTI9_5_IRQHandler(void) {}
__attribute__((weak)) void TIM1_BRK_TIM15_IRQHandler(void) {}
__attribute__((weak)) void TIM1_UP_TIM16_IRQHandler(void) {}
__attribute__((weak)) void TIM1_TRG_COM_TIM17_IRQHandler(void) {}
__attribute__((weak)) void TIM1_CC_IRQHandler(void) {}
__attribute__((weak)) void TIM2_IRQHandler(void) {}
__attribute__((weak)) void TIM3_IRQHandler(void) {}
__attribute__((weak)) void I2C1_EV_IRQHandler(void) {}
__attribute__((weak)) void I2C1_ER_IRQHandler(void) {}
__attribute__((weak)) void SPI1_IRQHandler(void) {}
__attribute__((weak)) void USART1_IRQHandler(void) {}
__attribute__((weak)) void USART2_IRQHandler(void) {}
__attribute__((weak)) void USART3_IRQHandler(void) {}
__attribute__((weak)) void EXTI15_10_IRQHandler(void) {}
__attribute__((weak)) void RTC_Alarm_IRQHandler(void) {}
__attribute__((weak)) void TIM6_DAC1_IRQHandler(void) {}
__attribute__((weak)) void TIM7_DAC2_IRQHandler(void) {}
__attribute__((weak)) void COMP2_IRQHandler(void) {}
__attribute__((weak)) void COMP4_6_IRQHandler(void) {}
__attribute__((weak)) void FPU_IRQHandler(void) {}


__attribute__((section(".isr_vector")))
void (*isr_vectors[])(void) = {
	_estack,
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	DebugMon_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_TSC_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	ADC1_2_IRQHandler,
	CAN_TX_IRQHandler,
	CAN_RX0_IRQHandler,
	CAN_RX1_IRQHandler,
	CAN_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_TIM17_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	0,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	0,
	0,
	SPI1_IRQHandler,
	0,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	TIM6_DAC1_IRQHandler,
	TIM7_DAC2_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	COMP2_IRQHandler,
	COMP4_6_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	FPU_IRQHandler,
};
