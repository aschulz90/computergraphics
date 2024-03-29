/************************************************************************/
/* This program benchmarks different ways to iterate over arrays and    */
/* contains examples on how to work with variables, pointers and        */
/* references.                                                          */
/* Note: All conceptually multi-dimensional arrays, such as a matrix,   */  
/* should be stored in memory as a one-dimensional array!               */
/* Avoid multi-dimensional arrays in C++!                               */
/************************************************************************/

//Include for in/out streams (std::cout/cin/cerr)
#include <iostream>

//Include for STL vector container
#include <vector>

//As the high-resolution timers in C are platform-specific, we need a switch
//Note these preprocessor macros # are evaluated before compiling!
#ifdef _WIN32
   #include <Windows.h>
   #define ARCH_WINDOWS
#else //Warning: Linux branch was not tested! Sorry for mistakes :)
   #include <sys/time.h>
#endif

//Identify whether the program is compiled in debug-mode or not
#ifdef _DEBUG
#define SIZE 3000 //choose a smaller array size due to slower execution
#else
#define SIZE 6000
#endif

//Iterate in two loops over all elements in the array
//The memory is not processed in a sequential order
//This is highly inefficient!
inline void experiment1(double* field, int x, int y)
{
    for(int i = 0; i < x;++i)
    {
        for(int j = 0; j < y;++j)
        {
            field[i+j*x]=1.0;
        }
    }
}

//The memory is processed sequentially by two loops
inline void experiment2(double* field, int x, int y)
{
    for(int j = 0; j < y;++j)
    {
        for(int i = 0; i < x;++i)
        {
            field[i+j*x]=1.0;
        }
    }
}

//The memory is processed sequentially by a single loop
inline void experiment3(double* field, int x, int y)
{
    int size = x*y;

    for(int i = 0; i < size;++i)
    {
        field[i]=1.0;
    }
}

//The memory is processed backwards sequentially by a single loop
inline void experiment4(double* field, int x, int y)
{
    int size = x*y;

    for(int i = size-1; i;--i)
    {
        field[i]=1.0;
    }
}

void doExperiments(int size)
{
    std::cout<<"Starting memory experiments..."<<std::endl;

    //Allocate memory for the experiments
    double* field = new double[size*size];

#ifdef ARCH_WINDOWS
    LONGLONG frequency, t,t1,t2,t3,t4;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    frequency/= 1000;

    QueryPerformanceCounter((LARGE_INTEGER*)&t);        //Measure the time now
    experiment1(field,size,size);                       //Perform the experiment
    QueryPerformanceCounter((LARGE_INTEGER*)&t1);t1-=t; //Measure time again and store difference to starting time

    QueryPerformanceCounter((LARGE_INTEGER*)&t);
    experiment2(field,size,size);
    QueryPerformanceCounter((LARGE_INTEGER*)&t2);t2-=t;

    QueryPerformanceCounter((LARGE_INTEGER*)&t);
    experiment3(field,size,size);
    QueryPerformanceCounter((LARGE_INTEGER*)&t3);t3-=t;

    QueryPerformanceCounter((LARGE_INTEGER*)&t);
    experiment4(field,size,size);
    QueryPerformanceCounter((LARGE_INTEGER*)&t4);t4-=t;

    std::cout<<"Experiment1 "<<(((double)t1)/((double)frequency))<<" ms"<<std::endl;
    std::cout<<"Experiment2 "<<(((double)t2)/((double)frequency))<<" ms"<<std::endl;
    std::cout<<"Experiment3 "<<(((double)t3)/((double)frequency))<<" ms"<<std::endl;
    std::cout<<"Experiment4 "<<(((double)t4)/((double)frequency))<<" ms"<<std::endl;
#else
    timeval tStart,tEnd;
    double elapsed1,elapsed2,elapsed3,elapsed4;

    gettimeofday(&tStart, NULL);
    experiment1(field,size,size);
    gettimeofday(&tEnd, NULL);
    elapsed1 = (tEnd.tv_sec - tStart.tv_sec) * 1000.0;      // sec to ms
    elapsed1 += (tEnd.tv_usec - tStart.tv_usec) / 1000.0;   // us to ms

    gettimeofday(&tStart, NULL);
    experiment2(field,size,size);
    gettimeofday(&tEnd, NULL);
    elapsed2 = (tEnd.tv_sec - tStart.tv_sec) * 1000.0;      // sec to ms
    elapsed2 += (tEnd.tv_usec - tStart.tv_usec) / 1000.0;   // us to ms

    gettimeofday(&tStart, NULL);
    experiment3(field,size,size);
    gettimeofday(&tEnd, NULL);
    elapsed3 = (tEnd.tv_sec - tStart.tv_sec) * 1000.0;      // sec to ms
    elapsed3 += (tEnd.tv_usec - tStart.tv_usec) / 1000.0;   // us to ms

    gettimeofday(&tStart, NULL);
    experiment4(field,size,size);
    gettimeofday(&tEnd, NULL);
    elapsed4 = (tEnd.tv_sec - tStart.tv_sec) * 1000.0;      // sec to ms
    elapsed4 += (tEnd.tv_usec - tStart.tv_usec) / 1000.0;   // us to ms

    std::cout<<"Experiment1 "<<elapsed1<<" ms"<<std::endl;
    std::cout<<"Experiment2 "<<elapsed2<<" ms"<<std::endl;
    std::cout<<"Experiment3 "<<elapsed3<<" ms"<<std::endl;
    std::cout<<"Experiment4 "<<elapsed4<<" ms"<<std::endl;
#endif

    //Don't forget to delete the experiment's array memory!
    delete[] field;
    std::cout<<"Finished..."<<std::endl;
}

