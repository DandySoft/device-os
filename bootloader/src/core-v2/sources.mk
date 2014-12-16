BOOTLOADER_SRC_COREV2_PATH = $(BOOTLOADER_MODULE_PATH)/src/core-v2

CSRC += $(call target_files,$(BOOTLOADER_SRC_COREV2_PATH)/,*.c)


HAL_LIB_COREV2 = $(HAL_SRC_COREV2_PATH)/lib
HAL_WICED_LIBS += Platform_$(PLATFORM_NET) SPI_Flash_Library_$(PLATFORM_NET)

HAL_WICED_LIB_FILES += $(addprefix $(HAL_LIB_COREV2)/,$(addsuffix .a,$(HAL_WICED_LIBS)))
HAL_WICED_LIB_FILES += $(HAL_LIB_COREV2)/FreeRTOS/STM32F2xx.a

LIBS_EXT += -Wl,--whole-archive $(HAL_WICED_LIB_FILES) -Wl,--no-whole-archive

