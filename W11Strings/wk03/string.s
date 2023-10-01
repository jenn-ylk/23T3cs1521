# TODO: Implement a loop to calculate the length of a string in MIPS
main:	# s is t0, length is t1, the temporary character value is t2
	la 	$a0, string 	# printf("%s", string)
	li 	$v0, 4
	syscall

	li 	$a0, '\n'	# printf("%c", '\n')
	li 	$v0, 11
	syscall

	# TODO: Set up length counter(s) required
	li	$t0, 0
loop_start:
	# TODO: write the loop here to count until the end of string is reached
	lb	$t1, string($t0)	# no extra offset calc
	beqz	$t1, loop_end

	add	$t0, $t0, 1

	b 	loop_start
loop_end:

	# Translate the code to determine the length of our string

	move 	$a0, $t0	# printf("%d", length)
	li	$v0, 1
	syscall

	li 	$a0, '\n'	# printf("%c", '\n')
	li 	$v0, 11
	syscall

	li 	$v0, 0	# return 0
	jr 	$ra

	.data
string:	.asciiz "0 1 2 3 4 5 6 7 8 9"