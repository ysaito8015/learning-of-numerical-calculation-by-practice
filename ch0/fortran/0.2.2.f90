program main
	implicit none

	! Declare variables
	real :: float1
	real(kind=8) :: float2 ! Assuming kind=8 is double precision
	real :: float3

	! Assign values
	float1 = 1.0
	float2 = 1.0d2 ! 'd' indicates double precision exponent
	float3 = 1.0e2 ! 'e' indicates single precision exponent

	! Print values
	print *, "float1: ", float1 ! float1:    1.00000000
	print *, "float2: ", float2 ! float2:    100.00000000000000
	print *, "float3: ", float3 ! float3:    100.000000
end program main
