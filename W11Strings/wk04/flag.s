# A program that prints out the Danish flag, stored in the data section

FLAG_ROWS = 6
FLAG_COLS = 12

main:   # Registers: 
        # t0 - row
        # t1 - col 
	# t2 - temporary offset

# (use one register as the row index, one as column index)
	li 	$t0, 0			# row = 0
row_loop_start:
	# branching instructions
	bge	$t0, FLAG_ROWS, row_loop_end
	li 	$t1, 0			# col = 0
col_loop_start:
	# branching instructions
	bge	$t1, FLAG_COLS, col_loop_end
	# print out the flag from memory - calculating the memory offset correctly with the row and column
	# calculate offset
	mul	$t2, $t0, FLAG_COLS	# row * FLAG_COLS + col
	add	$t2, $t2, $t1

	lb	$a0, flag($t2)
	li	$v0, 11
	syscall

	li	$a0, ' '
	li	$v0, 11
	syscall

	add	$t1, $t1, 1
	b	col_loop_start
col_loop_end:
	li	$a0, '\n'
	li	$v0, 11
	syscall

	add	$t0, $t0, 1
	b	row_loop_start
row_loop_end:

	li $v0, 0	# return 0
	jr $ra

    .data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'