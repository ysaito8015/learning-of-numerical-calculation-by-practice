module procedures
contains
	subroutine sub(n)
		integer :: n
		write(*,*) "subroutine", n
	end subroutine sub
end module procedures

program main
	use procedures
	call sub(3)
end program main
