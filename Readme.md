## Philosophers 🍝

* One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

* The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

* There are also forks on the table. There are as many forks as philosophers.

* Because serving and eating spaghetti with only one fork is very inconvenient,
a philosopher takes their right and their left forks to eat, one in each hand.

* When a philosopher has finished eating, they put their forks back on the table and start sleeping.
Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

* Every philosopher needs to eat and should never starve.

* Philosophers don’t speak with each other.

* Philosophers don’t know if another philosopher is about to die.

* No need to say that philosophers should avoid dying!

## program
the program receives as a parameter the number of philosophers, the time it can go without eating, the time it will take to eat, the time it will take to sleep, (optional) number of times to eat

all input times and passes in milliseconds

<h3>example</h3>

`./philo 5 300 100 150 (times opcional)`

if the `times` were not passed the program will run until one philosophers die

## ⚙️ Installing
```
$ git clone git@github.com:Wagratom/philosophers.git`
$ cd philo
```

## Makefile
To generate the executable use:

```
make
```

## TESTS
to run all tests use

```
make tests
```

to run individual tests use
```
make test t= path_file/name
```
to run the tests using valgrind use vg before the name

## Examples
```
make test t=struct/creat
make vgtest t=strct/creat

make tests
make vgtests
```

