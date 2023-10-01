NSIZE = 5

main:	# registers:
	# $t0 - i
	# $t1 - i * 4 (temp, for word alignment)

	# translate array.c into mips here, 
	# which reads in and prints out an array

	li $t0, 0				# i = 0

loop_read_start:
	bge 	$t0, NSIZE, loop_read_end	# if (i >= NSIZE)  (while loop condition)

	li 	$v0, 5				# scan in the next value in the array
	syscall

	# store the scanned number in the array
	mul	$t1, $t0, 4	# calculate offset
	sw	$v0, numbers($t1)

	add 	$t0, $t0, 1			# i++
	b 	loop_read_start
	
loop_read_end:	

	# Modify the middle value, adding 42 to it
	# numbers[3] = numbers[3] + 42
	# breaks into:
	la	$t1, numbers
	lw	$t2, 12($t1)
	add	$t2, $t2, 42
	sw	$t2, 12($t1)

	li 	$t0, 0				# i = 0
loop_write_start:

	bge 	$t0, NSIZE, loop_write_end	# if (i >= NSIZE)  (while loop condition)

	# read the stored number and put it into $a0 to print
	la	$t1, numbers
	mul	$t2, $t0, 4
	add	$t1, $t1, $t2
	lw	$a0, ($t1)
	li	$v0, 1
	syscall					

	li $a0, '\n'				# printf("%c", '\n')
	li $v0, 11
	syscall

	add $t0, $t0, 1
	b loop_write_start

loop_write_end:

	li $v0, 0				# return 0
	jr $ra

	.data
numbers: .space NSIZE * 4