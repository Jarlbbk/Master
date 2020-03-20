# Master
Code from master thesis
The lopp() for Timer_Func_And_Reed_Switch has a "glitch", the timer will start when I compile (I think), so that it will return total_time 
with how long the compilation takes. This is only the initial return value, after that it returns the correct time

The fall alarm has a somewhat arbitrary threshold for FSR reading. It has been put at 20 simply to have a value to work with. When choosing 0, the sensor might be too sensitive so that 0 is not reached. This threshold needs to be tested and chosen on better terms. A suggestion is to use the logarithmic graph for the FSR to see where it is very sensitive.

The bluetooth class needs to be changed the following way: the constructor and the loop function must have the correct size of the input array (the size will equal the number of values that are sent to the app)
