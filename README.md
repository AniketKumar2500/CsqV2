# CsqV2
This is the version 2 and the secode most advance version of Csq programming language.


## Features
* Easy Syntax
* Fast Runtime
* Having Libraries which can provide various supports
* Platform independent  (The translator haven't yet created for Windows but if you are in Windows so you could use Csq in Github codespace)

# Specialties
* Support OPPs
* Support dynamic typing by using var and def keyword for functions
* Allows to use C++ in Csq code
# Building
* Install all files via git
* then compile all cpp files
* at last go to Modules/fmt/ compile all headerfiles via g++
# Examples 

## Hello World Program

> print("Hello, World")

## Create an array and print it.

> `array<int> arr = {3,4,3,4}` <br>
  `print(arr)`
  
## Create a function
<li>Creating a function in CsqV2 can we done in two ways that is writing function using lamda in .csq file and other one is to create using a .csqm file.</li>
<li>//In csq file:<br>

> def foo lam(){<br>
  .....<br>
  }
</li>
<li>//In csqm file and importing via import statement from .csq:<br>
//test.csqm
> def foo(){<br>
.....</br>
}

//main.csq

> import test <br>
  foo()

</li>

## Working of import statement
> import pd.dframe


## Importing C headerfile
> #include<stdio.h>
