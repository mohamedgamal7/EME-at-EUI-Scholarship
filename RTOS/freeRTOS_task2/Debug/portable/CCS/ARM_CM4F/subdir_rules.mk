################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
portable/CCS/ARM_CM4F/%.obj: ../portable/CCS/ARM_CM4F/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2" --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2/include" --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="portable/CCS/ARM_CM4F/$(basename $(<F)).d_raw" --obj_directory="portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

portable/CCS/ARM_CM4F/%.obj: ../portable/CCS/ARM_CM4F/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2" --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2/include" --include_path="E:/EUI workspace/workspace_new/freeRTOS_task2/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="portable/CCS/ARM_CM4F/$(basename $(<F)).d_raw" --obj_directory="portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


