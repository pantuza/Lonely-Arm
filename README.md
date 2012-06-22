Lonely-Arm
==========

### NAME
> ###### Lonely Arm
    
### DESCRIPTION

        A robot arm implemented in C++ using GLUT, GLU and Open GL. The 
    program is composed by an Arm that moves on a Platform in 3D space
    
        The arm has two modes. Sliding and flying. When on the sliding
    mode its movements are limited by the platform limits and it can rotate 
    its arm, forearm and hand. When on flying mode it can not rotate its 
    parts and the hand changes to a propeller and the arm is free to fly 
    over the 3D space

### COMPILATION

- If you do not wants to compile the program, this repository keeps a 
  binary file compiled with the latest version of the Lonely Arm program.
  So just clone this repository and run it :)

- To compile the program you will need to install the freeglut library 
  that brings the GLU, GLUT and open GL to your operacional system and 
  install g++ compiler and GNU make program:
- **On openSUSE**

```bash
sudo zypper install freeglut freeglut-devel make gcc-c++
```
- **On Ubuntu**

```bash
sudo apt-get install freeglut3 freeglut3-dev make g++
```
- Installed the dependencies, clone this repository
- go to the Lonely-Arm directory and run:
```bash
make run
```
  - It will compile, then run the Lonely Arm program
    that is placed in Lonely-Arm/bin directory

- enjoy the Lonely Arm :)

### USAGE KEYBOARD OPTIONS
- space
> Rotate the camera looking fixed to the arm

- up | down
> Zoom in/out over the arm

- ctrl + left | right | up | down  
> Moves the arm on the platform

- f
> Set the arm to the Flight mode. You can fly usings the arrows 
> left | right | up | down. If 'f' is pressed again it stops the flight
> mode, then the arm starts to fall on the space. If the arm fall, the
> program decrements its life. You can save the arm by setting the 
> flight mode again pressing 'f'

- r
> Resets the arm and the camera to the initial position

- 1 
> Sets the Selected Part to Arm. Press left | right to rotate arm

- 2
> Sets the Selected Part to Forearm. Press left | right to rotate forearm

- 3
> Sets the Selected Part to the Hand. Press left | right to close/open the hand

### AUTHOR
> ###### Written by Gustavo Pantuza

### REPORTING BUGS

> ###### Report dumper bugs to gustavopantuza@gmail.com