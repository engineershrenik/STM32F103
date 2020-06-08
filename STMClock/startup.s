.syntax unified

.equ THUMB_EN, 1


.word __stack_end
.word ResetHandler+THUMB_EN
.word NMIHandler+THUMB_EN
.word HardFaultHandler+THUMB_EN
.word MPUFaultHandler+THUMB_EN
.word BUFFaultHandler+THUMB_EN
.word UsageFaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word SVCallHandler+THUMB_EN
.word DebugMonitorHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word PendSVHandler+THUMB_EN
.word SysTickHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word DefaultHandler+THUMB_EN
.word GPIOPortEHandler+THUMB_EN

start:
ResetHandler:
/* Write your board reset handler code here */	
/* The code here would have low level hardware init, scatter loader, and jump to main */

B main
	


SysTickHandler:
DefaultHandler:
GPIOPortAHandler:
BUFFaultHandler:
MPUFaultHandler:
NMIHandler:
HardFaultHandler:
UsageFaultHandler:
SVCallHandler:
DebugMonitorHandler:
PendSVHandler:
GPIOPortEHandler:



