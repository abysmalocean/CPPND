# Writing Larger Programs

## 1. Headers

Header files, or .h files, allow related funciton, method, and class declarations to be collected in one palce. The corresponsing definitions can the be placed in `.cpp` files. The compiler condisers a header declaration a "promise" that the definition will be found later in the code, so if the compiler reaches a function that hasn't been defined yet, it can continue on compliling until the definition is found. This allows funcitons to be defined and declared in arbitrary order. 

<p align = "center">   <img width = "500" src = "images/Lesson4_2020-01-02-16-10-23.png "> </p>

## 2. Using Multiple Files

using the header files and declare the function and implementations separately. So you do not need to too careful about the order in which functions are defined. Using header files is typically the first step in creating a mult-file program. 

## 3. Reference VS. Pointers

Pointer and references can have similar using cases in C++. Pass-by-reference to a function. They both pprovide an alternative way to access an existing variable: pointers through the variable's address, and references through another name for that variable. 

### 3.1 Reference

References must be initialized when they are declared. This means that a reference will always point to data that was intentionally assigned to it. Reference can not be null. This means a reference should point to meaningful data in the program. When used in a function for pass-be-reference, the reference can be used just as a variable of the same type would be. 

### 3.2 Pointer

Pointers can be declared without being initialized, which is dangerous. If this happens mistakely, the pointer could be pointing to an arbitrary address in memory, and the data associated with that address could be meaningless, leading to underfined behavior and difficult to resovle bugs. 

Pointer can be null, nullptr. 

When used in a function for pass-by-reference, a pointer must be dereferenced in order to access the underlying object. 

### 3.3 Summary

References are generally easier and safer than pointers. As a descent rule of thumb, references should be used in place of pointers when possible. 

However, there are times when it is not possible to use references.  One example is object initialization. You might like one object to store a reference to another object. However, if the other object is not yet available when the first object is created, then the first object will need to use a pointer, not a reference, since a reference cannot be null. The reference could only be initialized once the other object is created.
