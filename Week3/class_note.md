Copy Constructor.

Copy Constructor is a special constructor which makes a copy of an existing object.

Syntax: 
< Ctor(const & class);>

Example: 

Cube::Cube(const Cube &obj);

Often, copy constructor are invoked automatically by: 
- Passing an object as a parameter to the constructor
- Returning an object from a function
- Initializing an object

Copy assignment operator: 

Operator used to copy an object: **=**
Assignment assigns a value to an existing object

Automatic assignment operator will copy the contents of all member variables

Custom operator (overload)

<ObjectType> & operator<arimethic operator>(const <ObjectType> &obj)

Cube & Cube::operator=(const Cube &obj){
  _length = obj.length;
  return *this;
}

The storage of variable: 
in C++, an instance of a variable can be stored:
- directly in memory 
- accessed by pointer 
- accessed by reference

A reference is an alias to existing memory
A reference doesn't store memory itself, it is only an alias to another variable. 
The alias must be assigned when the variable is intialized. 

Reference variable has no size!

Pass by: 
arguments can be passed to functions in 3 different ways: 
- pass by value
- pass by pointer
- pass by reference

Note that there are 3 ways to return the values from function: 
- return by value
- return by pointer  (1)
- return by reference (2)
(1), (2) are bad examples when the pointer/reference points to stack variable



Modern Range-Based "for-loop"
<for (temp variable declaration: container)>{
  ...
}

note that: to modify the content of each object in the container, use reference
Ex: 
  for (std::int &x : container){
    x += 1;
  }
  
