# PyFromC
Try to run python functions from c program

## key points

We use `Python.h` header file comes with python installation to provide python C Api.

To compile a ccode that uses Python C Api:
> gcc prog.c -I /usr/include/python3.x/ -l python3.x

This tells to gcc to look `/usr/include/python3.x/` dir for header files included in this c code & `python3.x` is the library that has to use for execution of some functions, constants, etc.

## main fundamentals

using python functions, modules whould be done inside:
`Py_Initialize()` and `Py_Finalize()` functions which which executes and stops python interpreter, and may be more things.

    first we need to hold python module we need and import it.

    then get references for required functions inside the imported module.

    after that we can call those functions by giving arguments too.

## important

But now as we saw above we want to use some python modules using Python C Api. But this Api do not know modules we created without telling it right!

Python C Api will look for `PYTHONPATH` variable to get the directories that has python modules. So, simply we have to include our module directory to this variable.

> export PYTHONPATH=$PYTHONPATH:$PWD/path_to_custom_modules_dir

Ofcourse we can set this variable in our `.profile` or `.bashrc`. Otherwise we can set this variable each time we want in our shell.