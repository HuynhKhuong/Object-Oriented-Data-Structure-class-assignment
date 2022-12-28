Question 1

Pair <-
{int *pa, *pb;}

pa, pb points to heap memory locations store integers. 

Requirements:
1 A single constructor Pair(int a, int b): 

- pa and pb: point to newly allocated memory locations on the heap. 
- The integers at those memory locations should be assigned values according to the constructor's integer arguments a and b.

2. A copy constructor Pair(const Pair& other): 
- argument:  a read-only reference to another Pair. 
- It should create a new Pair that is equivalent to the other Pair based on dereferenced values 
does not reuse any of the same memory locations. 

=> the copy constructor should set up its own instance's member variables pa and pb to point to newly allocated memory locations for integers on the heap; 

those memory locations must be new, not the same locations pointed to by the other Pair, but the integers at these new locations should be assigned values according to the integers that the other Pair is pointing to.

A destructor ~Pair() that de-allocates all of the the heap memory that had previously been allocated for this Pair's members.
