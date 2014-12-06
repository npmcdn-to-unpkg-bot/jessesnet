<?php

namespace test\Broker;

use Service;

/**
 * RabbitMQ Client Test
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class RabbitClientTest extends \PHPUnit_Framework_TestCase
{
	protected $RabbitClient;

	protected function setUp()
	{
		$DIContainer        = new Service\Container();
		$this->RabbitClient = $DIContainer->get('rabbit-client');
	}

	public function testClient()
	{
		$this->assertInstanceOf('Broker\RabbitClient', $this->RabbitClient);
	}

	/**
     * @depends testClient
     */
	public function testGetConnection()
	{
		$this->assertInstanceOf('PhpAmqpLib\Connection\AMQPConnection', $this->RabbitClient->getConnection());
	}

	/**
     * @depends testClient
     */
	public function testGetChannel()
	{
		$this->assertInstanceOf('PhpAmqpLib\Channel\AMQPChannel', $this->RabbitClient->getChannel());
	}
} 