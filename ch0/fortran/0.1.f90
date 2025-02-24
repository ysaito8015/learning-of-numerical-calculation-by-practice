program main
	call sub(2)
contains
	subroutine sub(n)
		integer :: n
		write(*,*) "substitute", n
	end subroutine sub
end
