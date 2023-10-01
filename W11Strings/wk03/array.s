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
	# this method is broken down into multiple steps of manually calculating 
	# the address, in the printing loop, a shorter way is shown
	la	$t2, numbers			# get address of numbers[0]
	mul	$t1, $t0, 4			# calculate word offset (multiply by the size of the value, in this case, a 4 byte integer)
	add	$t2, $t2, $t1
	sw	$v0, ($t2)

	add 	$t0, $t0, 1			# i++
	b 	loop_read_start
	
loop_read_end:	

	# Modify the middle value, adding 42 to it
	# numbers[2] = numbers[2] + 42
	lw	$t1, numbers+8	# temp = numbers[2]
	add	$t1, $t1, 42	# temp = temp + 42
	sw	$t1, numbers+8	# numbers[2] = temp

	li 	$t0, 0				# i = 0
loop_write_start:

	bge 	$t0, NSIZE, loop_write_end	# if (i >= NSIZE)  (while loop condition)

	# read the stored number and put it into $a0 to print
	#shorthand way
	mul	$t1, $t0, 4	# calc offset
	lw	$a0, numbers($t1)
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
numbers: .word 0:NSIZE
# .space NSIZE * 4