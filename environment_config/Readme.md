# VPS - Environment setup in Debian 9:

## Install thrift

```
sudo apt-get install thrift-compiler
```


## Install apache2

```
sudo apt-get install apache2
sudo a2enmod proxy_http
sudo systemctl restart apache2
```

Copy all files in etc/apache2 inside the /etc/apache2 folder.

## Install mongoDB

```
sudo echo "deb http://repo.mongodb.org/apt/debian stretch/mongodb-org/4.0 main" > /etc/apt/sources.list.d/mongodb-org-4.0.list
sudo apt-get update
sudo apt-get install mongodb-org
git clone https://github.com/fabiensabatie/QuasR.git quasr.io
mkdir quasr.io/data
mkdir quasr.io/data/db
mongod --dbpath quasr.io/data/db
```

In a new terminal window

```
mongo
use admin
db.createUser({ user: "myUserAdmin", pwd: "abc123", roles: [{ role: "userAdminAnyDatabase", db: "admin" }] })
exit
sudo chown -R mongodb:mongodb quasr.io/data
sudo service mongod stop
sudo service mongod start
sudo service mongod status
```

## Install MySQL + phpMyAdmin

```
wget https://dev.mysql.com/get/mysql-apt-config_0.8.10-1_all.deb
sudo dpkg -i mysql-apt-config*
sudo apt-get update
sudo apt-get install mysql-server
mysql_secure_installation
sudo apt install phpmyadmin php-mbstring php-gettext
sudo phpenmod mbstring
sudo systemctl restart apache2
sudo ln -s /etc/phpmyadmin/apache.conf /etc/apache2/conf-available/phpmyadmin.conf
sudo a2enconf phpmyadmin
```

phpMyAdmin is not available at http://your-domain/phpmyadmin
