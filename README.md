# QuasR.io

## Dependencies :

- Download and install VirtualBox at : https://www.virtualbox.org/wiki/Downloads
- Download QuasR's DevMode virtual machine image at : 
- Import the virtual machine into VirtualBox with :

```
File > Import > Select the .ova file you downloaded.
```

Once imported, an network related error should pop up if you try to start the virtual machine, just select the corresponding interface in the Network Menu.

Once the virtual machine is started, you are good to go. In the VM, access the website at http://localhost/ ! 
You can also access the current site from any other device on your network : 

```
In the top right corner, click of the two arrows, and select "Connection information"
Under IPv4 > IP Address : 192.168.0.**
```

By browsing this IP address from any device (your host device included), you can browse the website. Ex : http://192.168.0.22/


A few information :

```
Local username : quasr
Local password : quasr


The QuasR directory in /home/quasr/ is the current git repo.
``` 
### Make sure to git pull before you start working, as the repo might have changed since the VM was created.

____________________________________

## What has been done so far :

Created the registration/login pages.
Users can register and login.

____________________________________

## Good practices rules :

Use defines in config/defines.php to set what should be used as constant strings in the code, but that could me modified later.
For instance :

```
define("MONGOSERVER", "mongodb://localhost:27017");
define("DBNAME", "QuasR");
define("USERSCOLLECTION", "users");
define("INTERESTSCOLLECTION", "interests");
```

All this variables defining the database's collections will probably change, and so will the connection URL, so every parameter related to the Database should be defined, in order to be able to use constant strings.

### Every time you write a function, index it in docs/doc.html, and explain in a few lines what the function does.

____________________________________

## And to finish - NORM :

```
Classes are in the src/models/ folder,
src/basics.php references every basic functions,
Every file should "require_once 'src/includes.php';",
Every functions file & and functions must start with a ft_,
Every class should start with cl_,
```
### MAKE BEAUTIFUL CODE AND WE SHALL TAKE OVER THE WORLD
