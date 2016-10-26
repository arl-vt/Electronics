################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ADC.obj: ../ADC.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ADC.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

QEI.obj: ../QEI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="QEI.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pinout.obj: ../pinout.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="pinout.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

thermo.obj: ../thermo.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="thermo.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tm4c1294ncpdt_startup_ccs.obj: ../tm4c1294ncpdt_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/shriya/Documents/Exoskeleton/Electronics/Dyno/DynoTestStand code/DynoStand" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c1294xl/" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="tm4c1294ncpdt_startup_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


