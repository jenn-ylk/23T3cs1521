# A program with a function to recursively determine the maximum value of an array
max:
	# Args:     &array[0], length (a0, a1)
	#
	# Returns:  sum
	#
	# Frame:    [s0, ra]
	# Uses:     [s0, ra, a0, a1, v0]
	# Clobbers: [a0, a1, v0]
	#
	# Locals:
	#   - s0 - first element
	#
	# Structure:
	#   max
	#   [prologue]
	#   [max_body]
	#	base_case
	#	recursive_case
	#   [epilogue]
	#
max_prologue:
        # prologue section before code, 
        # add elements to the stack that need to be used
	begin
	push	$s0
	push	$ra
max_body:
	# load in first value
	lw	$s0, ($a0)
	bne	$a1, 1, recursive
base: 
	# base case
	move	$v0, $s0
	b 	max_epilogue
recursive:
	# recursive case - move array pointer along once
	add	$a0, $a0, 4
	sub	$a1, $a1, 1
	jal	max

	blt	$s0, $v0, max_epilogue
	move	$v0, $s0		# change maximum

max_epilogue:
        # epilogue section - pop elements from the stack
	pop	$ra
	pop	$s0
	end
	jr      $ra

main:

        push    $ra

        la      $a0, array
        li      $a1, 10
        jal     max             # call max(array, 10)

        move    $a0, $v0        # printf ("%d")
        li      $v0, 1
        syscall

        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall

                                
        pop     $ra		# clean up stack frame

        li      $v0, 0          # return 0
        jr      $ra


.data
array:
    .word 1, 2, 9, 4, 5, 6, 4, 3, 2, 1