void memoryFun()
{
    //Primitives on stack
    {
        double value0 = 0.0;
        double value1(0.0);
    }//value0 and value1 are removed from the stack according to LIFO principle
    
    //Primitives on heap
    {
        //Create a double on the heap
        double* value0 = new double(0.0);

        //Don't forget to free the memory
        delete value0;

        //The pointer value0 still points to the freed memory, operating on value0 would crash the program:
        //*value0 = 10;
        //by convention you should set the pointer to zero
        value0 = 0;
    }

    //References
    {
        double value0 = 0.0;

        //Get a reference to the value
        double& refValue0 = value0;
        refValue0 = 1.0; //this changes value0 to 1.0
    }

    //Static Arrays
    {
        //A static array on the stack, the length 4 must be known at compile time!
        int a[4] = {0,1,2,3};
        a[0]= 10; //Use the array-opertor [] to assign values to array entries
        a[1]= 20;
        a[2]= 30;
        a[3]= 40;
        //a = {10,20,30,40}
        
    }//the static array a is now destroyed, i.e. removed from the stack -> LIFO

    //Dynamic Arrays
    {
        //Create a dynamic array of size 4 on the heap.
        //In contrast to JAVA, arrays do not have a length() function
        //By inspecting "a", it is impossible to determine its length is 4
        //So remember to keep track of your dynamic array sizes
        int* a = new int[4];
        //a points to the memory address of the first entry in the array

        //The array-operator [] can be used just like on static arrays to access all entries
        a[0]=0;
        a[1]=1;
        a[2]=2;
        a[3]=3; //Set the entries such that a ={0,1,2,3}

        *a = 10; //Sets the value of the first element to 10 by dereferencing the pointer

        *(a+1) = 20; //Do pointer arithmetic and dereferencing to set the second entry to 20

        int* aPtr = a+2; //create a copy of the pointer "a" and add two, thus aPtr points to the third element

        *(aPtr++) = 30; //assign 30 to the third value by dereferencing
                        //and you postfix increment, so that aPtr points to the fourth element afterwards
      
        *aPtr = 40; //dereference and assign value 40 to the fourth element

        //a = {10,20,30,40}
        std::cout<<"Array={"<<a[0]<<","<<a[1]<<","<<a[2]<<","<<a[3]<<"}"<<std::endl;

        delete [] a; //don't forget to free the allocated memory
        //if you didn't call delete[], the memory for a would still remain allocated until the program ends
        //this is in contrast to the JAVA Garbage Collector that frees elements that are not being referenced anywhere
    }
    
    //STL container (recommendated)
    {
      std::vector<int> a; //create a vector that has *int* as element type 
      
      a.reserve(4); //this is not required by reserving memory can speed up
                    //vector filling
      
      a.push_back(0);
      a.push_back(1);
      a.push_back(2);
      a.push_back(3);
      //push values into vector, a.size() is 4 now. Note that the vector
      //grows automatically to account for required memory ammount).
      
      a[2] = 10; //use array indexing
      
      std::cout<<"Array={"<<a[0]<<","<<a[1]<<","<<a[2]<<","<<a[3]<<"}"<<std::endl;
      
      //The memory of a is free *automatically* when a gets destroyed!!
      //No need to keep track of memory like this
    }
}

int main(int argc, char** argv)
{
    memoryFun();

    //This function creates an array of dimensions SIZE*SIZE
    //and times different ways to iterate over all elements
    doExperiments(SIZE);

    int wait;
    std::cin>>wait;

    return 0;
}