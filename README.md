## Book Data
書名  :  C & Fortran 演習で学ぶ数値計算
出版社  :  共立出版 (2022/3/19)
発売日  :  2022/3/19
言語  :  日本語
単行本  :  212ページ
ISBN-10  :  4320124847
ISBN-13  :  978-4320124844
寸法  :  18.2 x 1.2 x 25.7 cm

## Page on the publisher
- [C&Fortran 演習で学ぶ数値計算 - 共立出版](https://www.kyoritsu-pub.co.jp/book/b10011784.html)


## Support Page
- [「C & Fortran　演習で学ぶ数値計算」　読者のページ](http://www.abc-lib.org/LearnNum/LearnNum.html)


## Compile C Programs


```shell
$ gcc -Wall -o machine_epsilon_hat ./machine_epsilon_hat.c -lm
$ ./machine_epsilon_hat # float machine epsilon hat = 5.960464e-08
```


## Compile Fortran Programs


```shell
$ gfortran -Wall -o machine_epsilon_hat machine_epsilon_hat.f90
$ ./machine_epsilon_hat #  Floating point machine epsilon is:   5.96046448E-08
```
