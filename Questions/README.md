# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?
	Replacing all '#' methods such as 'using', 'ifdef', etc... then compressing the files into .obj and lastly into .exe (or .lbb)

2. What is the difference between a declaration and a definition?
	Declarations are done inside the .h and are used to tell the functions/class/struct signature (return type, parameters, methods, etc..)
	Definition are done inside .cpp this is were the execution logic is coded.

3. What is the difference between passing a parameter by value, by reference, and by pointer?
	Passing by value create a copy of the passed value
	Passing by reference is passing the exact same variable, modifying one modifies the other
	Passing by pointer means passing the memory address of the variables, to access the value, the pointer must be dereferenced

4. What is the difference between the stack and the heap?
	The stack is contigous and allocated at the start of the program
	The heap isn't contigous and is allocated dynamically during program execution

5. What is the difference between struct and class in C++?
	by default, variables and methods are 'private' in 'class' and 'public' in 'struct'

6. What is the difference between the public, protected, and private access specifiers?
	'public' means that everyone with a reference to the object can access and modify the variables/method
	'protected' means only the object and it's children (heritancy) can access and modify the variables/method
	'private' means only the object itself can access and modify the variables/method

7. What is a pure virtual function? What effect does it have on a class?
	a pure virtual function is one that isn't define in the .cpp (ex: virtual void Toto() = 0;)
	the class containing a pure virtual function becomes 'abstract' and cannot be instanciated as is.

8. Briefly explain the diamond problem in multiple inheritance.
	The diamond problem is when a class inherit multiple time from the same parent class (by inheriting different parent class)
	this means that some variables/methods are duplicated and accessing and modifing those becomes a headack

9. Name the different containers studied in class and describe the strengths and weaknesses of each.
	vector: contigous and dynamic is good for reading but bad for research bad for insertion
	array: continous and static is good for reading but bad for research very bad for insertion
	list: none contigous and dynamic is bad for reading and research but simple to implement good for insertion
	hashmap: none contigous and dynamic are bad for reading but very good for research not very good for insertion
	map: same as hashmap but creates a key value pair, given the value when key is inputed
	queue/stack: same as list but with FIFO and LIFO principle

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.
	array -> number of element known and needs to be easily read
- You need to manage a queue of tasks that must be executed in the order they arrive.
	vector with queue principle -> the size is dynamic and the element needs to be read in order
- You frequently need to insert and remove elements in the middle of a sequence.
	list -> removing and inserting are the strengh of list
- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.
	hashmap -> very good for research ( O(1) ) and the order isn't important
- You need to keep track of actions so that the most recent action can be undone before earlier actions.
	vector with stack principle -> dynamic size and element are read in Last In First Out
- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.
	vector -> dynamic size and good for reading
- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.
	unordered map -> key value pair needed and easy to read ( O(1) )