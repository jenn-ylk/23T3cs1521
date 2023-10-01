# Implement a loop to calculate the length of a string in MIPS
main:	# s is t0, length is t1, the temporary character value is t2
	la 	$a0, string 	# printf("%s", string)
	li 	$v0, 4
	syscall

	li 	$a0, '\n'	# printf("%c", '\n')
	li 	$v0, 11
	syscall

	# Set up length counter(s) required
	li	$t0, 0
	la	$t2, string	# char *s = &string[0] (used if incrementing the string pointer)

loop_start:
	# load in the current character and check its value
	lb	$t1, ($t2)
	lb	$t1, string($t0)
	beqz	$t1,loop_end

	addi	$t0, $t0, 1	# i++
	addi	$t2, $t2, 1	# s++

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
string:	.asciiz "Hello there!!"