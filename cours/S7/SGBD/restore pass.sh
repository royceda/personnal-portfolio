sudo /etc/init.d/mysql stop;
sudo /usr/sbin/mysqld --skip-grant-tables --skip-networking &;

mysql -u root;

flush privileges;
set password for root@'localhost'=password('password');
update mysql.user set password=password('newpass') where user='root';

flush privileges;

sudo /etc/init.d/mysql stop;
sudo /etc/init.d/mysql restart;

