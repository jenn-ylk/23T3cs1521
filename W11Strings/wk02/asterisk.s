# A translation of a c program that prints a pyramid of asterisks

# When writing branching code with loops, make sure the start of loop label is 
# _before_ your conditional check
# Often (but not all the time) you will want to invert the condition of the 
# original loop condition, and branch to the end of the loop

main:	# i in $t0, j in $t1
	# li $t0, 1
	# li $t1, 0

outerloop_start:
	li	$t0, 1				# i = 1;
outerloop_cond:
	bgt	$t0, 5, outerloop_end		# if (i > 5) goto outerloop_end

innerloop_start:
	li	$t1, 0				# j = 0;
innerloop_cond:
	bge	$t1, $t0, innerloop_end		# if (j >= i) goto innerloop_end

	li	$a0, '*'			# printf("*");
	li	$v0, 11
	syscall

	add	$t1, $t1, 1			# j++
	b	innerloop_cond			# goto innerloop_cond;
innerloop_end:

	li	$a0, '\n'			# printf("\n");
	li	$v0, 11
	syscall

	add	$t0, $t0, 1			# i++;
	b	outerloop_cond			# goto outerloop_cond;
outerloop_end:

	li $v0, 0				# return 0
	jr $ra