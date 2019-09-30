/******************************************************************
*                                                                 *
*                        SAS TEST BENCH                           *
*                        ==============                           *
*                                                                 *
*                        Version : 0.1                            *
*                                                                 *
******************************************************************/

This document contains the release notes and usage instructions for 
the third release of SAS Test Bench. 

WHAT IS SAS TEST BENCH?

  The SAS Test Bench (referred to as SAS-TB, hereafter) is a package
  containing a set of tools to facilitate verification and validation 
  of the SASLABSproduct. The system test team will be using the SAS-TB 
  primarily to execute different test scenarios.  This package is also 
  targeted at SASLABS developers who want to run basic functionality tests
  for the modules owned by them. To that end, the test bench enables 
  component owners to run their tests in a system context.

  Version 0.1 of SAS-TB provides support for executing functionality
  test cases involving end-to-end data flows. It also allows users to 
  control and configure SASLABS devices. 

HOW TO BUILD?

  Clone the repository. 
  - git clone https://github.com/organicvillage-usa/SASTB.git
  
  - Change directory to SASTB
    host $ cd ~/SASTB

  - Build the SAS-TB
    host $ make

  - Install SAS-TB into /opt/sastb of target file system
    host $ make install

  If any modifications are made to SASTB source code, please do a 
  'make clean' before doing 'make'. 

  TIP:
  Debug logs are switched off in SAS-TB by default. An option in makefile
  switches on/off the debug logs. If debug logs are required, please 
  change the 'DBG_FLAGS' in Makefile as follows and build SAS-TB again 
  cleanly:

  DBG_FLAGS = -g -D_SAS_DEBUG_
  # DBG_FLAGS = 

  If debug logs are not required, comment the first line and uncomment 
  the second.

USAGE:

  The SAS-TB can be executed in command line mode or script mode. To
  execute in command line mode, just start the SAS-TB from the Linux
  shell.
        
        root@<hostname># ./sastb

  This prints a welcome screen and gives a command prompt for the user
  to type in commands. You can trigger scenarios by typing in the
  appropriate command.

        <SAS-TB> $ 

  TIP:
  The SAS-TB command shell supports most of UNIX command line expansion
  options. 

  To run the SAS-TB in script mode, run the sastb with -s <script file>
  option from the Linux shell. If your script file is linux_commands.txt, 
  then do

        root@<hostname>:/opt/sastb# ./sastb -s linux_commands.txt

  This neither prints a welcome screen nor gives out a command prompt.
  However, relevant logs get printed onto stdout and stderr. The main
  idea behind this mode is to have shell script wrappers or to run the
  command in background.

SCRIPTS:
 - TBD