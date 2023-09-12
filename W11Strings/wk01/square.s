# A program which takes in a number, and computes the square
# registers:
# - x: $t0
# - y: $t1
main:
	# int x, y;

	la 	$a0, prompt	# printf("Enter a number: ");
	li 	$v0, 4	
	syscall
	
	li 	$v0, 5		# scanf("%d", &x);
	syscall
	move 	$t0, $v0 	# x in t0

	mul 	$t1, $t0, $t0	# y = x * x;

	move 	$a0, $t1
	li 	$v0, 1		# printf("%d", y);
	syscall

	li 	$a0, '\n'	# printf("%c", '\n')
	li 	$v0, 11
	syscall

	li 	$v0, 0		# return 0
	jr 	$ra

# Data section, contains out prompt string
# having a label (prompt) means that we can call it by name, rather than 
# manually calculating the memory address (could change as we add more code)
	.data
prompt:
	.asciiz "Enter a number: "