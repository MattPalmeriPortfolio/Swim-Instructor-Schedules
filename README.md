# Swim-Instructor-Schedules

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Swim_Instructor_Scheduler.cpp  (program file containing code that determines when a swim instructor is free)
  	schedule.txt   (example text file contailing the schedule of swim instructor)

## Introduction
Book practice project from Problem Solving With C++ Chapter 7. Project 17.
A program that takes in schedules for two swim instructors and outputs the times they are free. Demonstrates ability to read in files and create a functional menu with multiple options in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. prompt user whether to take input from file or default
		1. if from file, get file name and take schedule from that file
		2. else, use default schedule
	2. begin program main menu
		2a. let user edit the schedules as they please
		2b. let user output schedules to screen
		2c. let user output free individual timeslots to screen
		2d. let user output free group session timeslots to screen
		2e. let user save schedule to file
		2f. let user load different schedule from file
		2g. let user exit
	SUBTASKS:
		- Let user edit schedules:
			- have user pick which instructor schedule to edit
			- then pick which timeslot to edit
			- then change it to free or occupied
		- let user output schedules to screen: routine
		- let user output free individual timeslots to screen:
			- iterate through first schedule and output those that are marked free
			- then iterate through second schedule and output those that are marked free
		- let user output free group timeslots to screen:
			-iterate through first and second schedule at same time and output those where both are free
		- let user save schedule to file:
			- take input of filename
			- do output loop for elements of arrays
		- let user load different schedule from file
			- take input of filename
			-do input loop for elements of arrays
		- let user exit: routine

## Requirements
No requirements or modules needed for running this program.
