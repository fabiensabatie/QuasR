# QuasR.io

## Dependencies :

The best working method is the following

### - httpd24 (apache2) :

```
On KUBUNTU :
sudo apt-add-repository ppa:ptn107/apache
sudo apt-get install apache2-mpm-worker
```

### - php7.1 :

```
On KUBUNTU :
sudo add-apt-repository ppa:ondrej/php
sudo apt-get update
(optional) sudo apt-get remove php7.0
sudo apt-get install php7.1
```

### - MongoDB : see https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/

### - php-mongodb

```
On KUBUNTU :
sudo apt-get install php-mongodb
```

Clone the project into a directory, and edit your httpd.conf apache file at the following lines :

```
DocumentRoot "/usr/local/var/www/htdocs"
<Directory "/usr/local/var/www/htdocs">
```

Use the URL of your cloned folder.
Save the file and restart the apache server.

With any file editor, find and replace every "set_include_path('/Users/aidenpearce/QuasR/');" by the URL of your folder.
In your browser, access http://localhost/

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

## Every time you write a function, index it in docs/doc.html, and explain in a few lines what the function does.

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
