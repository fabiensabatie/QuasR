![oh you're not ready](https://cdn.quasr.io/assets/images/github.jpg)
# QuasR.io

QuasR is a software framework that allows developers to build cross-languages services easily. It provides automatic bindings for any library written in C/C++, D, Dart, JavaScript, Java, PHP, Python, Ruby and many more.

## Getting started

Install the QuasR framework using node and npm (see https://nodejs.org) :
```
git clone https://github.com/fabiensabatie/QuasR.git
cd QuasR
npm i && cd Stardust && npm i && cd ..
```

Start the backend with :
```
node qr_index.js repoAuthor repoName
```

Start the front with :
```
cd Stardust && npm start
```

## Roadmap

- Build front for parameter types
- Parser optimisation.
- Encapsulating server and client

## Project structure

```
root
	|_ app_commons - Contains the nodejs application common files (globals / mongo functions / prototypes / credentials)
	|_ controllers - Contains the controllers
		|_ files - File management functions (read / write / etc.)
		|_ programs - Functions gathering / saving the information relative to the programs
	|_ libraries - Contains all QuasR libraries for cross-platform connection to quasr.io services
		|_ clients - Client side libraries
		|_ servers - Server side libraries
		|_ gen-code - Thrift libs for libraries (to be integrated in clients/server on short-term)
	|_ views - Contains front-end views
		|_ layouts - Views layouts
	|_ qr_index.js - Entry point for the QuasR app.
	|_ Stardust - ReactJS Front
		|_ src - Contains all app the sources 
```

## Logic

The following steps describe the process for QuasR usage :
```
- A library is added from the QuasR website
- The library is parsed :
	|_ Typedefs, enums, structs, classes and macros are gathered
- A .thrift file is generated using the parsed data
- Thrift generates the appropriate code for the requested languages
- The client side library is created using the previously generated code : includes thrift functions / QuasR communicating functions
- The server side encapsulating program is generated using the previously built thrift file for each language : includes thrift functions / QuasR communicating functions / library functions
- The server side code is executed and listens for entries.
- The client includes the QuasR library to their program, initialise the connection to the quasr.io gateway, and starts using the distant library functions.
```
