subroutine sub(n)
	integer :: n
	write(*,*) "subroutine", n
end subroutine sub

program main
	call sub(2)
end program main
