# 模块名_DIR 是上一层传递下来的参数，
# 是从工程根目录到该模块文件夹的路径

# 向 C_SOURCES 中添加需要编译的源文件
#C_SOURCES += $(wildcard $(Libraries_DIR)/CW32L031_StdLib/src/*.c)
C_SOURCES += $(wildcard $(Libraries_DIR)/CW32L031_StdLib/src/cw32l031_rcc.c)
C_SOURCES += cw32l031_gpio.c
C_SOURCES += cw32l031_uart.c
C_SOURCES += system_cw32l031.c
C_SOURCES += cw32l031_systick.c

# 向 C_INCLUDES 中添加头文件路径
C_INCLUDES += -I$(Libraries_DIR)/CMSIS/Include
C_INCLUDES += -I$(Libraries_DIR)/CMSIS/Device/
C_INCLUDES += -I$(Libraries_DIR)/CW32L031_StdLib/inc


# 向 LIBDIR 中添加静态库文件路径
# LIBDIR += -L$(Libraries_DIR)/Lib
# 向 LIBS 中添加需要链接的静态库
# LIBS += -lxxxx

# link script
LDSCRIPT = $(Libraries_DIR)/CMSIS/Device/CW32L031_FLASH.ld


# 汇编文件宏定义
AS_DEFS += 

# 汇编头文件目录
AS_INCLUDES += 

# 汇编源文件（starup）
ASM_SOURCES += $(Libraries_DIR)/CMSIS/Device/startup_cw32l031_gcc.s
