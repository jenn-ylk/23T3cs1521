# A piece of code that swaps all values of an array around to reverse the array

N_SIZE = 10
N_SIZE_M_1 = N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2

main:	# Registers:
	# t0 - i
	

	li 	$t0, 0				# i = 0;
loop_swap_start:
	bge	$t0, N_SIZE_D_2, loop_swap_end	# while (i < N_SIZE_D_2)

	# get x and y
	mul	$t1, $t0, 4			# x = numbers[i]
	lw	$t2, numbers($t1)	

	sub	$t1, $t0, N_SIZE_M_1		# y = numbers[N_SIZE_M_1 - i]
	mul	$t1, $t1, -4			# multiply by -4 to deal with direction of subtraction
	lw	$t3, numbers($t1)

	# swap their positions (use the calculated offsets!)
	sw	$t2, numbers($t1)		# numbers[N_SIZE_M_1 - i] = x
	mul	$t1, $t0, 4			# x = numbers[i]
	sw	$t3, numbers($t1)

	add	$t0, $t0, 1 			# i++;

	b	loop_swap_start
loop_swap_end:


	# Print out the array, now reversed
	li	$t0, 0
loop_write_start:

	bge 	$t0, N_SIZE, loop_write_end	# if (i >= NSIZE)  (while loop condition)

						# syscall for printf("%d", numbers[i])
	mul	$t1, $t0, 4			# calculate array offset
	lw	$a0, numbers($t1)		# load value from numbers into $a0 (to print)
	li	$v0, 1
	syscall					

	li $a0, '\n'				# printf("%c", '\n')
	li $v0, 11
	syscall

	add $t0, $t0, 1
	b loop_write_start

loop_write_end:


	li $v0, 0	# return 0
	jr $ra

	.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9	# int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};