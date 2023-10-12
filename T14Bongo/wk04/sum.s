# A program with functions to sum 4 numbers, and to sum 2 numbers
# week 4 COMP1521 tutorial 
main:

	push	$ra		# since this code is calling a function, push ra

	li 	$a0, 42		# sum3(42, 2, 6, 5)
	li 	$a1, 2
	li	$a2, 6
	li	$a3, 5
	jal	sum4

	move	$a0, $v0
	li 	$v0, 1
	syscall

	li 	$a0, '\n'	# printf("%c", '\n')
	li 	$v0, 11
	syscall

	pop	$ra
	li 	$v0, 0		# return 0
	jr 	$ra

sum2:
	# Args:     a, b (a0, a1)
	#
	# Returns:  sum
	#
	# Frame:    [ra]
	# Uses:     [v0, a0, a1, a3] - a3 only used to mess with caller
	# Clobbers: [v0, a0, a1, a3]
	#
	# Locals:
	#   - 
	#
	# Structure:
	#   sum2
	#   
	#
sum2_prologue:
	# sw    $fp, -4($sp)	# store and move the frame pointer
        # la    $fp, -4($sp)
        # sw    $ra, -8($sp)	# store the return address
        # addi  $sp, $sp, -12	# change stack pointer location to past the stored data
	# set up the stack and frame pointer for the function + push registers
	begin
	push	$ra
sum2_body:
	add	$v0, $a0, $a1
	li	$a3, 42
sum2_return:

        # lw    	$ra, -4($fp)
        # la    	$sp, 4($fp)
        # lw    	$fp, ($fp)
	# retrieve the return address and move stack and frame pointers again
	end
	jr 	$ra



sum4:	
	# Args:     a, b, c, d (a0, a1, a2, a3)
	#
	# Returns:  sum
	#
	# Frame:    [ra, s0, s2, s3]
	# Uses:     [ra, s0, s2, s3]
	# Clobbers: [a0, a1, v0] # act like the function called may clobber others
	#
	# Locals:
	#   - 
	#
	# Structure:
	#   sum2
	#   
	#
sum4_prologue:
	# use begin to move the frame pointer, put all s registers which 
	# will be used inside the function onto the stack, 
	# as well as the return address
	begin
	push	$ra
	
sum4_body:
	# call sum2 to get the sum of the numbers
	# int res1 = sum2(a, b);
	move	$s2, $a2
	move	$s3, $a3
	jal	sum2
	move	$s0, $v0

    	# int res2 = sum2(c, d);
	move	$a0, $s2
	move	$a1, $s3
	jal 	sum2
	move 	$a1, $v0

	move	$a0, $s0
    	# return sum2 (res1, res2);
	jal 	sum2
sum4_return:
	# pop registers off the stack, and use end to move the frame pointer
	pop	$ra
	end

	jr 	$ra



# ecample of how a "cube" might be made in the data section
	.data
# each value in the cube is a single byte
line00:	.space 4
line01:	.space 4
line02:	.space 4
line03:	.space 4
line10:	.space 4
line11:	.space 4
line12:	.space 4
line13:	.space 4
line20:	.space 4
line21:	.space 4
line22:	.space 4
line23:	.space 4
line30:	.space 4
line31:	.space 4
line32:	.space 4
line33:	.space 4

layer0: .word line00, line01, line02, line03
layer1: .word line10, line11, line12, line13
layer2: .word line20, line21, line22, line23
layer3: .word line30, line31, line32, line33

cube:	.word layer0, layer1, layer2, layer3
