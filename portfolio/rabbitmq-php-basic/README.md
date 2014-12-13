jessesnet
=========

### RabbitMQ PHP Basic Queue

Ensure that the RabbitMQ server has been <a>installed</a> and the management UI is accessible.  Verify that the server is running, sudo service rabbitmq-server status.  

The project src is broken into two parts, Broker and Service.  The broker code has the RabbitMQ client and the message handler.  The service code includes the dependency injection container and Scheduler for controlling the worker process which read from the queue.

The worker processes can be manually started either directly in the foreground: app/worker/rabbitworkerd.php, or in batch in the  background: app/bin/proc.php -c start -p 5

To test the queue run: app/queue.php  -j 10000 -p 8, where j signifies how many jobs to insert into the queue and p represents how many processes to monitor the queue.

The RabbitClient is a wrapper class providing access the AMQPConnection and AMQPChannel objects.  I can be accessed via the dependency container, allowing for only one connection at a time. 

The RabbitHandler is the object for handling the messages as they are pulled from the queue, as well as acknowledging when the messages have been successfully consumed.

The workers, app/worker/rabbitworkerd.php, are the scripts that continually run and listen to the queue  When they receive a message they pass invoke the RabbitHandler.

There are some unit tests to help understand class usage.

The config can be overridden if the path or rabbit credentials are different.  Copy the development config and create a local one, config.php