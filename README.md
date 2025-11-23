# LBYARCH
## x86-to-C interface programming project

### To setup:
Input the following into a run.bat file:
  nasm -f win64 asmacc.asm
  gcc -c acc.c -o acc.obj -m64
  gcc acc.obj asmacc.obj -o acc.exe -m64
  acc.exe < input.txt
To change which test case to use, replace "input.txt" with any of the files in the "test_cases" folder.
-  input.txt: test case from the specifications
-  input10.txt: test case where y = 10
-  input100.txt: test case where y = 100
-  input1000.txt: test case where y = 1000

### Assigned specifications:
Implement a program that computes for the acceleration of multiple cars stored in a Y by 3 matrix. Where Y is the number of cars. All inputs are in single floating point.
The output acceleration for each will be converted into Integers.
Each row will indicate Initial Velocity (in KM/H), Final Velocity (in KM/H), and Time (in Seconds).
Sample Matrix:
  0.0, 62.5, 10.1
  60.0, 122.3, 5.5
  30.0, 160.7, 7.8
Input: Matrix Rows, single float matrix values
Example:
  3
  0.0, 62.5, 10.1
  60.0, 122.3, 5.5
  30.0, 160.7, 7.8
Output: Integer acceleration values (m/s2)
Example:
  2
  3
  5
