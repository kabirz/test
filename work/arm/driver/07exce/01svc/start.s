.align 2
.global _start
_start:
	b reset@addr = 0
	b unde
	b swi
	b pre_bot
	b dat_bot
	.word 0x00
	b irq
	b fiq
reset:
	stmfd sp!, {r0-r12, lr}
	bl main
	ldmfd sp!, {r0-r12, pc}
unde:
swi:
pre_bot:
dat_bot:
irq:
fiq:
