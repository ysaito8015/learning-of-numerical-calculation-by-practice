program print_array
	implicit none

	integer :: i, j
	integer, dimension(3,3) :: array = reshape((/1,2,3,4,5,6,7,8,9/),(/3,3/))

	do i=1, 3
	do j=1, 3
		print *, 'i: ', i, 'j: ', j, 'array(i,j): ', array(i,j)
	end do
	end do

end program print_array
