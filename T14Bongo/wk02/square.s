# A program which takes in a number, and computes the square
# registers:
# - x: $t0
# - y: $t1

SQUARE_MAX = 46340

# Week 2 code - this had a few bugs in it, 
# also now has a check for numbers too large to square
# Bugs found:
# 	- $t1 was used uninitialised where $t0 was meant to be used
#	- Use of add instruction rather than mul for squaring
#	- Use of syscall 12 (read a character) rather than 5 (read a number)
main:
	# int x, y;

	la 	$a0, prompt		# printf("Enter a number: ");
	li 	$v0, 4	
	syscall
	
	li 	$v0, 5			# scanf("%d", &x);
	syscall
	move 	$t0, $v0 		# x in t0

	# check the value in $t0
	# For a solution using bgt (and switched instruction order), see W11Strings/wk02
	ble	$t0, SQUARE_MAX, square	# if (x <= SQUARE_MAX) goto square;
	la 	$a0, toobig_prompt	# printf("");
	li 	$v0, 4	
	syscall
	b	end			# goto end; (skip printing of square)

square:
	mul 	$t1, $t0, $t0		# y = x * x;

	move 	$a0, $t1
	li 	$v0, 1			# printf("%d", y);
	syscall

	li 	$a0, '\n'		# printf("%c", '\n')
	li 	$v0, 11
	syscall

end:
	li 	$v0, 0			# return 0
	jr 	$ra

# Data section, contains our prompt string
# having a label (prompt) means that we can call it by name, rather than 
# manually calculating the memory address (could change as we add more code)
	.data
prompt:
	.asciiz "Enter a number: "
toobig_prompt:
	.asciiz "square too big for 32 bits\n"