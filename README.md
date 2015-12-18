#Sieve Theory

##Lizzy White

#Project
This is a project on Sieve Theory.  I have coded the algorithms to the sieves of Eratosthenes and Sundaram, providing visual representations of each.

#Building
For each sieve, navigate to the appropriate folder:

cd Sieve_of_Eratosthenes

Type

make

to compile the program.  Next, run the program and give it some integer n as the limit (for example, running the sieve of Eratosthenes with n=100):

./eratosthenes 100

#Expected Output
I have provided some 'C animation' to better portray the algorithms.  A 2D array will be printed and at each iteration of the algorithm something will change color.  To start, all numbers are the original color.  Once an integer is discovered to be prime, it is colored pink.  Similarly, a composite number is colored blue.  

Note: This looks better if you use the original black terminal screen, rather than white.

For large inputs of n, the animation could lag a bit.  It also may be too slow.  I would recommend for any n > 100 that these lines of code are altered:

Sieve_of_Eratosthenes/Eratosthenes.c: 71 -> usleep(5000);
Sieve_of_Sundaram/Sundaram.c: 66 -> usleep(5000);

At the end of the animation, a list is printed of all the primes less than the given limit.  

