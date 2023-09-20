# A translation of a c program that prints a 5 asterisks

# When writing branching code with loops, make sure the start of loop label is 
# _before_ your conditional check
# Often (but not all the time) you will want to invert the condition of the 
# original loop condition, and branch to the end of the loop

# The loop_start label is less necessary in this code, can help for nested loops

main:	# i in $t0, j in $t1
	# li $t0, 1
	# li $t1, 0

loop_start:
	li 	$t0, 0			# i = 0
loop_step:
	bge	$t0, 5, loop_end	# if (i >= 5) goto loop_end;

	li	$a0, '*'		# printf("*\n");
	li	$v0, 11
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

	addi	$t0, $t0, 1		# i++;
	b	loop_step		# goto loop_step;
loop_end:

	li $v0, 0			# return 0
	jr $ra