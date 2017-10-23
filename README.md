# QuasR.io

## Dependencies :

- Download and install VirtualBox at : https://www.virtualbox.org/wiki/Downloads
- Download QuasR's DevMode virtual machine image at : https://mega.nz/#!pd1SFRwK!0W-nbPj3xvssut5dq5amawuElXUdZrbBGTfHSlR0QKM

SHA-256 Checksum : E1DB1B1C3424847304FC765BFB49E24E61D9C245FF5ABF40BD522CB634C675FF
- Import the virtual machine into VirtualBox with :

```
File > Import > Select the .ova file you downloaded.
```

Once imported, an network related error might pop up if you try to start the virtual machine, do the following to fix :

```
"Change network settings" > Under "Name" select the right adapter, if you are not sure, just click "OK".
```

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
Are running on the VM :
- Apache 2.4
- PHP 7.1
- MongoDB
- MongoDB's php driver
- VirtualBox Additionnals components : might be useful if you want to work with shared folders, in order to edit your files directly from your host, instead of doing it in the VM.
```
### Make sure to git pull before you start working, as the repo might have changed since the VM was created.

____________________________________

## What has been done so far :

Created the registration/login pages.
Users can register and login on the index page.
The CSS and error checking are set for the index page, which includes login / registration errors.
Created the algorit 
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
