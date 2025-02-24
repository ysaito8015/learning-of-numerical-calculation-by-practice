program find_epsilon
    implicit none
    real(kind=4) :: feps
    feps = 1.0e0
    do while (feps + 1.0e0 > 1.0e0)
        feps = feps * 0.5e0
    end do
    print *, 'Floating point machine epsilon is:', feps
end program find_epsilon
