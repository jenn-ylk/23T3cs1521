# A program which takes in a number, and computes the square, 
# or tells the user if the number is too big to fit the square in 32 bits
# registers:
# - x: $t0
# - y: $t1

SQUARE_MAX = 46340

# Week 2 code - this had a few issues originally 
# - when writing MIPS code, be careful to use the correct registers and 
#   instructions, use a debugger to step through instruction by instruction
# 
main:
	# int x, y;

	la 	$a0, prompt			# printf("Enter a number: ");
	li 	$v0, 4	
	syscall
	
	li 	$v0, 5				# scanf("%d", &x);
	syscall
	move 	$t0, $v0 			# x in t0

	# For a solution using ble, see T14Bongo/wk02
	bgt	$t0, SQUARE_MAX, too_big	# if (x > SQUARE_MAX) goto too_big;

	mul 	$t1, $t0, $t0			# y = x * x;

	move 	$a0, $t1
	li 	$v0, 1				# printf("%d", y);
	syscall

	li 	$a0, '\n'			# printf("%c", '\n')
	li 	$v0, 11
	syscall

too_big:
	li 	$v0, 4	
	la 	$a0, too_big_prompt		# printf("Enter a number: ");
	syscall

endif:

	li 	$v0, 0		# return 0
	jr 	$ra

# Data section, contains out prompt string
# having a label (prompt) means that we can call it by name, rather than 
# manually calculating the memory address (could change as we add more code)
	.data
prompt:
	.asciiz "Enter a number: "
too_big_prompt:
	.asciiz "square too big for 32 bits\n"