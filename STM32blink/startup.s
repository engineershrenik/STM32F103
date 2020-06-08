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

	
LDR R1,=0x40021018
LDR R5,[R1]
ORR R5,R5,#0x80
STR R5,[R1]

LDR R2,=0x40011C00
LDR R5,[R2]
AND R5,R5,#0x00FFFFFF
ORR R5,R5,#0x11000000
STR R5,[R2]

LDR R2,=0x40011C08
LDR R5,[R2]
AND R5,R5,#0x00FFFFFF
ORR R5,R5,#0x00000011
STR R5,[R2]

LDR R1,=0x40011C10
LDR R5,=0x3C0
STR R5,[R1]

Loop:
	B Loop











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



