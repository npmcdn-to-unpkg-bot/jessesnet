<?php

namespace Proc\Daemon;

use app;
use Service;
use Broker\RabbitClient;

/**
 * RabbitMQ Worker
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */

require __DIR__.'/../../../app/Bootstrap.php';
app\Bootstrap::init();
app\Bootstrap::initGC(); // ensure garbage collection

$Container     = new Service\Container();
$RabbitClient  = $Container->get('rabbit-client');
$RabbitHandler = $Container->get('rabbit-handler');

$AMQChannel = $RabbitClient->getChannel();

// hook to job queue
$AMQChannel->basic_consume(RabbitClient::DEFAULT_QUEUE, '', false, false, false, false, [$RabbitHandler, 'consume']);

echo "Listening to queue: " . RabbitClient::DEFAULT_QUEUE . PHP_EOL . PHP_EOL;

// listen for new jobs being added to the queue
while(count($AMQChannel->callbacks)) {
   $AMQChannel->wait();
}

