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
	# Frame:    [ra, s0-s3]
	# Uses:     [ra, s0-s3, a0, a1, v0]
	# Clobbers: [a0, a1, v0] (act like the function called may clobber others though)
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
	push 	$ra
	push	$s0
	push 	$s1
	push	$s2
	push	$s3
	
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
	jal	sum2
	move	$s1, $v0

	move	$a0, $s0
	move	$a1, $s1
    	# return sum2 (res1, res2);
	jal 	sum2
sum4_return:
	# pop registers off the stack, and use end to move the frame pointer
	pop	$s3
	pop	$s2
	pop 	$s1
	pop	$s0
	pop	$ra
	end

	jr 	$ra