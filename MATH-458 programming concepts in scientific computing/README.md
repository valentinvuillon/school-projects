# Programming concepts in Scientific computing project: ODE solver
## Ismaël Gomes Almada Guillemin
## Valentin Antoine Roger Vuillon

<br/>

### Important information:

On the gitlab repository the option to look at commits per authors does not work well because
we didn't correctly identify ourselves with git at the beginning. So to see all the commits from each authors it is needed to look at all
the commits without filtering them per author.

Note on the commit branches: Our final project is in the branch "generalization". The branches "implicit_methods_development"
and "main" do not contain our final project.


<br/><br/>

### General description of the goal of the program
Our program is an ODE solver. It is able to solve ODEs of the form dy/dt(t)=f(t,y(t)) with y: R->R, f: R²->R, t a real
number. It is also able to solve systems of equations of the type

dy1/dt(t)=f1(t,y1(t),y2(t),y3(t)...)

dy2/dt(t)=f2(t,y1(t),y2(t),y3(t)...)

dy3/dt(t)=f3(t,y1(t),y2(t),y3(t)...)

...

with the yi function R->R, fi: R²->R  functions, t a real number. So the equations can be interdependent.

The case with only one equation dy/dt(t)=f(t,y(t)) is a subcase of the more general system of equations.

### How to complie the project

There is no particular procedure to do. It is only needed to clone the git repository of the project, be on the branch generalization
and build the project with an IDE.


### Description of the use of the executable of the program

The executable is called main.

The user needs to place the executable in a folder and then go in this folder with a terminal. He then needs to run in
the terminal the command ./main.

The user will be asked to give the path of the input text file which will contain all the input data for the program
to run. The file needs to be called input_file.txt. The path is of the form ".../input_file.txt".

A typical input file is as follows:

0

5 10

2

10

30

RungeKutta

4

0.01


### First line of the input file

It is the choice of the function f.

If this parameter is 0 the function will be f(t, y)=5.

If this parameter is 1 the function will be f(t, y)=t.

If this parameter is 2 the function will be f(t, y)=y.

If this parameter is 3 the function will be

f1(t,y1(t),y2(t))=t+y1(t)+y2(t);

f2(t, y1(t), y2(t))=2*t+3*y1(t)+y2(t);

The functions with parameter 0, 1, 2 can only be used with one ODE and not a system of ODEs. The function 3 can only be
used with a system of ODE.

The function with parameter  can only be used in the case of a system of ODEs.

### Second line of the input file

It is the interval of integration of the system of ODEs. The first number is the start of the interval. The second number
the end of the interval. We can write them t1 and t2.

### Third line of the input file

It is the number of equations in the system of ODEs.

### Fourth line of the input file (and the following lines if system of ODEs)

The first line is the initial condition of the function y1 in the system of ODEs. So it is y1(t1).
The second line is the initial condition of the function y2 in the system of ODEs. So it is y2(t2).
And so on

### Line after the initial conditions for the system of ODEs

We specify here the integration method to use. The implemented integration methods are:

Adams Bashforth methods (explicit). Write "AdamsBashforth" in the input file.

Forward Euler method. (explicit) Write "ForwardEuler" in the input file.

Explicit Runge Kutta methods (explicit). Write "RungeKutta" in the input file.

Backward Euler method (implicit). Write "BackwardEuler" in the input file.

Backward Differentiation (implicit). Write "BackwardDifferentiationFormula" in the input file.

Adams Moulton methods (implicit). Write "AdamsMoulton" in the input file.

### Line after the integration method

We specify here the step of the method. Here are the available steps:

Adams Bashforth from 1 to 4.

Explicit Runge Kutta methods from 1 to 4.

Backward Differentiation methods from 1 to 4.

Adams Moulton methods from 1 to 4.

Note that for the Forward and Backward Euler methods the step parameter have no effect on the method.

### Last line

It is the dt used for the integration of the system of ODEs.


Here is an example of the input file if we want to simply solve one ODE (not a system)

0    (function choice)

5 10   (interval)

1   (dimension=1)

10  (initial condition)

RungeKutta

4

0.01


<br/><br/>

Immediately after giving the path of the input file to the executable it will produce a file called "output.txt" in the
folder in which the executable is. The structure of this text file is as follows:

If the user wanted to integrate a single ODE:

The file contains in a first column the time steps of the integration. It contains in a second column the values of the function
y.

If the user wanted to integrate a system of ODEs:

The file contains in a first column the time steps of the integration. It contains in the next column the values of y1 and in
the next column the values of y2 etc...

### Issues and perspectives

One limit of our project is that we hard-coded simple functions to be tested. And the user can only choose among a small
set of these functions. What would be important if we continued to work on this project is to implement a way to let the user
enter its own custom function with a formula parser in the terminal. It would be quite easy to implement this by creating a
new daughter to Reader class. But for this project implementing simples hard coded functions was useful to be able to test
the rest of the code.

The methods Forward Euler, Adams Bashforth , Backward Euler, Adams Moulton, Backward Differentiation are all linear multistep methods.
We realized that we could have factored the code better to implement all these methods. But we realized this to late and decided
to follow the original class hierarchy we had decided: to devise methods in two categories, implicit and explicit.






