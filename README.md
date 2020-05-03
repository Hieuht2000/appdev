#appdev for 1-IT-1N1&2

List of Contents
1. Configuration instructions
2. Installation instructions
3. Operating instructions
4. File manifest
5. Copyright and Licensing information
6. Contact information
7. Credits and acknowledgements



1. Configuration instructions
	In this section we should give users information of how to configure
	the operating system, sofware environment, libraries, etc. to run
	this application
	Include 2 steps:
		- Make 2 new folders: "appdev" and "public_html".
		- Download sound files into "appdev". The sound file must be .wav file

2. Installation instructions
	In this section we shold give users information of how to install this application
	what files not included in this package should be added. What command/operation
	should be used to install this application.
	- Download all the files into "appdev" through this link:
	https://github.com/hieuht2000/appdev
	- Move 2 .php files to "public_html"

3. Operating instructions
	In this section we should give users information of how to run this application,
	e.g., What command-line arguments can be given and what do they mean.
	Go to the application file by using command window and type
	"cd appdev";
	- List all  files in this folder by using "ls -l";
	- Compile all the .c files so that they can be excuted by using
	" make ";
	- Run the application by using "./sound";

4. File manifest
	We should list all the files of this application at here with short descriptions.

	List of files:
	README.md		this file
	screen.c		contains screnn manipulation functions
	screen.h		contains constant definitions and functions declerations
					of screen.c
	testscreen.c	this file will be use to test functions in screen.c
	makefile		contains function to compile source code
	comm.c			contains function client-sever communication
	comm.h			contains function decleration in comm.c
	testcurl.c		contain main function to implement curl
	puttysize.php	contain function to send sound file which are analized 
					to PHP program as a HTTP POST

5. Copyright
	This application follows GPLv2 copyright.

